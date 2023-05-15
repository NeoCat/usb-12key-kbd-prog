AUTOMAKE_OPTIONS = foreign
ACLOCAL_AMFLAGS = -I m4 ${ACLOCAL_FLAGS}

bin_PROGRAMS = usb-12key-kbd-prog

usb_12key_kbd_prog_SOURCES = \
	usb-12key-kbd-prog.c \
	scancode.c

# options
# Additional library
usb_12key_kbd_prog_LDADD = \
	@LIBUSB10_LIBS@

# C compiler options
usb_12key_kbd_prog_CFLAGS = \
	-Os -Wall \
	@LIBUSB10_CFLAGS@

# C++ compiler options
usb_12key_kbd_prog_CXXFLAGS = \
	-Os -Wall \
	@LIBUSB10_CFLAGS@

# Linker options
usb_12key_kbd_prog_LDFLAGS = 
