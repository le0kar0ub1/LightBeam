`src/target`
=============

The directory host our plateform which are the target of the root build.

A particular Plateform is generaly preceded by a directory which host all his brothers & sisters.

All plateform-family have a `common` directory for usable sources over platforms.

The array below reference the built plateform and their own documentation.

## Plateform Target

| Plateform               | Description                                                                              |
|-------------------------|------------------------------------------------------------------------------------------|
| `x86/i386`              | [i386 multicore implementation](x86/i386)                                                |
| `x86/x86_64`            | [x86_64 multicore implementation](x86/x86_64)                                            |
| `aarch64/raspi/raspi3`  | [raspberry3 multicore implementation](aarch64/raspi/raspi3)                              |
| `riscv/riscv64/sifive`  | [riscv64 embedded system multicore implementation](riscv/riscv64/sifive)                 |
| `riscv/riscv64/generic` | [riscv64 generic boot implementation](riscv/riscv64/generic)                             |

## In The Scope

| Plateform            | Description                                                          |
|----------------------|----------------------------------------------------------------------|