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

./usb-12key-kbd-prog 1 1 d
./usb-12key-kbd-prog 1 2 b
./usb-12key-kbd-prog 1 3 3
./usb-12key-kbd-prog 1 4 s
./usb-12key-kbd-prog 1 5 a
./usb-12key-kbd-prog 1 6 2
./usb-12key-kbd-prog 1 7 g
./usb-12key-kbd-prog 1 8 h
./usb-12key-kbd-prog 1 9 1
./usb-12key-kbd-prog 1 13 n
./usb-12key-kbd-prog 1 14 c
./usb-12key-kbd-prog 1 15 n
./usb-12key-kbd-prog 1 16 n
./usb-12key-kbd-prog 1 17 n
./usb-12key-kbd-prog 1 18 n

echo "AGL momikey setting"
echo "-------------   -------- "
echo "| g | s | d |  | n, c, n|"
echo "-------------   -------- "
echo "| h | a | b |            "
echo "-------------   -------- "
echo "| 1 | 2 | 3 |  | n, n, n|"
echo "-------------   -------- "
echo "g : AGL Flutter demo IVI CES2024"
echo "s : AGL Flutter demo IVI CES2023"
echo "d : AGL Qt demo IVI"
echo "h : AGL HTML5 demo IVI"
echo "a : AGL Momi demo IVI"
echo "b : AGL Safe Momi demo IVI"
echo "c : force reboot guest"
echo "1: Teltail 1"
echo "2: Teltail 2"
echo "3: Teltail 3"
echo ""
