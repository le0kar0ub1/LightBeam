#!/bin/sh

make TARGET=raspi3
qemu-aarch64 LightBleam-0.1.0-raspi3.bin -serial stdio -trace -strace -m 256
#qemu-aarch64 LightBleam-0.1.0-raspi3.img -serial stdio
#qemu-system-aarch64 -M raspi3 -kernel LightBleam-0.1.0-raspi3.bin -serial stdio
