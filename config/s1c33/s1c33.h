/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 *
 *  Copyright (C) 2000 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *
 *  Copyright (C) 2004 by SEIKO EPSON Corp, JAPAN
 *
 *  �嵭����Ԥϡ��ʲ��� (1)��(4) �ξ�狼��Free Software Foundation
 *  �ˤ�äƸ�ɽ����Ƥ��� GNU General Public License �� Version 2 �˵�
 *  �Ҥ���Ƥ���������������˸¤ꡤ�ܥ��եȥ��������ܥ��եȥ�����
 *  ����Ѥ�����Τ�ޤࡥ�ʲ�Ʊ���ˤ���ѡ�ʣ�������ѡ������ۡʰʲ���
 *  ���ѤȸƤ֡ˤ��뤳�Ȥ�̵���ǵ������롥
 *  (1) �ܥ��եȥ������򥽡��������ɤη������Ѥ�����ˤϡ��嵭������
 *      ��ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ��꤬�����Τޤޤη��ǥ���
 *      ����������˴ޤޤ�Ƥ��뤳�ȡ�
 *  (2) �ܥ��եȥ������򡤥饤�֥������ʤɡ�¾�Υ��եȥ�������ȯ�˻�
 *      �ѤǤ�����Ǻ����ۤ�����ˤϡ������ۤ�ȼ���ɥ�����ȡ�����
 *      �ԥޥ˥奢��ʤɡˤˡ��嵭�����ɽ�����������Ѿ�浪��Ӳ���
 *      ��̵�ݾڵ����Ǻܤ��뤳�ȡ�
 *  (3) �ܥ��եȥ������򡤵�����Ȥ߹���ʤɡ�¾�Υ��եȥ�������ȯ�˻�
 *      �ѤǤ��ʤ����Ǻ����ۤ�����ˤϡ����Τ����줫�ξ�����������
 *      �ȡ�
 *    (a) �����ۤ�ȼ���ɥ�����ȡ����Ѽԥޥ˥奢��ʤɡˤˡ��嵭����
 *        �ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ����Ǻܤ��뤳�ȡ�
 *    (b) �����ۤη��֤��̤�������ˡ�ˤ�äơ�TOPPERS�ץ��������Ȥ�
 *        ��𤹤뤳�ȡ�
 *  (4) �ܥ��եȥ����������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������뤤���ʤ�»
 *      ������⡤�嵭����Ԥ����TOPPERS�ץ��������Ȥ����դ��뤳�ȡ�
 *
 *  �ܥ��եȥ������ϡ�̵�ݾڤ��󶡤���Ƥ����ΤǤ��롥�嵭����Ԥ�
 *  ���TOPPERS�ץ��������Ȥϡ��ܥ��եȥ������˴ؤ��ơ�����Ŭ�Ѳ�ǽ����
 *  �ޤ�ơ������ʤ��ݾڤ�Ԥ�ʤ����ޤ����ܥ��եȥ����������Ѥˤ��ľ
 *  ��Ū�ޤ��ϴ���Ū�������������ʤ�»���˴ؤ��Ƥ⡤������Ǥ�����ʤ���
 *
 */

/*
 *  �ϡ��ɥ������񸻤����
 */
#ifndef _S1C33_H_
#define _S1C33_H_

/*
 *  ���ѥ쥸������
 */
#define S1C33_GR_NUM		16

/*
 *  PSR
 */
#define S1C33_PSR_INITIAL	0x00000000
#define S1C33_PSR_MASK_IL	0x00000F00
#define S1C33_PSR_FLAG_IE	0x00000010

/*
 *  ���ܥ���ޥå�
 */
#define S1C33_AREA00_BASE	0x00000000
#define S1C33_AREA01_BASE	0x00040000
#define S1C33_AREA02_BASE	0x00060000
#define S1C33_AREA03_BASE	0x00080000
#define S1C33_AREA04_BASE	0x00100000
#define S1C33_AREA05_BASE	0x00200000
#define S1C33_AREA06_BASE	0x00300000
#define S1C33_AREA07_BASE	0x00400000
#define S1C33_AREA08_BASE	0x00600000
#define S1C33_AREA09_BASE	0x00800000
#define S1C33_AREA10_BASE	0x00c00000
#define S1C33_AREA11_BASE	0x01000000
#define S1C33_AREA12_BASE	0x01800000
#define S1C33_AREA13_BASE	0x02000000
#define S1C33_AREA14_BASE	0x03000000
#define S1C33_AREA15_BASE	0x04000000
#define S1C33_AREA16_BASE	0x06000000
#define S1C33_AREA17_BASE	0x08000000
#define S1C33_AREA18_BASE	0x0c000000

