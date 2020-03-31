`/src/target/raspi/raspi3`
=========================

A multicore Raspberry3 kernel implementation.

As explain, a part of the kernel is contained in other directories of the project. 

## ROADMAP

- [ ] Boot
  - [X] SMP init
  - [X] Interrupt Vectors
  - [ ] IRQ
- [ ] BCM(2835/2836/2837)
  - [X] GPIO Driver
  - [X] Mailbox Driver
  - [X] RPI Frambuffer Driver
  - [X] UART-PL011 Driver
  - [ ] ...
  - [ ] ...
- [ ] Driver
  - [X] UART 
  - [X] FB
  - [ ] Timer
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