`src/target/x86/i386`
=========================

A multicore i386 kernel implementation using `grub` so far.

Reference of [x86 common](..).

As explained, a part of the kernel is contained in other project directories.

The build actually assume that your host compiler is x86/x64.

## ROADMAP

- [X] Higher half loaded
- [X] Boot
  - [X] GDT
  - [X] Early Paging
  - [X] IDT
  - [ ] TSS
  - [ ] SMP init
- [ ] Memory
  - [X] VMM