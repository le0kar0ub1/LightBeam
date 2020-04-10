`/src/target/x86/i386`
=========================

A multicore i386 kernel implementation using `grub` so far.

[Built-in x86 bootloader unused at time.](https://github.com/le0kar0ub1/SecondBreath)

As explain, a part of the kernel is contained in other project directories.

## ROADMAP BASE

- [ ] Higher half loaded
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
    - [ ] CPUS exec routines
  - [ ] Virtual
    - [ ] Threads
    - [ ] Basic scheduler