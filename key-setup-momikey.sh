#! /bin/sh

echo off
echo "Key Map"
echo "-------------   -------- "
echo "| 7 | 4 | 1 |  |13,14,15|"
echo "-------------   -------- "
echo "| 8 | 5 | 2 |            "
echo "-------------   -------- "
echo "| 9 | 6 | 3 |  |16,17,18|"
echo "-------------   -------- "
echo ""

./usb-12key-kbd-prog 1 1 n
./usb-12key-kbd-prog 1 2 n
./usb-12key-kbd-prog 1 3 c
./usb-12key-kbd-prog 1 4 h
./usb-12key-kbd-prog 1 5 n
./usb-12key-kbd-prog 1 6 n
./usb-12key-kbd-prog 1 7 g
./usb-12key-kbd-prog 1 8 d
./usb-12key-kbd-prog 1 9 a
./usb-12key-kbd-prog 1 13 n
./usb-12key-kbd-prog 1 14 n
./usb-12key-kbd-prog 1 15 n
./usb-12key-kbd-prog 1 16 n
./usb-12key-kbd-prog 1 17 n
./usb-12key-kbd-prog 1 18 n

echo "AGL momikey setting"
echo "-------------   -------- "
echo "| g | h | n |  | n, n, n|"
echo "-------------   -------- "
echo "| d | n | 2 |            "
echo "-------------   -------- "
echo "| a | n | c |  | n, n, n|"
echo "-------------   -------- "
echo "g : agl-flutter-ivi-demo"
echo "d : agl-qt-ivi-demo"
echo "a : agl-momi-ivi-demo"
echo "h : agl-html5-ivi-demo"
echo "c : force reboot guest"
echo ""
