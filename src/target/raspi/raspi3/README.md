`/src/target/raspi/raspi3`
=========================

A multicore Raspberry3 kernel implementation.

As explain, a part of the kernel is contained in other project directories.

The Core of the rapspi3 is the bcm283x peripherals.

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
  - [ ] DMA
  - [ ] Interrupts
  - [ ] ...
- [ ] Driver
  - [X] UART 
  - [X] FB
  - [ ] Timer
  - [ ] DMA
  - [ ] ...
- [ ] Memory
  - [ ] MMU
- [ ] Multi-tasks system
  - [ ] Physical
    - [X] CPUS exec routines
    - [ ] CPUS particular task assignement (relevant?)
  - [ ] Virtual
    - [ ] Threads
    - [ ] Basic scheduler