#!/bin/sh

make TARGET=raspi1
qemu-system-arm -M raspi2 -kernel LightBleam-0.1.0-raspi2.bin -serial stdio
