#ifndef __DATASTRUCTURE__
#define __DATASTRUCTURE__

#include "kernel/def/typedef.h"

typedef enum {
	Clkdiv1 = 0b00,										// 0
	Clkdiv16 = 0b01,									// 1
	Clkdiv256 = 0b10,									// 2
	Clkdiv_undefined = 0b11,							// 3 
} TIMER_PRESCALE;

struct __attribute__((__packed__, aligned(4))) GPIORegisters
{
	u32_t GPFSEL[6];									// 0x00  GPFSEL0 - GPFSEL5
	u32_t reserved1;									// 0x18  reserved
	u32_t GPSET[2];									// 0x1C  GPSET0 - GPSET1;
	u32_t reserved2;									// 0x24  reserved
	u32_t GPCLR[2];									// 0x28  GPCLR0 - GPCLR1
	u32_t reserved3;									// 0x30  reserved
	const u32_t GPLEV[2];								// 0x34  GPLEV0 - GPLEV1   ** Read only hence const
	u32_t reserved4;									// 0x3C  reserved
	u32_t GPEDS[2];									// 0x40  GPEDS0 - GPEDS1 
	u32_t reserved5;									// 0x48  reserved
	u32_t GPREN[2];									// 0x4C  GPREN0 - GPREN1;	 
	u32_t reserved6;									// 0x54  reserved
	u32_t GPFEN[2];									// 0x58  GPFEN0 - GPFEN1;
	u32_t reserved7;									// 0x60  reserved
	u32_t GPHEN[2];									// 0x64  GPHEN0 - GPHEN1;
	u32_t reserved8;									// 0x6c  reserved
	u32_t GPLEN[2];									// 0x70  GPLEN0 - GPLEN1;
	u32_t reserved9;									// 0x78  reserved
	u32_t GPAREN[2];									// 0x7C  GPAREN0 - GPAREN1;
	u32_t reserved10;									// 0x84  reserved
	u32_t GPAFEN[2]; 									// 0x88  GPAFEN0 - GPAFEN1;
	u32_t reserved11;									// 0x90  reserved
	u32_t GPPUD; 										// 0x94  GPPUD 
	u32_t GPPUDCLK[2]; 								// 0x98  GPPUDCLK0 - GPPUDCLK1;
};

/*--------------------------------------------------------------------------}
{  RASPBERRY PI SYSTEM TIMER HARDWARE REGISTERS - BCM2835 Manual Section 12	}
{--------------------------------------------------------------------------*/
struct __attribute__((__packed__, aligned(4))) SystemTimerRegisters
{
	u32_t ControlStatus;								// 0x00
	u32_t TimerLo;										// 0x04
	u32_t TimerHi;										// 0x08
	u32_t Compare0;									// 0x0C
	u32_t Compare1;									// 0x10
	u32_t Compare2;									// 0x14
	u32_t Compare3;									// 0x18
};

/*--------------------------------------------------------------------------}
{	   TIMER_CONTROL REGISTER BCM2835 ARM Peripheral manual page 197		}
{--------------------------------------------------------------------------*/
typedef union  
{
	struct 
	{
		unsigned unused : 1;							// @0 Unused bit
		unsigned Counter32Bit : 1;						// @1 Counter32 bit (16bit if false)
		TIMER_PRESCALE Prescale : 2;					// @2-3 Prescale  
		unsigned unused1 : 1;							// @4 Unused bit
		unsigned TimerIrqEnable : 1;					// @5 Timer irq enable
		unsigned unused2 : 1;							// @6 Unused bit
		unsigned TimerEnable : 1;						// @7 Timer enable
		unsigned reserved : 24;							// @8-31 reserved
	};
	u32_t Raw32;										// Union to access all 32 bits as a u32_t
} time_ctrl_reg_t;


/*--------------------------------------------------------------------------}
{   RASPBERRY PI ARM TIMER HARDWARE REGISTERS - BCM2835 Manual Section 14	}
{--------------------------------------------------------------------------*/
struct __attribute__((__packed__, aligned(4))) ArmTimerRegisters
{
	u32_t Load;												// 0x00
	const u32_t Value;											// 0x04  ** Read only hence const
	time_ctrl_reg_t Control;									// 0x08
	u32_t Clear;												// 0x0C
	const u32_t RawIRQ;										// 0x10  ** Read only hence const
	const u32_t MaskedIRQ;										// 0x14  ** Read only hence const
	u32_t Reload;												// 0x18
};

