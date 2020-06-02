`/src/target/riscv/riscv64/sifive`
=================================

riscv64 implementation for embedded system.

Reference of [riscv common](../../README.md).

[Official sifive spec](https://sifive.cdn.prismic.io/sifive%2F834354f0-08e6-423c-bf1f-0cb58ef14061_fu540-c000-v1.0.pdf)

There are no multi-level bootloading in our implementation.

The code start at `0x80000000` and we don't use the two previous stages.

Sifive havn't any integrated graphical interface, then we are using the UART.

## ROADMAP

- [X] S/O the boot
  - [X] some things to escape from the chaos
  - [X] SMP init
- [ ] Interrupts
  - [X] Interrupt vector
  - [ ] ISR
- [ ] Drivers Early
  - [ ] GPIO
  - [X] UART
- [ ] Memory
  - [ ] PMM
  - [ ] VMM
  - [ ] Allocator
- [ ] Drivers middle
  - [ ] DMA
  - [ ] SD
  - [ ] ...