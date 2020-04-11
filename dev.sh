#!/bin/sh

BIN=build/LightBeam-i386.iso

if [ "$1" != "no" ]; then
    make fclean
fi

make TARGET=x86/i386

echo ""

if [ "$1" == "debug" ]; then
    qemu-system-i386 $BIN -d in_asm,int,cpu
    exit 0
fi

qemu-system-i386 -cdrom $BIN

