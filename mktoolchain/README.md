`mktoolchain`
=============

This directory is used as dependencies installer.

If you does not have clone recursively this repository you must run `mktoolchain` shell script before build.

Currently handle only the ARM toolchain.

# Install 

_Using make rule:_ `make toolchain`.

_Using mktoolchain directly:_ `./mktoolchain/mktoolchain`.

# ARM

Toolchain pre-configured cloned from github.

# x86

Curently assume that your host machine is x86/x64.

# RISCV

Clone from [here](https://github.com/riscv/riscv-gnu-toolchain) and configure as explained.

By the way, archlinux have a package for the riscv gnu toolchain, lucky we are.
