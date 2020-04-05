#!/bin/sh

BIN=LightBeam-i386.bin

FLAG="$BIN"
#DEV="-usb -device usb-host,hostbus=2,hostaddr=1 -device usb-mouse -device usb-kbd"

if [ "$1" != "no" ]; then
    make fclean
fi

make TARGET=x86/i386

echo ""

if [ "$1" == "debug" ]; then
    qemu-system-i386 $FLAG -d in_asm,int,cpu
    exit 0
fi

qemu-system-i386  $BIN

