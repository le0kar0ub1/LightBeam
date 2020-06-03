.code32

.section .multiboot, "awdx"

/*
** THE multiboot header
*/
.balign 4
mb_header:
    .4byte 0xE85250D6                 # magic
    .4byte 0x0                        # architecture 0 (protected mode i386)
    .4byte mb_header_end - mb_header  # mb_header length

    .4byte 0x100000000 - (0xE85250D6 + 0x0 + (mb_header_end - mb_header)) # checksum

    .2byte 0x0  # type
    .2byte 0x0  # flags
    .4byte 0x8  # size
mb_header_end:
