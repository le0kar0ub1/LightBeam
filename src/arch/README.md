`/src/arch`
===========

There are three sources sub-directories (which are the same in `/inc`).

- `/src/arch`
  - `XXX` : directory with files which are architecture specific (generaly particulars tools etc..)
  - `overworld`: is dedicated to sources wich are usable over architectures.
- `/src/kernel`
  : All sub-directories host kernel objects/interfaces shareable.
- `/src/target`
  : specific plateform which are the target of the build

## ROADMAP

At time we have 2 handled architecture linked with our target plateform.

- [ARM]
  - [X] AARCH32
  - [X] AARCH64