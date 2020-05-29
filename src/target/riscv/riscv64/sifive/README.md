`/src/target/riscv/sifive`
==========================

riscv64 implementation for embedded system.

Reference of [riscv64 common](../README.md).

[Official sifive spec](https://sifive.cdn.prismic.io/sifive%2F834354f0-08e6-423c-bf1f-0cb58ef14061_fu540-c000-v1.0.pdf)

## ROADMAP

- [X] S/O the boot
  - [ ] some things to escape from the chaos
  - [ ] fcking hell SMP assembly setup
- [ ] Interrupt
  - [ ] Something like a vector
  - [ ] another ISR
- [ ] Memory
  - [ ] PMM
  - [ ] VMM
  - [ ] Allocator
- [ ] Drivers
  - [ ] GPIO
  - [ ] UART
  - [ ] DMA
  - [ ] SD
  - [ ] ...