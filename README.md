# usb-12key-kbd-prog

This command line tool is to program 6/9/12 Bluetooth/USB keyboard:
<a href="https://www.amazon.co.jp/gp/product/B0B6TS4DCV?ie=UTF8&th=1&linkCode=li2&tag=neocat-22&linkId=8935c929955d3e1c599093cf99bff6f8&language=ja_JP&ref_=as_li_ss_il" target="_blank"><img border="0" src="https://ws-fe.amazon-adsystem.com/widgets/q?_encoding=UTF8&ASIN=B0B6TS4DCV&Format=_SL160_&ID=AsinImage&MarketPlace=JP&ServiceVersion=20070822&WS=1&tag=neocat-22&language=ja_JP" >6/9/12 Bluetooth/USB Keyboard with knobs</a>


## Build

- Install libusb-1.0
    - (Mac) brew install libusb
    - (Linux/debian etc.) apt install libusb-1.0-0-dev
    - (Linux/fedora etc.) dnf install libusb1-devel
- make
    - `#include` in .c file maybe modified to `<libusb-1.0/libusb.h>` in Linux

## Usage
```
sudo ./usb-12key-kbd-prog layer_number key_nubmer code [modifiers ...]
```

- layer_number: 1-3
- key_number:   1-12 for keys / 13-18 for knobs
- code:         key name or #<scan_code in decimal
- modifiers:    list of modifier key names


For example, to assign key #5 to <shift + A> on layer 1,
```
sudo ./usb-12key-kbd-prog 1 5 a lshift
```

See scancode.c for key names.
