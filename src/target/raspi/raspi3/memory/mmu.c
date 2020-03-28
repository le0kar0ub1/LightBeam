// #include "target/raspi/raspi3/driver/lfb.h"
// #include "target/raspi/raspi3/memory/mmu.h"
// #include <stdint.h>

// extern u64_t __KEND;

// /* We have 2Mb blocks, so we need 2 of 512 entries  */
// /* Covers 2GB which is enuf for the 1GB + QA7 we need */
// #define NUM_PAGE_TABLE_ENTRIES 512
// /* Each Block is 2Mb in size */
// #define LEVEL1_BLOCKSIZE (1 << 21)

// /* First Level Page Table for 1:1 mapping */
// static mmuval_t __attribute__((aligned(PAGESIZE))) page_table_map1to1[NUM_PAGE_TABLE_ENTRIES] = { 0 };
// /* First Level Page Table for virtual mapping */
// static mmuval_t __attribute__((aligned(PAGESIZE))) page_table_virtualmap[NUM_PAGE_TABLE_ENTRIES] = { 0 };
// /* First Level Page Table for virtual mapping */
// static mmuval_t __attribute__((aligned(PAGESIZE))) Stage2virtual[512] = { 0 };

// typedef union {
//     struct {
//         u64_t EntryType : 2;             // @0-1     1 for a block table, 3 for a page table
            
//             /* These are only valid on BLOCK DESCRIPTOR */
//             u64_t MemAttr : 4;           // @2-5
//             enum {
//                 STAGE2_S2AP_NOREAD_EL0 = 1, //          No read access for EL0
//                 STAGE2_S2AP_NO_WRITE = 2,   //          No write access
//             } S2AP : 2;                     // @6-7
//             enum {
//                 STAGE2_SH_OUTER_SHAREABLE = 2,  //          Outter shareable
//                 STAGE2_SH_INNER_SHAREABLE = 3,  //          Inner shareable
//             } SH : 2;                       // @8-9
//             u64_t AF : 1;                // @10      Accessable flag

//         u64_t _reserved11 : 1;           // @11      Set to 0
//         u64_t Address : 36;              // @12-47   36 Bits of address
//         u64_t _reserved48_51 : 4;        // @48-51   Set to 0
//         u64_t Contiguous : 1;            // @52      Contiguous
//         u64_t _reserved53 : 1;           // @53      Set to 0
//         u64_t XN : 1;                    // @54      No execute if bit set
//         u64_t _reserved55_58 : 4;        // @55-58   Set to 0
        
//         u64_t PXNTable : 1;              // @59      Never allow execution from a lower EL level 
//         u64_t XNTable : 1;               // @60      Never allow translation from a lower EL level
//         enum {
//             APTABLE_NOEFFECT = 0,           // No effect
//             APTABLE_NO_EL0 = 1,             // Access at EL0 not permitted, regardless of permissions in subsequent levels of lookup
//             APTABLE_NO_WRITE = 2,           // Write access not permitted, at any Exception level, regardless of permissions in subsequent levels of lookup
//             APTABLE_NO_WRITE_EL0_READ = 3   // Write access not permitted,at any Exception level, Read access not permitted at EL0.
//         } APTable : 2;                      // @61-62   AP Table control .. see enumerate options
//         u64_t NSTable : 1;               // @63      Secure state, for accesses from Non-secure state this bit is RES0 and is ignored
//     };
//     u64_t Raw64;                         // @0-63    Raw access to all 64 bits via this union
// } VMSAv8_64_DESCRIPTOR;

// /* Level 2 and final ... 1 to 1 mapping */
// /* This will have 1024 entries x 2M so a full range of 2GB */
// static VMSAv8_64_DESCRIPTOR __attribute__((aligned(PAGESIZE))) Stage2map1to1[1024] = { 0 };

// /* Stage3 ... Virtual mapping stage3 (final) ... basic minimum of a single table */
// static __attribute__((aligned(PAGESIZE))) VMSAv8_64_DESCRIPTOR Stage3virtual[512] = { 0 };

// /*-[ MMU_setup_pagetable ]--------------------------------------------------}
// .  Sets up a default TLB table. This needs to be called by only once by one
// .  core on a multicore system. Each core can use the same default table.
// .--------------------------------------------------------------------------*/
// void MMU_setup_pagetable (void)
// {
//     u32_t base;
//     u32_t msg[5] = { 0 };
//     /* Get VC memory sizes */
//     if (mailbox_tag_message(&msg[0], 5, MAILBOX_TAG_GET_VC_MEMORY, 8, 8, 0, 0))
//     {
//         // msg[3] has VC base addr msg[4] = VC memory size
//         msg[3] /= LEVEL1_BLOCKSIZE;                                 // Convert VC4 memory base address to block count
//     }