/*--------------------------------------------------------------------------}
{   IRQ BASIC PENDING REGISTER - BCM2835.PDF Manual Section 7 page 113/114  }
{--------------------------------------------------------------------------*/
typedef union
{
	struct __attribute__((__packed__, aligned(4)))
	{
		const unsigned Timer_IRQ_pending : 1;						// @0 Timer Irq pending  ** Read only
		const unsigned Mailbox_IRQ_pending : 1;						// @1 Mailbox Irq pending  ** Read only
		const unsigned Doorbell0_IRQ_pending : 1;					// @2 Arm Doorbell0 Irq pending  ** Read only
		const unsigned Doorbell1_IRQ_pending : 1;					// @3 Arm Doorbell0 Irq pending  ** Read only
		const unsigned GPU0_halted_IRQ_pending : 1;					// @4 GPU0 halted IRQ pending  ** Read only
		const unsigned GPU1_halted_IRQ_pending : 1;					// @5 GPU1 halted IRQ pending  ** Read only
		const unsigned Illegal_access_type1_pending : 1;			// @6 Illegal access type 1 IRQ pending  ** Read only
		const unsigned Illegal_access_type0_pending : 1;			// @7 Illegal access type 0 IRQ pending  ** Read only
		const unsigned Bits_set_in_pending_register_1 : 1;			// @8 One or more bits set in pending register 1  ** Read only
		const unsigned Bits_set_in_pending_register_2 : 1;			// @9 One or more bits set in pending register 2  ** Read only
		const unsigned GPU_IRQ_7_pending : 1;						// @10 GPU irq 7 pending  ** Read only
		const unsigned GPU_IRQ_9_pending : 1;						// @11 GPU irq 9 pending  ** Read only
		const unsigned GPU_IRQ_10_pending : 1;						// @12 GPU irq 10 pending  ** Read only
		const unsigned GPU_IRQ_18_pending : 1;						// @13 GPU irq 18 pending  ** Read only
		const unsigned GPU_IRQ_19_pending : 1;						// @14 GPU irq 19 pending  ** Read only
		const unsigned GPU_IRQ_53_pending : 1;						// @15 GPU irq 53 pending  ** Read only
		const unsigned GPU_IRQ_54_pending : 1;						// @16 GPU irq 54 pending  ** Read only
		const unsigned GPU_IRQ_55_pending : 1;						// @17 GPU irq 55 pending  ** Read only
		const unsigned GPU_IRQ_56_pending : 1;						// @18 GPU irq 56 pending  ** Read only
		const unsigned GPU_IRQ_57_pending : 1;						// @19 GPU irq 57 pending  ** Read only
		const unsigned GPU_IRQ_62_pending : 1;						// @20 GPU irq 62 pending  ** Read only
		unsigned reserved : 10;										// @21-31 reserved
	};
	const u32_t Raw32;											// Union to access all 32 bits as a u32_t  ** Read only
} irq_basic_pending_reg_t;

/*--------------------------------------------------------------------------}
{	   FIQ CONTROL REGISTER BCM2835.PDF ARM Peripheral manual page 116		}
{--------------------------------------------------------------------------*/
typedef union
{
	struct __attribute__((__packed__, aligned(4)))
	{
		unsigned SelectFIQSource : 7;								// @0-6 Select FIQ source
		unsigned EnableFIQ : 1;										// @7 enable FIQ
		unsigned reserved : 24;										// @8-31 reserved
	};
	u32_t Raw32;													// Union to access all 32 bits as a u32_t
} fiq_control_reg_t;

/*--------------------------------------------------------------------------}
{	 ENABLE BASIC IRQ REGISTER BCM2835 ARM Peripheral manual page 117		}
{--------------------------------------------------------------------------*/
typedef union
{
	struct __attribute__((__packed__, aligned(4)))
	{
		unsigned Enable_Timer_IRQ : 1;								// @0 Timer Irq enable
		unsigned Enable_Mailbox_IRQ : 1;							// @1 Mailbox Irq enable
		unsigned Enable_Doorbell0_IRQ : 1;							// @2 Arm Doorbell0 Irq enable
		unsigned Enable_Doorbell1_IRQ : 1;							// @3 Arm Doorbell0 Irq enable
		unsigned Enable_GPU0_halted_IRQ : 1;						// @4 GPU0 halted IRQ enable
		unsigned Enable_GPU1_halted_IRQ : 1;						// @5 GPU1 halted IRQ enable
		unsigned Enable_Illegal_access_type1 : 1;					// @6 Illegal access type 1 IRQ enable
		unsigned Enable_Illegal_access_type0 : 1;					// @7 Illegal access type 0 IRQ enable
		unsigned reserved : 24;										// @8-31 reserved
	};
	u32_t Raw32;													// Union to access all 32 bits as a u32_t
} irq_enable_basic_reg_t;

/*--------------------------------------------------------------------------}
{	DISABLE BASIC IRQ REGISTER BCM2835 ARM Peripheral manual page 117		}
{--------------------------------------------------------------------------*/
typedef union
{
	struct __attribute__((__packed__, aligned(4)))
	{
		unsigned Disable_Timer_IRQ : 1;								// @0 Timer Irq disable
		unsigned Disable_Mailbox_IRQ : 1;							// @1 Mailbox Irq disable
		unsigned Disable_Doorbell0_IRQ : 1;							// @2 Arm Doorbell0 Irq disable
		unsigned Disable_Doorbell1_IRQ : 1;							// @3 Arm Doorbell0 Irq disable
		unsigned Disable_GPU0_halted_IRQ : 1;						// @4 GPU0 halted IRQ disable
		unsigned Disable_GPU1_halted_IRQ : 1;						// @5 GPU1 halted IRQ disable
		unsigned Disable_Illegal_access_type1 : 1;					// @6 Illegal access type 1 IRQ disable
		unsigned Disable_Illegal_access_type0 : 1;					// @7 Illegal access type 0 IRQ disable
		unsigned reserved : 24;										// @8-31 reserved
	};
	u32_t Raw32;													// Union to access all 32 bits as a u32_t
} irq_disable_basic_reg_t;

