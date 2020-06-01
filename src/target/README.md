`src/target`
=============

The directory host our plateform which are the target of the root build.

A particular Plateform is generaly preceded by a directory which host all his brother & sister.

All plateform-family have a `common` directory for usable sources over platforms.

The array below reference the built plateform and their own documentation.


## Plateform Target

| Plateform               | Description                                                                              |
|-------------------------|------------------------------------------------------------------------------------------|
| `x86/i386`              | [i386 multicore implementation](x86/i386/README.md)                                      |
| `x86/x86_64`            | [x86_64 multicore implementation](x86/i386/README.md)                                    |
| `arm/raspi/raspi3`      | [raspberry3 multicore implementation](arm/raspi/raspi3/README.md)                        |
| `riscv/riscv64/generic` | [riscv64 generic boot implementation](riscv/riscv64/generic/README.md)                   |
| `riscv/riscv64/sifive`  | [riscv64 embedded system multicore implementation](riscv/riscv64/sifive/README.md)       |


## In The Scope

| Plateform            | Description                                                          |
|----------------------|----------------------------------------------------------------------|