//     // initialize 1:1 mapping for TTBR0
//     /* The 21-12 entries are because that is only for 4K granual it makes it obvious to change for other granual sizes */

//     /* Ram from 0x0 to VC4 RAM start */
//     for (base = 0; base < msg[3]; base++)
//     {
//         // Each block descriptor (2 MB)
//         Stage2map1to1[base] = (VMSAv8_64_DESCRIPTOR){
//             .Address = (uintptr_t_t)base << (21 - 12),
//             .AF = 1,
//             .SH = STAGE2_SH_INNER_SHAREABLE,
//             .MemAttr = MMU_NORMAL,
//             .EntryType = 1,
//         };
//     }

//     /* VC ram up to 0x3F000000 */
//     for (; base < 512 - 8; base++) {
//         // Each block descriptor (2 MB)
//         Stage2map1to1[base] = (VMSAv8_64_DESCRIPTOR){
//             .Address = (uintptr_t_t)base << (21 - 12),
//             .AF = 1,
//             .MemAttr = MMU_NORMAL_NC,
//             .EntryType = 1,
//         };
//     }

//     /* 16 MB peripherals at 0x3F000000 - 0x40000000*/
//     for (; base < 512; base++) {
//         // Each block descriptor (2 MB)
//         Stage2map1to1[base] = (VMSAv8_64_DESCRIPTOR){
//             .Address = (uintptr_t_t)base << (21 - 12),
//             .AF = 1,
//             .MemAttr = MMU_DEVICE_NGNRNE,
//             .EntryType = 1,
//         };
//     }

//     // 2 MB for mailboxes at 0x40000000
//     // shared device, never execute
//     Stage2map1to1[512] = (VMSAv8_64_DESCRIPTOR){
//         .Address = (uintptr_t_t)512 << (21 - 12),
//         .AF = 1,
//         .MemAttr = MMU_DEVICE_NGNRNE,
//         .EntryType = 1
//     };

//     // Level 1 has just 2 valid entries mapping the each 1GB in stage2 to cover the 2GB
//     page_table_map1to1[0] = (0x8000000000000000) | (uintptr_t_t)&Stage2map1to1[0] | 3;
//     page_table_map1to1[1] = (0x8000000000000000) | (uintptr_t_t)&Stage2map1to1[512] | 3;


//     // Initialize virtual mapping for TTBR1 .. basic 1 page  .. 512 entries x 4K pages
//     // 2MB of ram memory memory  0xFFFFFFFFFFE00000 to 0xFFFFFFFFFFFFFFFF

//     // Stage2 virtual has just 1 valid entry (the last) of the 512 entries pointing to the Stage3 virtual table
//     // Stage 3 starts as all invalid they will be added by mapping call
//     //Stage2virtual[511] = (VMSAv8_64_DESCRIPTOR){ .NSTable = 1,.Address = (uintptr_t_t)& Stage3virtual[0] >> 12,.EntryType = 3 };
//     Stage2virtual[511] = (0x8000000000000000) | (uintptr_t_t)& Stage3virtual[0] | 3;

//     // Stage1 virtual has just 1 valid entry (the last) of 512 entries pointing to the Stage2 virtual table
//     page_table_virtualmap[511] = (0x8000000000000000) | (uintptr_t_t)& Stage2virtual[0] | 3;
// }

// /*-[ MMU_enable ]-----------------------------------------------------------}
// .  Enables the MMU system to the previously created TLB tables.
// .--------------------------------------------------------------------------*/
// void MMU_enable (void)
// {
//     enable_mmu_tables(&page_table_map1to1[0], &page_table_virtualmap[0]);
// }

// mmuval_t virtualmap (u32_t phys_addr, u8_t_t memattrs) {
//     u64_t addr = 0;
//     for (int i = 0; i < 512; i++)
//     {
//         if (Stage3virtual[i].Raw64 == 0) {                          // Find the first vacant stage3 table slot
//             u64_t offset;
//             Stage3virtual[i] = (VMSAv8_64_DESCRIPTOR) { .Address = (uintptr_t_t)phys_addr << (21 - 12), .AF = 1, .MemAttr = memattrs, .EntryType = 3 };
//             __asm volatile ("dmb sy" ::: "memory");
//             offset = ((512 - i) * 4096) - 1;
//             addr = 0xFFFFFFFFFFFFFFFFul;
//             addr = addr - offset;
//             return(addr);
//         }
//     }
//     return (addr);                                                  // error
// }