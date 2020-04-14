# LightBeam

The purpose of this project is to create some kernel base for several plateform.

LightBeam is a little project without ambition that explore the OS development world.

[Project Root Documentation](doc/tree.md)

<img src="doc/lightbeam.jpg" width="600" height="200">

## INSTALL

LightBeam will check all dependencies and install the needed GNU toolchain (if not already done).

_Using make rule:_ `make toolchain`

_Using mktoolchain directly:_ `./mktoolchain/mktoolchain`

Kernels are built using GNU toolchain from submodules git.

For x86 build we actually assume that your host machine is of this architecture. An installer for x86 will be provide later.

## BUILD

`make TARGET=$PLATEFORM`

[Targetable PLATEFORM list](src/target/README.md)

You can run at root `make help` to see targetable plateform.


## RUN

For virtual run I advise to use [QEMU](https://www.qemu.org/docs/master/qemu-doc.html) for systems X.

Install QEMU from official [github repository](https://github.com/qemu/qemu).

Check dependencies using the `make toolchain`.


## EPILOGUE

And, from the darkness, shine the light.

Feel free to fork, use, improve.
