#!/bin/sh

BASE="-cdrom build/LightBeam-i386.iso -serial stdio -enable-kvm"

if [ "$1" != "no" ]; then
    make fclean
fi

make TARGET=x86/i386

echo ""

if [ "$1" == "debug" ]; then
    echo "DEBUG"
    qemu-system-i386 $BASE -d in_asm,int,cpu
    exit 1
fi

qemu-system-i386 $BASE