/*--------------------------------------------------------------------------}
{	   RASPBERRY PI IRQ HARDWARE REGISTERS - BCM2835 Manual Section 7	    }
{--------------------------------------------------------------------------*/
struct __attribute__((__packed__, aligned(4))) IrqControlRegisters
{
	const irq_basic_pending_reg_t IRQBasicPending;				// 0x200   ** Read only hence const
	u32_t IRQPending1;											// 0x204
	u32_t IRQPending2;											// 0x208
	fiq_control_reg_t FIQControl;								// 0x20C
	u32_t EnableIRQs1;											// 0x210
	u32_t EnableIRQs2;											// 0x214
	irq_enable_basic_reg_t EnableBasicIRQs;						// 0x218
	u32_t DisableIRQs1;										// 0x21C
	u32_t DisableIRQs2;										// 0x220
	irq_disable_basic_reg_t DisableBasicIRQs;					// 0x224
};

/*--------------------------------------------------------------------------}
;{               RASPBERRY PI MAILBOX HARRDWARE REGISTERS					}
;{-------------------------------------------------------------------------*/
struct __attribute__((__packed__, aligned(4))) MailBoxRegisters
{
	const u32_t Read0;											// 0x00         Read data from VC to ARM
	u32_t Unused[3];											// 0x04-0x0F
	u32_t Peek0;												// 0x10
	u32_t Sender0;												// 0x14
	u32_t Status0;												// 0x18         Status of VC to ARM
	u32_t Config0;												// 0x1C        
	u32_t Write1;												// 0x20         Write data from ARM to VC
	u32_t Unused2[3];											// 0x24-0x2F
	u32_t Peek1;												// 0x30
	u32_t Sender1;												// 0x34
	u32_t Status1;												// 0x38         Status of ARM to VC
	u32_t Config1;												// 0x3C 
};

/*--------------------------------------------------------------------------}
{         MINI UART IO Register BCM2835 ARM Peripheral manual page 11		}
{--------------------------------------------------------------------------*/
typedef union
{
	struct __attribute__((__packed__))
	{
		unsigned DATA : 8;											// @0-7 Transmit Read/write data if DLAB=0, DLAB = 1 Lower 8 bits of 16 bit baud rate generator 
		unsigned reserved : 24;										// @8-31 Reserved - Write as 0, read as don't care 
	};
	u32_t Raw32;													// Union to access all 32 bits as a u32_t
} mu_io_reg_t;

/*--------------------------------------------------------------------------}
{ MINI UART INTERRUPT ENABLE Register BCM2835 ARM Peripheral manual page 12	}
{   PAGE HAS ERRORS: https://elinux.org/BCM2835_datasheet_errata            }
{   It is essentially same as standard 16550 register IER                   }
{--------------------------------------------------------------------------*/
typedef union
{
	struct __attribute__((__packed__))
	{
		unsigned RXDI : 1;											// @0	 If this bit is set the interrupt line is asserted if the receive FIFO holds at least 1 byte.
		unsigned TXEI : 1;											// @1	 If this bit is set the interrupt line is asserted if the transmit FIFO is empty.  
		unsigned LSI : 1;											// @2	 If this bit is set the Receiver Line Status interrupt is asserted on overrun error, parity error, framing error etc
		unsigned MSI : 1;											// @3	 If this bit is set the Modem Status interrupt is asserted on a change To Send(CTS), Data Set Ready(DSR)
		unsigned reserved : 28;										// @4-31 Reserved - Write as 0, read as don't care 
	};
	u32_t Raw32;													// Union to access all 32 bits as a u32_t
} mu_ie_reg_t;

/*--------------------------------------------------------------------------}
{   MINI UART INTERRUPT ID Register BCM2835 ARM Peripheral manual page 13	}
{--------------------------------------------------------------------------*/
typedef union
{
	const struct __attribute__((__packed__))
	{																// THE REGISTER READ DEFINITIONS 
		unsigned PENDING : 1;										// @0	 This bit is clear whenever an interrupt is pending 
		enum
        {
			MU_NO_INTERRUPTS = 0,									//		 No interrupts pending
			MU_TXE_INTERRUPT = 1,									//		 Transmit buffer empty causing interrupt
			MU_RXD_INTERRUPTS = 2,									//		 receive fifa has data causing interrupt 
		} SOURCE : 2;												// @1-2	 READ this register shows the interrupt ID bits 
		unsigned reserved_rd : 29;									// @3-31 Reserved - Write as 0, read as don't care 
	};
	struct __attribute__((__packed__))
	{																// THE REGISTER WRITE DEFINITIONS 
		unsigned unused : 1;										// @0	 This bit has no use when writing 
		unsigned RXFIFO_CLEAR : 1;									// @1	 Clear the receive fifo by writing a 1
		unsigned TXFIFO_CLEAR : 1;									// @2	 Clear the transmit fifo by writing a 1
		unsigned reserved_wr : 29;									// @3-31 Reserved - Write as 0, read as don't care 
	};
	u32_t Raw32;													// Union to access all 32 bits as a u32_t
} mu_ii_reg_t;

/*--------------------------------------------------------------------------}
{	MINI UART LINE CONTROL Register BCM2835 ARM Peripheral manual page 14	}
{--------------------------------------------------------------------------*/
typedef union
{
	struct __attribute__((__packed__))
	{
		unsigned DATA_LENGTH : 1;									// @0	 If clear the UART works in 7-bit mode, If set the UART works in 8-bit mode 
		unsigned reserved : 5;										// @1-5	 Reserved, write zero, read as don�t care Some of these bits have functions in a 16550 compatible UART but are ignored here
		unsigned BREAK : 1;											// @6	 If set high the UART1_TX line is pulled low continuously
		unsigned DLAB : 1;											// @7	 DLAB access control bit.
		unsigned reserved1 : 24;									// @8-31 Reserved - Write as 0, read as don't care 
	};
	u32_t Raw32;													// Union to access all 32 bits as a u32_t
} mu_lcr_reg_t;

