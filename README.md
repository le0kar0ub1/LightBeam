# LightBeam

The purpose of this project is to create some kernel base.

LightBeam is a little project without ambition that explore the kernel developpment world.

[Project Root Documentation](doc/tree.md)

<img src="doc/lightbeam.jpg" width="600" height="200">

## INSTALL

LightBeam will check all dependencies and install the ARM GNU toolchain (if not already done).

_Using make rule:_ `make toolchain`

_Using mktoolchain directly:_ `./mktoolchain/mktoolchain`

ARM Kernels are built using GNU ARM toolchain from submodules git.

## BUILD

`make TARGET=$PLATEFORM`

[Targetable PLATEFORM list](src/target/README.md)

You can run at root `make help` to see targetable plateform.


## RUN

For virtual run I advise to use [QEMU](https://www.qemu.org/docs/master/qemu-doc.html) for ARM systems.

Install QEMU from official [github repository](https://github.com/qemu/qemu).

Check dependencies using the `make toolchain`.


## EPILOGUE

And, from the darkness, shine the light.

Feel free to fork, use, improve.
