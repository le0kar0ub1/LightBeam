`src/target/aarch64/raspi/raspi3`
=========================

A multicore Raspberry3 kernel implementation.

As explained, a part of the kernel is contained in other project directories.

The Core of the raspi3 is the bcm2837 peripherals.

## ROADMAP

- [ ] Boot
  - [X] SMP init
  - [X] Interrupt Vectors
  - [ ] IRQ
- [ ] [BCM(2835/2836/2837)](https://www.raspberrypi.org/documentation/hardware/raspberrypi/bcm2835/BCM2835-ARM-Peripherals.pdf)
  - [X] GPIO Driver
  - [X] Mailbox Driver
  - [X] RPI Frambuffer Driver
  - [X] UART-PL011 Driver
  - [X] DMA
  - [ ] Interrupts
  - [ ] ...
- [ ] Driver
  - [X] UART
  - [X] FB
  - [X] Timer
  - [ ] DMA
  - [ ] ...
- [ ] Memory
  - [ ] MMU
- [ ] Multi-tasks system
  - [X] Physical
    - [X] CPUS exec routines
  - [ ] Virtual
    - [ ] Threads
    - [ ] Basic scheduler