/*--------------------------------------------------------------------------}
{	MINI UART MODEM CONTROL Register BCM2835 ARM Peripheral manual page 14	}
{--------------------------------------------------------------------------*/
typedef union
{
	struct __attribute__((__packed__))
	{
		unsigned reserved : 1;										// @0	 Reserved, write zero, read as don�t care 
		unsigned RTS : 1;											// @1	 If clear the UART1_RTS line is high, If set the UART1_RTS line is low 
		unsigned reserved1 : 30;									// @2-31 Reserved - Write as 0, read as don't care 
	};
	u32_t Raw32;													// Union to access all 32 bits as a u32_t
} mu_mcr_reg_t;

/*--------------------------------------------------------------------------}
{	MINI UART LINE STATUS Register BCM2835 ARM Peripheral manual page 15	}
{--------------------------------------------------------------------------*/
typedef union
{
	struct __attribute__((__packed__))
	{
		unsigned RXFDA : 1;											// @0	 This bit is set if the receive FIFO holds at least 1 
		unsigned RXOE : 1;											// @1	 This bit is set if there was a receiver overrun
		unsigned reserved : 3;										// @2-4	 Reserved, write zero, read as don�t care 
		unsigned TXFE : 1;											// @5	 This bit is set if the transmit FIFO can accept at least one byte
		unsigned TXIdle : 1;										// @6	 This bit is set if the transmit FIFO is empty and the transmitter is idle. (Finished shifting out the last bit). 
		unsigned reserved1 : 25;									// @7-31 Reserved - Write as 0, read as don't care 
	};
	u32_t Raw32;													// Union to access all 32 bits as a u32_t
} mu_lsr_reg_t;

/*--------------------------------------------------------------------------}
{	MINI UART MODEM STATUS Register BCM2835 ARM Peripheral manual page 15	}
{--------------------------------------------------------------------------*/
typedef union
{
	struct __attribute__((__packed__))
	{
		unsigned reserved : 4;										// @0-3	 Reserved, write zero, read as don�t care 
		unsigned CTS : 1;											// @4	 This bit is the inverse of the CTS input, If set the UART1_CTS pin is low If clear the UART1_CTS pin is high 
		unsigned reserved1 : 27;									// @5-31 Reserved - Write as 0, read as don't care 
	};
	u32_t Raw32;													// Union to access all 32 bits as a u32_t
} mu_msr_reg_t;

/*--------------------------------------------------------------------------}
{	  MINI UART SCRATCH Register BCM2835 ARM Peripheral manual page 16	    }
{--------------------------------------------------------------------------*/
typedef union
{
	struct __attribute__((__packed__))
	{
		unsigned USER_DATA : 8;										// @0-7		One whole byte extra on top of the 134217728 provided by the SDC  
		unsigned reserved : 24;										// @8-31	Reserved - Write as 0, read as don't care 
	};
	u32_t Raw32;													// Union to access all 32 bits as a u32_t
} mu_scratch_reg_t;

/*--------------------------------------------------------------------------}
{     MINI UART CONTROL Register BCM2835 ARM Peripheral manual page 16	    }
{--------------------------------------------------------------------------*/
typedef union
{
	struct __attribute__((__packed__))
	{
		unsigned RXE : 1;											// @0		If this bit is set the mini UART receiver is enabled, If this bit is clear the mini UART receiver is disabled  
		unsigned TXE : 1;											// @1		If this bit is set the mini UART transmitter is enabled, If this bit is clear the mini UART transmitter is disabled
		unsigned EnableRTS : 1;										// @2		If this bit is set the RTS line will de-assert if the rc FIFO reaches it 'auto flow' level. If this bit is clear RTS is controlled by the AUX_MU_MCR_REG register bit 1. 
		unsigned EnableCTS : 1;										// @3		If this bit is set the transmitter will stop if the CTS line is de-asserted. If this bit is clear the transmitter will ignore the status of the CTS line
		enum
        {
			FIFOhas3spaces = 0,
			FIFOhas2spaces = 1,
			FIFOhas1spaces = 2,
			FIFOhas4spaces = 3,
		} RTSflowLevel : 2;											// @4-5		These two bits specify at what receiver FIFO level the RTS line is de-asserted in auto-flow mode
		unsigned RTSassertLevel : 1;								// @6		If set the RTS auto flow assert level is low, If clear the RTS auto flow assert level is high
		unsigned CTSassertLevel : 1;								// @7		If set the CTS auto flow assert level is low, If clear the CTS auto flow assert level is high
		unsigned reserved : 24;										// @8-31	Reserved - Write as 0, read as don't care 
	};
	u32_t Raw32;													// Union to access all 32 bits as a u32_t
} mu_cntl_reg_t;

