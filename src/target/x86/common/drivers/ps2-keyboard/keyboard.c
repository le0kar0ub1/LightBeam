#include "target/x86/x86.h"
#include "target/x86/common/drivers/ps2-keyboard.h"
#include "target/x86/common/interrupts/interrupts.h"
#include "target/x86/common/interrupts/pic.h"
#include "target/x86/common/drivers/vga.h"

static uchar const azerty_keyset[128] =
{
    0,
    [2] = '&',
    [4] = '\"',
    [5] = '\'',
    [6] = '(',
    [7] = '-',
    [9] = '_',
    [12] = ')',
    [13] = '=',
    [16] = 'a',
    [17] = 'z',
    [18] = 'e',
    [19] = 'r',
    [20] = 't',
    [21] = 'y',
    [22] = 'u',
    [23] = 'i',
    [24] = 'o',
    [25] = 'p',
    [30] = 'q',
    [31] = 's',
    [32] = 'd',
    [33] = 'f',
    [34] = 'g',
    [35] = 'h',
    [36] = 'j',
    [37] = 'k',
    [38] = 'l',
    [39] = 'm',
    [44] = 'w',
    [45] = 'x',
    [46] = 'c',
    [47] = 'v',
    [48] = 'b',
    [49] = 'n',
    [28] = '\n',
    [14] = '\b',
    [50] = ',',
    [51] = ';',
    [52] = ':',
    [53] = '!',
    [57] = ' ',
    [27] = '$',
    [43] = '*',
    [26] = '^'
};

static uchar const azerty_keyset_altgr[128] =
{
    0,
    [2] = '&',
    [3] = '~',
    [4] = '#',
    [5] = '{',
    [6] = '[',
    [9] = '\\',
    [11] = '@',
    [12] = ']',
    [13] = '}',
    [16] = 'a',
    [17] = 'z',
    [18] = 'e',
    [19] = 'r',
    [20] = 't',
    [21] = 'y',
    [22] = 'u',
    [23] = 'i',
    [24] = 'o',
    [25] = 'p',
    [30] = 'q',
    [31] = 's',
    [32] = 'd',
    [33] = 'f',
    [34] = 'g',
    [35] = 'h',
    [36] = 'j',
    [37] = 'k',
    [38] = 'l',
    [39] = 'm',
    [44] = 'w',
    [45] = 'x',
    [46] = 'c',
    [47] = 'v',
    [48] = 'b',
    [49] = 'n',
    [28] = '\n',
    [14] = '\b',
    [50] = ',',
    [51] = ';',
    [57] = ' '
};

static uchar const azerty_keyset_capslock[128] =
{
    0,
    [2] = '1',
    [3] = '2',
    [4] = '3',
    [5] = '4',
    [6] = '5',
    [7] = '6',
    [8] = '7',
    [9] = '8',
    [10] = '9',
    [11] = '0',
    [13] = '+',
    [16] = 'A',
    [17] = 'Z',
    [18] = 'E',
    [19] = 'R',
    [20] = 'T',
    [21] = 'Y',
    [22] = 'U',
    [23] = 'I',
    [24] = 'O',
    [25] = 'P',
    [30] = 'Q',
    [31] = 'S',
    [32] = 'D',
    [33] = 'F',
    [34] = 'G',
    [35] = 'H',
    [36] = 'J',
    [37] = 'K',
    [38] = 'L',
    [39] = 'M',
    [44] = 'W',
    [45] = 'X',
    [46] = 'C',
    [47] = 'V',
    [48] = 'B',
    [49] = 'N',
    [28] = '\n',
    [14] = '\b',
    [50] = '?',
    [51] = '.',
    [52] = '/',
    [57] = ' ',
    [40] = '%'
};


static bool caps_lock = false;
static bool caps = false;
static bool ctrl = false;
static bool altgr = false;

void printable_fired(struct intframe *frame, uchar getch)
{
    if (caps_lock != caps)
        frame->eax = azerty_keyset_capslock[getch];
    else if (altgr && !caps_lock && !caps)
        frame->eax = azerty_keyset_altgr[getch];
    else
        frame->eax = azerty_keyset[getch];
    if (frame->eax != 0x0)
        vga_printf("%c", frame->eax);
}

void non_printable_fired(uchar getch)
{
    if (getch == 0x2A || getch == 0x36) // caps on
        caps = true;
    if (getch == 170 || getch == 182) // caps release
        caps = false;
    if (getch == 0x1D) // ctrl on
        ctrl = true;
    if (getch == 157) // ctrl release
        ctrl = false;
    if (getch == 0x3A) // caps_lock is touch
        caps_lock = !caps_lock;
    if (getch == 0xE0) // altgr
        altgr = !altgr;
}

void keyboard_handler(struct intframe *frame)
{
    uchar getch = read_scan_code();

    if (getch < 60 && (azerty_keyset[getch] ||
azerty_keyset_altgr[getch] || azerty_keyset_capslock[getch]))
        printable_fired(frame, getch);
    else
        non_printable_fired(getch);
    pic_eoi(IRQ1);
}