#define S1C33_INTERNAL_RAM_BASE		S1C33_AREA00_BASE
#define S1C33_INT08_DEVICE_BASE		(S1C33_AREA01_BASE + 0x0000000)
#define S1C33_INT16_DEVICE_BASE		(S1C33_AREA01_BASE + 0x0008000)
#define S1C33_EXT08_DEVICE_BASE		(S1C33_AREA06_BASE + 0x0000000)
#define S1C33_EXT16_DEVICE_BASE		(S1C33_AREA06_BASE + 0x0080000)

#define S1C33_TIMER_CONTROL_BASE	(S1C33_INT08_DEVICE_BASE + 0x0000140)
#define S1C33_CLKTIMER_BASE		(S1C33_INT08_DEVICE_BASE + 0x0000150)
#define S1C33_P8TIMER_BASE		(S1C33_INT08_DEVICE_BASE + 0x0000160)
#define S1C33_WATCHDOG_BASE		(S1C33_INT08_DEVICE_BASE + 0x0000170)
#define S1C33_POWER_BASE		(S1C33_INT08_DEVICE_BASE + 0x0000180)
#define S1C33_SERIAL_BASE		(S1C33_INT08_DEVICE_BASE + 0x00001e0)
#define S1C33_AD_BASE			(S1C33_INT08_DEVICE_BASE + 0x0000240)
#define S1C33_INTC_BASE			(S1C33_INT08_DEVICE_BASE + 0x0000260)
#define S1C33_DMAC_BASE			(S1C33_INT08_DEVICE_BASE + 0x0000290)
#define S1C33_PORT_BASE			(S1C33_INT08_DEVICE_BASE + 0x00002c0)

#define S1C33_BCU_BASE			(S1C33_INT16_DEVICE_BASE + 0x0000120)
#define S1C33_P16TIMER_BASE		(S1C33_INT16_DEVICE_BASE + 0x0000180)
#define S1C33_IDMA_BASE			(S1C33_INT16_DEVICE_BASE + 0x0000200)
#define S1C33_HSDMA_BASE		(S1C33_INT16_DEVICE_BASE + 0x0000220)

/*
 *  �����ߥ٥����ֹ�
 */
#define S1C33_INHNO_RESET		0x00
#define S1C33_INHNO_ZERO		0x04
#define S1C33_INHNO_ADDRESS		0x06
#define S1C33_INHNO_DEBUG		0x07
#define S1C33_INHNO_NMI			0x08
#define S1C33_INHNO_INT0		0x0c
#define S1C33_INHNO_INT1		0x0d
#define S1C33_INHNO_INT2		0x0e
#define S1C33_INHNO_INT3		0x0f
#define S1C33_INHNO_PINT0		0x10
#define S1C33_INHNO_PINT1		0x11
#define S1C33_INHNO_PINT2		0x12
#define S1C33_INHNO_PINT3		0x13
#define S1C33_INHNO_KINT0		0x14
#define S1C33_INHNO_KINT1		0x15
#define S1C33_INHNO_HSDMA0		0x16
#define S1C33_INHNO_HSDMA1		0x17
#define S1C33_INHNO_HSDMA2		0x18
#define S1C33_INHNO_HSDMA3		0x19
#define S1C33_INHNO_IDMA		0x1a
#define S1C33_INHNO_P16TIMER0B		0x1e
#define S1C33_INHNO_P16TIMER0A		0x1f
#define S1C33_INHNO_P16TIMER1B		0x22
#define S1C33_INHNO_P16TIMER1A		0x23
#define S1C33_INHNO_P16TIMER2B		0x26
#define S1C33_INHNO_P16TIMER2A		0x27
#define S1C33_INHNO_P16TIMER3B		0x2a
#define S1C33_INHNO_P16TIMER3A		0x2b
#define S1C33_INHNO_P16TIMER4B		0x2e
#define S1C33_INHNO_P16TIMER4A		0x2f
#define S1C33_INHNO_P16TIMER5B		0x32
#define S1C33_INHNO_P16TIMER5A		0x33
#define S1C33_INHNO_P8TIMER0		0x34
#define S1C33_INHNO_P8TIMER1		0x35
#define S1C33_INHNO_P8TIMER2		0x36
#define S1C33_INHNO_P8TIMER3		0x37
#define S1C33_INHNO_SERIAL0ERR		0x38
#define S1C33_INHNO_SERIAL0RX		0x39
#define S1C33_INHNO_SERIAL0TX		0x3a
#define S1C33_INHNO_SERIAL1ERR		0x3c
#define S1C33_INHNO_SERIAL1RX		0x3d
#define S1C33_INHNO_SERIAL1TX		0x3e
#define S1C33_INHNO_AD			0x40
#define S1C33_INHNO_CLKTIMER		0x41
#define S1C33_INHNO_PINT4		0x44
#define S1C33_INHNO_PINT5		0x45
#define S1C33_INHNO_PINT6		0x46
#define S1C33_INHNO_PINT7		0x47