/*--------------------------------------------------------------------------}
{	  MINI UART STATUS Register BCM2835 ARM Peripheral manual page 18	    }
{--------------------------------------------------------------------------*/
typedef union
{
	struct __attribute__((__packed__))
	{
		unsigned RXFDA : 1;											// @0		This bit is set if the receive FIFO holds at least 1
		unsigned TXFE : 1;											// @1		If this bit is set the mini UART transmitter FIFO can accept at least one more symbol
		unsigned RXIdle : 1;										// @2		If this bit is set the receiver is idle. If this bit is clear the receiver is busy
		unsigned TXIdle : 1;										// @3		If this bit is set the transmitter is idle. If this bit is clear the transmitter is idle
		unsigned RXOE : 1;											// @4		This bit is set if there was a receiver overrun
		unsigned TXFF : 1;											// @5		The inverse of bit 0
		unsigned RTS : 1;											// @6		This bit shows the status of the RTS line
		unsigned CTS : 1;											// @7		This bit shows the status of the CTS line
		unsigned TXFCE : 1;											// @8		If this bit is set the transmitter FIFO is empty. Thus it can accept 8 symbols
		unsigned TX_DONE : 1;										// @9		This bit is set if the transmitter is idle and the transmit FIFO is empty. It is a logic AND of bits 2 and 8 
		unsigned reserved : 6;										// @10-15	Reserved - Write as 0, read as don't care 
		unsigned RXFIFOLEVEL : 4;									// @16-19	These bits shows how many symbols are stored in the receive FIFO The value is in the range 0-8 
		unsigned reserved1 : 4;										// @20-23	Reserved - Write as 0, read as don't care 
		unsigned TXFIFOLEVEL : 4;									// @24-27	These bits shows how many symbols are stored in the transmit FIFO The value is in the range 0-8
		unsigned reserved2 : 4;										// @28-31	Reserved - Write as 0, read as don't care 
	};
	u32_t Raw32;													// Union to access all 32 bits as a u32_t
} mu_stat_reg_t;

/*--------------------------------------------------------------------------}
{	  MINI UART BAUDRATE Register BCM2835 ARM Peripheral manual page 19  	}
{--------------------------------------------------------------------------*/
typedef union
{
	struct __attribute__((__packed__))
	{
		unsigned DIVISOR : 16;										// @0-15	 Baudrate divisor  
		unsigned reserved : 16;										// @16-31	 Reserved - Write as 0, read as don't care 
	};
	u32_t Raw32;													// Union to access all 32 bits as a u32_t
} mu_baudrate_reg_t;

/*--------------------------------------------------------------------------}
{	  MINIUART STRUCTURE LAYOUT BCM2835 ARM Peripheral manual page 8	    }
{--------------------------------------------------------------------------*/
struct __attribute__((__packed__, aligned(4))) MiniUARTRegisters
{
	mu_io_reg_t IO;													// +0x0
	mu_ie_reg_t IER;												// +0x4
	mu_ii_reg_t IIR;												// +0x8
	mu_lcr_reg_t LCR;												// +0xC
	mu_mcr_reg_t MCR;												// +0x10
	const mu_lsr_reg_t LSR;											// +0x14	** READ ONLY HENCE CONST **
	const mu_msr_reg_t MSR;											// +0x18	** READ ONLY HENCE CONST **
	mu_scratch_reg_t SCRATCH;										// +0x1C
	mu_cntl_reg_t CNTL;												// +0x20
	const mu_stat_reg_t STAT;										// +0x24	** READ ONLY HENCE CONST **
	mu_baudrate_reg_t BAUD;											// +0x28;
};

/*--------------------------------------------------------------------------}
{     PL011 UART DATA Register BCM2835 ARM Peripheral manual page 179/180	}
{--------------------------------------------------------------------------*/
typedef union
{
	struct __attribute__((__packed__))
	{
		unsigned DATA : 8;											// @0-7		Transmit Read/write data
		unsigned FE : 1;											// @8		Framing error
		unsigned PE : 1;											// @9		Parity error
		unsigned BE : 1;											// @10		Break error
		unsigned OE : 1;											// @11		Overrun error
		unsigned _reserved : 20;									// @12-31	Reserved - Write as 0, read as don't care 
	};
	u32_t Raw32;													// Union to access all 32 bits as a u32_t
} pl011_data_reg_t;

/*--------------------------------------------------------------------------}
{     PL011 UART FR Register BCM2835 ARM Peripheral manual page 181/182	    }
{--------------------------------------------------------------------------*/
typedef union
{
	struct __attribute__((__packed__))
	{
		unsigned CTS : 1;											// @0		Clear to send. This bit is the complement of the UART clear to send, nUARTCTS
		unsigned DSR : 1;											// @1		Unsupported, write zero, read as don't care 
		unsigned DCD : 1;											// @2		Unsupported, write zero, read as don't care  
		unsigned BUSY : 1;											// @3		UART busy. If this bit is set to 1, the UART is busy transmitting data.
		unsigned RXFE : 1;											// @4		Receive FIFO empty. The meaning of this bit depends on the state of the FEN bit
		unsigned TXFF : 1;											// @5		Transmit FIFO full. The meaning of this bit depends on the state of the FEN bit
		unsigned RXFF : 1;											// @6		Receive FIFO full. The meaning of this bit depends on the state of the FEN bit 
		unsigned TXFE : 1;											// @7		Transmit FIFO empty. The meaning of this bit depends on the state of the FEN bit 
		unsigned _reserved : 24;									// @8-31	Reserved - Write as 0, read as don't care 
	};
	u32_t Raw32;													// Union to access all 32 bits as a u32_t
} pl011_fr_reg_t;

