`/src/target/x86/i386`
=========================

A multicore i386 kernel implementation with a built-in x86 generic bootloader.

As explain, a part of the kernel is contained in other project directories.

## ROADMAP BASE

- [ ] Bootloader
  - [ ] Memory scan
  - [ ] Kernel Load
  - [ ] ... Undefined
- [ ] Boot
  - [ ] Paging
  - [ ] IDT
  - [ ] TSS
  - [ ] SMP init
- [ ] Driver
  - [ ] VGA 
  - [ ] PS/2 Keyboard
  - [ ] PS/2 Mouse
  - [ ] Timer
  - [ ] ...
- [ ] Memory
  - [ ] MMU
- [ ] Multi-tasks system
  - [ ] Physical
    - [X] CPUS exec routines
  - [ ] Virtual
    - [ ] Threads
    - [ ] Basic scheduler