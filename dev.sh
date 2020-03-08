#!/bin/sh

make TARGET=raspi3
if [ "$1" == "" ]; then
    qemu-system-aarch64 -machine raspi3 -kernel LightBleam-raspi3.bin -serial stdio -m 256
    exit 0
fi
qemu-system-aarch64 -machine raspi3 -kernel LightBleam-raspi3.bin -serial stdio -m 256 -d in_asm