/*--------------------------------------------------------------------------}
{      PL011 UART IBRD Register BCM2835 ARM Peripheral manual page 183	    }
{--------------------------------------------------------------------------*/
typedef union
{
	struct __attribute__((__packed__))
	{
		unsigned DIVISOR : 16;										// @0-15	Integer baud rate divisor
		unsigned _reserved : 16;									// @12-31	Reserved - Write as 0, read as don't care 
	};
	u32_t Raw32;													// Union to access all 32 bits as a u32_t
} pl011_ibrd_reg_t;

/*--------------------------------------------------------------------------}
{      PL011 UART FBRD Register BCM2835 ARM Peripheral manual page 184	    }
{--------------------------------------------------------------------------*/
typedef union
{
	struct __attribute__((__packed__))
	{
		unsigned DIVISOR : 6;										// @0-5		Factional baud rate divisor
		unsigned _reserved : 26;									// @6-31	Reserved - Write as 0, read as don't care 
	};
	u32_t Raw32;													// Union to access all 32 bits as a u32_t
} pl011_fbrd_reg_t;

/*--------------------------------------------------------------------------}
{    PL011 UART LRCH Register BCM2835 ARM Peripheral manual page 184/185	}
{--------------------------------------------------------------------------*/
typedef union
{
	struct __attribute__((__packed__))
	{
		unsigned BRK : 1;											// @0		Send break. If this bit is set to 1, a low-level is continually output on the TXD output
		unsigned PEN : 1;											// @1		Parity enable, 0 = parity is disabled, 1 = parity via bit 2. 
		unsigned EPS : 1;											// @2		If PEN = 1 then 0 = odd parity, 1 = even parity
		unsigned STP2 : 1;											// @3		Two stops = 1, 1 stop bit = 0
		unsigned FEN : 1;											// @4		FIFO's enable = 1, No FIFO's uart becomes 1 character deep = 0
		enum
        {
			PL011_DATA_5BITS = 0,
			PL011_DATA_6BITS = 1,
			PL011_DATA_7BITS = 2,
			PL011_DATA_8BITS = 3,
		} DATALEN : 2;												// @5-6		Data length for transmission
		unsigned SPS : 1;											// @7		Stick parity select 1 = enabled, 0 = stick parity is disabled 
		unsigned _reserved : 24;									// @8-31	Reserved - Write as 0, read as don't care 
	};
	u32_t Raw32;													// Union to access all 32 bits as a u32_t
} pl011_lrch_reg_t;

/*--------------------------------------------------------------------------}
{    PL011 UART CR Register BCM2835 ARM Peripheral manual page 185/186/187	}
{--------------------------------------------------------------------------*/
typedef union
{
	struct __attribute__((__packed__))
	{
		unsigned UARTEN : 1;										// @0		UART enable = 1, disabled = 0
		unsigned _unused : 6;										// @2-6		unused bits
		unsigned LBE : 1;											// @7		Loop back enable = 1
		unsigned TXE : 1;											// @8		TX enabled = 1, disabled = 0
		unsigned RXE : 1;											// @9		RX enabled = 1, disabled = 0
		unsigned DTR_unused : 1;									// @10		DTR unused
		unsigned RTS : 1;											// @11		RTS complement when the bit is programmed to a 1 then nUARTRTS is LOW.
		unsigned OUT : 2;											// @12-13	Unsupported
		unsigned RTSEN : 1;											// @14		RTS hardware flow control enable if this bit is set to 1. 
		unsigned CTSEN : 1;											// @15		CTS hardware flow control enable if this bit is set to 1.
		unsigned _reserved : 16;									// @16-31	Reserved - Write as 0, read as don't care 
	};
	u32_t Raw32;													// Union to access all 32 bits as a u32_t
} pl011_cr_reg_t;

/*--------------------------------------------------------------------------}
{       PL011 UART ICR Register BCM2835 ARM Peripheral manual page 192	    }
{--------------------------------------------------------------------------*/
typedef union
{
	struct __attribute__((__packed__))
	{
		unsigned RIMIC : 1;											// @0		Unsupported, write zero, read as don't care 
		unsigned CTSMIC : 1;										// @1		nUARTCTS modem masked interrupt status 
		unsigned DCDMIC : 1;										// @2		Unsupported, write zero, read as don't care 
		unsigned DSRMIC : 1;										// @3		Unsupported, write zero, read as don't care 
		unsigned RXIC : 1;											// @4		Receive interrupt clear. 
		unsigned TXIC : 1;											// @5		Transmit interrupt clear
		unsigned RTIC : 1;											// @6		Receive timeout interrupt clear. 
		unsigned FEIC : 1;											// @7		Framing error interrupt clear.
		unsigned PEIC : 1;											// @8		Parity error interrupt clear.
		unsigned BEIC : 1;											// @9		Break error interrupt clear.
		unsigned OEIC : 1;											// @10		Overrun error interrupt clear.
		unsigned _reserved : 21;									// @11-31	Reserved - Write as 0, read as don't care 
	};
	u32_t Raw32;													// Union to access all 32 bits as a u32_t
} pl011_icr_reg_t;