#ifndef _MACRO_ONLY

typedef unsigned char   byte;
typedef unsigned short  word;
typedef volatile byte   IOREG;
typedef volatile word   HIOREG;
typedef volatile int    LIOREG;

/*
 * �쥸����(TIMER_CONTROL 140)
 */
typedef struct {
	IOREG bP8ClkSelect45;
	IOREG bDummy[4];
	IOREG bP8ClkCtrl45;
	IOREG bP8ClkSelect;
	IOREG bP16ClkCtrl[6];
	IOREG bP8ClkCtrl[2];
	IOREG bADClkCtrl;
} s1c33TimerControl_t;

/*
 *  �쥸����(SERIAL 1e0)
 */
typedef struct {
	struct {
		IOREG bTxd;
		IOREG bRxd;
		IOREG bStatus;
		IOREG bControl;
		IOREG bIrDA;
	} stChannel01[2];

	IOREG Dummy[6];

	struct {
		IOREG bTxd;
		IOREG bRxd;
		IOREG bStatus;
		IOREG bControl;
		IOREG bIrDA;
	} stChannel23[2];
} s1c33Serial_t;

/*
 *  �쥸����(INTC 260)
 *
 */
typedef struct {
	IOREG bPriority[15];	/* C33209�ǤΥ��������bPriority[14] +	*/
	IOREG bDummy0[1];	/* bDummy0[2]�ι�����������		*/

	IOREG bIntEnable[10];	/* C33209�ǤΥ��������bIntEnable[8] +	*/
	IOREG bDummy1[6];	/* bDummy1[8]�ι�����������		*/

	IOREG bIntFactor[10];	/* C33209�ǤΥ��������bIntFactor[8] +	*/
	IOREG bDummy2[6];	/* bDummy2[8]�ι�����������		*/

	IOREG bIDMAReq[4];
	IOREG bIDMAEnable[4];
	IOREG bHSDMATriger[2];
	IOREG bHSDMASoftTrg;

	IOREG bIDMAReqExt;	/* C33209�ǤΥ��������bDummy3[4]��	*/
	IOREG bIDMAEnableExt;	/* ������������*/
	IOREG bDummy3[2];

	IOREG bReset;
} s1c33Intc_t;

/*
 *  �쥸����(PORT 2c0)
 */
typedef struct {
	struct {
		IOREG bFuncSwitch;
		IOREG bData;
	} stK5Port;

	IOREG bDummy;

	struct {
		IOREG bFuncSwitch;
		IOREG bData;
	} stK6Port;

	IOREG bIntFPSwitch;		/* C33L11�Ǥ�̤����		*/

	struct {
		IOREG bSpt[2];
		IOREG bSppt;
		IOREG bSept;
	} stPINT;

	struct {
		IOREG bSppk;
		IOREG bTM16Switch;	/* C33L11�Ǥ�̤����		*/
		IOREG bScpk[2];
		IOREG bSmpk[2];
	} stKINT;

	struct {
		IOREG bFuncSwitch;
		IOREG bData;
		IOREG bControl;
		IOREG bFuncExt		/* stPPort[0]�Τ�C33209,C33L11	*/;
					/* �Ȥ�̤����			*/
	} stPPort[4];
} s1c33Port_t;

/*
 *  �쥸����(BCU 120)
 */
typedef struct {
	HIOREG uwA18_15;
	HIOREG uwA14_13;
	HIOREG uwA12_11;
	HIOREG uwA10_09;
	HIOREG uwA08_07;
	HIOREG uwA06_04;
	IOREG  bDummy;
	IOREG  bTtbrProt;
	HIOREG uwBus;
	HIOREG uwDram;
	HIOREG uwAccess;
	LIOREG ulTtbr;
	HIOREG uwGACtrl;
	IOREG  bBClk;
} s1c33Bcu_t;

/*
 *  �쥸����(P16TIMER 180)
 */
typedef struct {
	struct {
		HIOREG uwComp[2];
		HIOREG uwCount;
		IOREG  bControl;
		IOREG  bDummy;
	} stChannel[6];
} s1c33P16Timer_t;

#endif /* _MACRO_ONLY */
#endif /* _S1C33_H_ */