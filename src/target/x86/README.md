`/src/target/x86`
=================

Built-in [x86 bootloader](https://github.com/le0kar0ub1/SecondBreath) unused at time.

This part host all common object for x86 architecture.

Some objects below are also in the target-specific arch and interfaced with.

## ROADMAP

- [ ] Drivers
  - [X] VGA 
  - [ ] PS/2 Keyboard
  - [ ] PS/2 Mouse
  - [ ] Timer
  - [ ] ...
- [ ] Memory
  - [X] PMM
  - [X] VMM
  - [X] Kernel allocator
- [ ] Multi-tasks system
  - [ ] Physical
    - [ ] CPUS exec routines
  - [ ] Virtual
    - [ ] Threads
    - [ ] Basic scheduler