/*--------------------------------------------------------------------------}
{	 PL011 UART STRUCTURE LAYOUT BCM2835 ARM Peripheral manual page 175	    }
{--------------------------------------------------------------------------*/
struct __attribute__((__packed__, aligned(4))) PL011UARTRegisters
{
	pl011_data_reg_t DR;										// +0x0
	u32_t RSRECR;												// +0x4
	u32_t _unused[4];											// +0x8, +0xC, +0x10, +0x14
	pl011_fr_reg_t FR;											// +0x18
	u32_t _unused1[2];											// +0x1C, 0x20
	pl011_ibrd_reg_t IBRD;										// +0x24
	pl011_fbrd_reg_t FBRD;										// +0x28
	pl011_lrch_reg_t LCRH;										// +0x2C
	pl011_cr_reg_t CR;											// +0x30
	u32_t IFLS;												// +0x34
	u32_t IMSC;												// +0x38
	u32_t RIS;													// +0x3C
	u32_t MIS;													// +0x40
	pl011_icr_reg_t ICR;										// +0x44
	u32_t DMACR;												// +0x48
};

/*--------------------------------------------------------------------------}
{    LOCAL TIMER INTERRUPT ROUTING REGISTER - QA7_rev3.4.pdf page 18		}
{--------------------------------------------------------------------------*/
typedef union
{
	struct
	{
		enum
        {
			LOCALTIMER_TO_CORE0_IRQ = 0,
			LOCALTIMER_TO_CORE1_IRQ = 1,
			LOCALTIMER_TO_CORE2_IRQ = 2,
			LOCALTIMER_TO_CORE3_IRQ = 3,
			LOCALTIMER_TO_CORE0_FIQ = 4,
			LOCALTIMER_TO_CORE1_FIQ = 5,
			LOCALTIMER_TO_CORE2_FIQ = 6,
			LOCALTIMER_TO_CORE3_FIQ = 7,
		} Routing : 3;												// @0-2		Local Timer routing 
		unsigned unused : 29;										// @3-31
	};
	u32_t Raw32;													// Union to access all 32 bits as a u32_t
} local_timer_int_route_reg_t;

/*--------------------------------------------------------------------------}
{    LOCAL TIMER CONTROL AND STATUS REGISTER - QA7_rev3.4.pdf page 17		}
{--------------------------------------------------------------------------*/
typedef union
{
	struct
	{
		unsigned ReloadValue : 28;									// @0-27	Reload value 
		unsigned TimerEnable : 1;									// @28		Timer enable (1 = enabled) 
		unsigned IntEnable : 1;										// @29		Interrupt enable (1= enabled)
		unsigned unused : 1;										// @30		Unused
		unsigned IntPending : 1;									// @31		Timer Interrupt flag (Read-Only) 
	};
	u32_t Raw32;													// Union to access all 32 bits as a u32_t
} local_timer_ctrl_status_reg_t;

/*--------------------------------------------------------------------------}
{     LOCAL TIMER CLEAR AND RELOAD REGISTER - QA7_rev3.4.pdf page 18		}
{--------------------------------------------------------------------------*/
typedef union
{
	struct
	{
		unsigned unused : 30;										// @0-29	unused 
		unsigned Reload : 1;										// @30		Local timer-reloaded when written as 1 
		unsigned IntClear : 1;										// @31		Interrupt flag clear when written as 1  
	};
	u32_t Raw32;													// Union to access all 32 bits as a u32_t
} local_timer_clr_reload_reg_t;

/*--------------------------------------------------------------------------}
{    GENERIC TIMER INTERRUPT CONTROL REGISTER - QA7_rev3.4.pdf page 13		}
{--------------------------------------------------------------------------*/
typedef union
{
	struct
	{
		unsigned nCNTPSIRQ_IRQ : 1;									// @0		Secure physical timer event IRQ enabled, This bit is only valid if bit 4 is clear otherwise it is ignored. 
		unsigned nCNTPNSIRQ_IRQ : 1;								// @1		Non-secure physical timer event IRQ enabled, This bit is only valid if bit 5 is clear otherwise it is ignored
		unsigned nCNTHPIRQ_IRQ : 1;									// @2		Hypervisor physical timer event IRQ enabled, This bit is only valid if bit 6 is clear otherwise it is ignored
		unsigned nCNTVIRQ_IRQ : 1;									// @3		Virtual physical timer event IRQ enabled, This bit is only valid if bit 7 is clear otherwise it is ignored
		unsigned nCNTPSIRQ_FIQ : 1;									// @4		Secure physical timer event FIQ enabled, If set, this bit overrides the IRQ bit (0) 
		unsigned nCNTPNSIRQ_FIQ : 1;								// @5		Non-secure physical timer event FIQ enabled, If set, this bit overrides the IRQ bit (1)
		unsigned nCNTHPIRQ_FIQ : 1;									// @6		Hypervisor physical timer event FIQ enabled, If set, this bit overrides the IRQ bit (2)
		unsigned nCNTVIRQ_FIQ : 1;									// @7		Virtual physical timer event FIQ enabled, If set, this bit overrides the IRQ bit (3)
		unsigned reserved : 24;										// @8-31	reserved
	};
	u32_t Raw32;													// Union to access all 32 bits as a u32_t
} generic_timer_int_ctrl_reg_t;


