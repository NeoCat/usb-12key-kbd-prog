#include <stdio.h>
#include <stdlib.h>
//#include <libusb-1.0/libusb.h>
#include <libusb.h>

#define VENDOR_ID  0x1189
#define PRODUCT_ID 0x8890

extern unsigned char get_modifier_bitmask(const char *name);
extern unsigned char get_scan_code(const char *name);

int main(int argc, char *argv[])
{
	int ret = 0;

	if (argc < 4) {
		fprintf(stderr, "usage: %s layer_number key_nubmer code [modifiers ...]\n", argv[0]);
		fprintf(stderr, "       layer_number: 1-3\n");
		fprintf(stderr, "       key_number:   1-12 for keys / 13-18 for knobs\n");
		fprintf(stderr, "       code:         key name or #<scan_code in decimal number>\n");
		fprintf(stderr, "       modifiers:    list of modifier key names\n");
		return 1;
	}
	int layer = atoi(argv[1]);
	int key = atoi(argv[2]);
	int code = get_scan_code(argv[3]);
	if (code == 0) {
		fprintf(stderr, "invalid key: %s\n", argv[3]);
		return 1;
	}
	int modifiers = 0;
	for (int i = 4; i < argc; i++) {
		int mod = get_modifier_bitmask(argv[i]);
		if (mod == 0) {
			fprintf(stderr, "invalid modifier: %s\n", argv[i]);
			return 1;
		}
		modifiers |= mod;
	}

	printf("keycode=%d modifiers=0x%x\n", code, modifiers);

	libusb_init(NULL);

	libusb_device_handle *handle = libusb_open_device_with_vid_pid(NULL, VENDOR_ID, PRODUCT_ID);
	if (!handle) {
		fprintf(stderr, "failed to open device\n");
		ret = 1;
		goto error;
	}
	unsigned char text[128];
	libusb_get_string_descriptor_ascii(handle, 2, text, sizeof(text));
	printf("opened device \"%s\"\n", text);

	ret = libusb_claim_interface(handle, 1);
	if (ret) {
		fprintf(stderr, "claim interface failed: %s\n", libusb_error_name(ret));
		goto error;
	}

	int xferd = 0;
	unsigned char data[65] = {0x03, 0xa1, layer};
	ret = libusb_interrupt_transfer(handle, 2, data, 65, &xferd, 1000);
	if (ret) {
		fprintf(stderr, "transfer failed: %s\n", libusb_error_name(ret));
		goto error;
	}

	unsigned char data2[65] = {0x03, key, 0x11, 0x01, 0x00, modifiers, 0};
	ret = libusb_interrupt_transfer(handle, 2, data2, 65, &xferd, 1000);
	if (ret) {
		fprintf(stderr, "transfer failed: %s\n", libusb_error_name(ret));
		goto error;
	}

	unsigned char data3[65] = {0x03, key, 0x11, 0x01, 0x01, modifiers, code};
	ret = libusb_interrupt_transfer(handle, 2, data3, 65, &xferd, 1000);
	if (ret) {
		fprintf(stderr, "transfer failed: %s\n", libusb_error_name(ret));
		goto error;
	}

	unsigned char data4[65] = {0x03, 0xaa, 0xaa};
	ret = libusb_interrupt_transfer(handle, 2, data4, 65, &xferd, 1000);
	if (ret) {
		fprintf(stderr, "transfer failed: %s\n", libusb_error_name(ret));
		goto error;
	}

	puts("completed");

error:
	libusb_exit(NULL);
	return ret;
}
