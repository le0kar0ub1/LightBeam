#ifndef _ASM_RISCV_CSR_H
#define _ASM_RISCV_CSR_H

/* Status register flags */
#define SR_SIE  0x00000002 /* Supervisor Interrupt Enable */
#define SR_SPIE 0x00000020 /* Previous Supervisor IE */
#define SR_SPP  0x00000100 /* Previously Supervisor */
#define SR_SUM  0x00040000 /* Supervisor may access User Memory */

#define SR_FS           0x00006000 /* Floating-point Status */
#define SR_FS_OFF       0x00000000
#define SR_FS_INITIAL   0x00002000
#define SR_FS_CLEAN     0x00004000
#define SR_FS_DIRTY     0x00006000

#define SR_XS           0x00018000 /* Extension Status */
#define SR_XS_OFF       0x00000000
#define SR_XS_INITIAL   0x00008000
#define SR_XS_CLEAN     0x00010000
#define SR_XS_DIRTY     0x00018000

#define SR_SD   0x80000000 /* FS/XS dirty */

/* SATP flags */
#define SATP_PPN     0x00000FFFFFFFFFFF
#define SATP_MODE_39 0x8000000000000000
#define SATP_MODE    SATP_MODE_39

/* Interrupt Enable and Interrupt Pending flags */
#define SIE_SSIE 0x00000002 /* Software Interrupt Enable */
#define SIE_STIE 0x00000020 /* Timer Interrupt Enable */
#define SIE_SEIE 0x00000200 /* External Interrupt Enable */

#define EXC_INST_MISALIGNED     0
#define EXC_INST_ACCESS         1
#define EXC_BREAKPOINT          3
#define EXC_LOAD_ACCESS         5
#define EXC_STORE_ACCESS        7
#define EXC_SYSCALL             8
#define EXC_INST_PAGE_FAULT     12
#define EXC_LOAD_PAGE_FAULT     13
#define EXC_STORE_PAGE_FAULT    15

#define csr_swap(csr, val)                  \
({                              \
    unsigned long __v = (unsigned long)(val);       \
    __asm__ __volatile__ ("csrrw %0, " #csr ", %1"      \
                  : "=r" (__v) : "rK" (__v)     \
                  : "memory");          \
    __v;                            \
})

#define csr_read(csr)                       \
({                              \
    register unsigned long __v;             \
    __asm__ __volatile__ ("csrr %0, " #csr          \
                  : "=r" (__v) :            \
                  : "memory");          \
    __v;                            \
})

#define csr_write(csr, val)                 \
({                              \
    unsigned long __v = (unsigned long)(val);       \
    __asm__ __volatile__ ("csrw " #csr ", %0"       \
                  : : "rK" (__v)            \
                  : "memory");          \
})

#define csr_read_set(csr, val)                  \
({                              \
    unsigned long __v = (unsigned long)(val);       \
    __asm__ __volatile__ ("csrrs %0, " #csr ", %1"      \
                  : "=r" (__v) : "rK" (__v)     \
                  : "memory");          \
    __v;                            \
})

#define csr_set(csr, val)                   \
({                              \
    unsigned long __v = (unsigned long)(val);       \
    __asm__ __volatile__ ("csrs " #csr ", %0"       \
                  : : "rK" (__v)            \
                  : "memory");          \
})

#define csr_read_clear(csr, val)                \
({                              \
    unsigned long __v = (unsigned long)(val);       \
    __asm__ __volatile__ ("csrrc %0, " #csr ", %1"      \
                  : "=r" (__v) : "rK" (__v)     \
                  : "memory");          \
    __v;                            \
})

#define csr_clear(csr, val)                 \
({                              \
    unsigned long __v = (unsigned long)(val);       \
    __asm__ __volatile__ ("csrc " #csr ", %0"       \
                  : : "rK" (__v)            \
                  : "memory");          \
})

#endif
