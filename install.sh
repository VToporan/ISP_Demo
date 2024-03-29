#!/bin/bash
cd src

cmake -H. -Bbuild
cd build
make all

cd ../
DESKTOP_SHORTCUT=$HOME/Desktop/iLID.desktop

echo "
[Desktop Entry]
Name=iLID
Exec=$(pwd)/build/IspDemo.exe
Icon=$(pwd)/resources/ISP_Demo_Shutter.png
Type=Application
Terminal=false
Encoding=UTF-8
" > $DESKTOP_SHORTCUT
gio set $DESKTOP_SHORTCUT metadata::trusted true
chmod a+x $DESKTOP_SHORTCUT 

