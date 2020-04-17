`/src/target/x86/i386`
=========================

A multicore i386 kernel implementation using `grub` so far.

Built-in [x86 bootloader](https://github.com/le0kar0ub1/SecondBreath) unused at time.

As explain, a part of the kernel is contained in other project directories.

The build actually assume that your host compiler is x86/x64.

## ROADMAP

- [X] Higher half loaded
- [X] Boot
  - [X] GDT
  - [X] Early Paging
  - [X] IDT
  - [ ] TSS
  - [ ] SMP init
- [ ] Driver
  - [X] VGA 
  - [ ] PS/2 Keyboard
  - [ ] PS/2 Mouse
  - [ ] Timer
  - [ ] ...
- [ ] Memory
  - [ ] MMU
  - [X] PMM
  - [ ] VMM
- [ ] Multi-tasks system
  - [ ] Physical
    - [ ] CPUS exec routines
  - [ ] Virtual
    - [ ] Threads
    - [ ] Basic scheduler