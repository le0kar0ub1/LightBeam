#!/bin/sh

FLAG="-machine raspi3 -kernel LightBeam-raspi3.img -serial stdio -show-cursor"
DEV="-usb -device usb-host,hostbus=2,hostaddr=1 -device usb-mouse -device usb-kbd"

if [ "$1" != "no" ]; then
    make fclean
fi

make TARGET=raspi3

echo ""

if [ "$1" == "debug" ]; then
    qemu-system-aarch64 $FLAG -d in_asm,int,cpu
    exit 0
fi

qemu-system-aarch64 $FLAG

