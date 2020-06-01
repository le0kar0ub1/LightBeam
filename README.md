# LightBeam

The purpose of this project is to create some kernel base for several plateforms.

LightBeam is a project without ambition that explore the OS development world.

[A documentation is provided](doc/tree.md).

<img src="doc/lightbeam.jpg" width="600" height="200">

## INSTALL

LightBeam will check all dependencies and install the needed GNU toolchain (if not already done).

_Using make rule:_ `make toolchain`

_Using mktoolchain directly:_ `./mktoolchain/mktoolchain`

Kernels are built using GNU toolchain from submodules git.

For x86 the build actually assume that your host machine is of this architecture. An installer will be provided later.

## BUILD

`make TARGET=$PLATEFORM`

The targetable PLATEFORM list is provided [here](src/target/README.md).

You can also run `make help` at root to see targetable plateform.


## RUN

For virtual run I advise to use [QEMU](https://www.qemu.org/docs/master/qemu-doc.html) for system X.

Install QEMU from official [github repository](https://github.com/qemu/qemu).

A configured run is provided for each plateform.

`make run TARGET=$PLATEFORM`

Check dependencies using the `make toolchain`.


## EPILOGUE

A light beam in the dark.

Feel free to fork, use, improve.
