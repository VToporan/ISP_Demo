#!/bin/bash

if [ "$EUID" -ne 0 ]
  then echo "Please run as root"
  exit
fi

apt-get install cmake
apt-get install qt5-default
apt-get install libopencv-dev
