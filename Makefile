hid-12key-kbd-prog: usb-12key-kbd-prog.c scancode.c
	gcc -Os -ousb-12key-kbd-prog -Wall `pkg-config --cflags --libs libusb-1.0` $^