/*--------------------------------------------------------------------------}
{       MAILBOX INTERRUPT CONTROL REGISTER - QA7_rev3.4.pdf page 14			}
{--------------------------------------------------------------------------*/
typedef union
{
	struct
	{
		unsigned Mailbox0_IRQ : 1;									// @0		Set IRQ enabled, This bit is only valid if bit 4 is clear otherwise it is ignored. 
		unsigned Mailbox1_IRQ : 1;									// @1		Set IRQ enabled, This bit is only valid if bit 5 is clear otherwise it is ignored
		unsigned Mailbox2_IRQ : 1;									// @2		Set IRQ enabled, This bit is only valid if bit 6 is clear otherwise it is ignored
		unsigned Mailbox3_IRQ : 1;									// @3		Set IRQ enabled, This bit is only valid if bit 7 is clear otherwise it is ignored
		unsigned Mailbox0_FIQ : 1;									// @4		Set FIQ enabled, If set, this bit overrides the IRQ bit (0) 
		unsigned Mailbox1_FIQ : 1;									// @5		Set FIQ enabled, If set, this bit overrides the IRQ bit (1)
		unsigned Mailbox2_FIQ : 1;									// @6		Set FIQ enabled, If set, this bit overrides the IRQ bit (2)
		unsigned Mailbox3_FIQ : 1;									// @7		Set FIQ enabled, If set, this bit overrides the IRQ bit (3)
		unsigned reserved : 24;										// @8-31	reserved
	};
	u32_t Raw32;													// Union to access all 32 bits as a u32_t
} mailbox_int_ctrl_reg_t;

/*--------------------------------------------------------------------------}
{		 CORE INTERRUPT SOURCE REGISTER - QA7_rev3.4.pdf page 16			}
{--------------------------------------------------------------------------*/
typedef union
{
	struct
	{
		unsigned CNTPSIRQ : 1;										// @0		CNTPSIRQ  interrupt 
		unsigned CNTPNSIRQ : 1;										// @1		CNTPNSIRQ  interrupt 
		unsigned CNTHPIRQ : 1;										// @2		CNTHPIRQ  interrupt 
		unsigned CNTVIRQ : 1;										// @3		CNTVIRQ  interrupt 
		unsigned Mailbox0_Int : 1;									// @4		Set FIQ enabled, If set, this bit overrides the IRQ bit (0) 
		unsigned Mailbox1_Int : 1;									// @5		Set FIQ enabled, If set, this bit overrides the IRQ bit (1)
		unsigned Mailbox2_Int : 1;									// @6		Set FIQ enabled, If set, this bit overrides the IRQ bit (2)
		unsigned Mailbox3_Int : 1;									// @7		Set FIQ enabled, If set, this bit overrides the IRQ bit (3)
		unsigned GPU_Int : 1;										// @8		GPU interrupt <Can be high in one core only> 
		unsigned PMU_Int : 1;										// @9		PMU interrupt 
		unsigned AXI_Int : 1;										// @10		AXI-outstanding interrupt <For core 0 only!> all others are 0 
		unsigned Timer_Int : 1;										// @11		Local timer interrupt
		unsigned GPIO_Int : 16;										// @12-27	Peripheral 1..15 interrupt (Currently not used
		unsigned reserved : 4;										// @28-31	reserved
	};
	u32_t Raw32;													// Union to access all 32 bits as a u32_t
} core_int_source_reg_t;

/*--------------------------------------------------------------------------}
{					 ALL QA7 REGISTERS IN ONE BIG STRUCTURE					}
{--------------------------------------------------------------------------*/
struct __attribute__((__packed__, aligned(4))) QA7Registers
{
	local_timer_int_route_reg_t TimerRouting;						// 0x24
	u32_t GPIORouting;												// 0x28
	u32_t AXIOutstandingCounters;									// 0x2C
	u32_t AXIOutstandingIrq;										// 0x30
	local_timer_ctrl_status_reg_t TimerControlStatus;				// 0x34
	local_timer_clr_reload_reg_t TimerClearReload;					// 0x38
	u32_t unused;													// 0x3C
	generic_timer_int_ctrl_reg_t CoreTimerIntControl[4];			// 0x40, 0x44, 0x48, 0x4C  .. One per core
	mailbox_int_ctrl_reg_t  CoreMailboxIntControl[4];				// 0x50, 0x54, 0x58, 0x5C  .. One per core
	core_int_source_reg_t CoreIRQSource[4];							// 0x60, 0x64, 0x68, 0x6C  .. One per core
	core_int_source_reg_t CoreFIQSource[4];							// 0x70, 0x74, 0x78, 0x7C  .. One per core
};

/*--------------------------------------------------------------------------}
{						RASPBERRY PI MODEL NUMBER 							}
{--------------------------------------------------------------------------*/
/* https://github.com/raspberrypi/documentation/blob/master/hardware/raspberrypi/revision-codes/README.md */
typedef union
{
	struct
	{
		unsigned revision : 4;										// @0-3			revision 0,1,2 .. etc
		unsigned model : 8;											// @4-11		model type
		unsigned processor : 4;										// @12-15		processor 0 = BCM2835, 1 = BCM2836, 2 = BCM2837
		unsigned manufacturer : 4;									// @16-19		manufacturer 
		unsigned memory_size : 3;									// @20-22		memory size 0 = 256 MB, 1 = 512MB, 2 = 1024MB 
		unsigned new_revision : 1;									// @23			new style revision if set
		unsigned _reserved : 8;										// @24-31		reserved for future use
	};
	u32_t Raw32;													// Union to access all 32 bits as a u32_t
} model_number_t;

#endif