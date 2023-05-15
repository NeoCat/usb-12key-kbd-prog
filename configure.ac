# autoconf for usb-12key-kbd-prog

AC_PREREQ([2.69])

AC_INIT([usb-12key-kbd-prog], [1.0])

AM_INIT_AUTOMAKE([foreign])

AC_CONFIG_SRCDIR([usb-12key-kbd-prog.c])
AC_CONFIG_HEADERS([config.h])

AC_CONFIG_MACRO_DIR([m4])

# Checks for programs.
AC_PROG_CC
AC_PROG_CXX
AC_PROG_INSTALL

AC_DISABLE_STATIC

# Checks for libraries.
LT_INIT
#AM_PROG_LIBTOOL 

PKG_PROG_PKG_CONFIG
PKG_CHECK_MODULES([LIBUSB10], [libusb-1.0])

AC_CONFIG_FILES([Makefile])
AC_OUTPUT

