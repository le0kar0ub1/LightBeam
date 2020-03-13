# LightBleam

The purpose of this project is to create some ARM kernel base for micro-systems as [RaspberryPi](https://fr.wikipedia.org/wiki/Raspberry_Pi).

LightBleam is a little project without ambition that explore the ARM kernel developpment world.

A fast documentation will be provide later.

## INSTALL

LightBleam will check all dependencies and install the ARM GNU toolchain (if not already done).

_Using make rule:_ `make toolchain`

_Using mktoolchain directly:_ `./mktoolchain/mktoolchain`

Kernels are built using GNU ARM toolchain from submodules git.

## BUILD

LightBleam build kernel system-specific.

`make TARGET=$PLATEFORM`

*PLATEFORM targetable list*:
  - raspi3 (RaspberryPi3)

for now, the only non dirty target kernel is `raspi3`.

## RUN

For virtual run I advise to use [QEMU](https://www.qemu.org/docs/master/qemu-doc.html) for ARM systems.

For physical run check this [page](https://wiki.osdev.org/Raspberry_Pi_Bare_Bones#Testing_your_operating_system_.28Real_Hardware.29).

Check dependencies using the `make toolchain`.

## ROADMAP

- [X] Scalable Build & Dependencies installer
- [ ] RaspberryPi3
  - [ ] Boot
    - [X] SMP init
    - [X] Interrupt Vectors
    - [ ] IRQ
  - [ ] Driver
    - [X] UART 
    - [X] LFB
  - [ ] Memory
    - [ ] MMU
    - [ ] Allocator


## EPILOGUE

[ARM ABI specification](http://infocenter.arm.com/help/index.jsp?topic=/com.arm.doc.ihi0042f/index.html).

[ARM official developper documentation](https://developer.arm.com/docs).

And, from the darkness, shine the light.

Feel free to fork, use, improve.
