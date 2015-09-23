/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2002 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 * 
 *  上記著作権者は，Free Software Foundation によって公表されている 
 *  GNU General Public License の Version 2 に記述されている条件か，以
 *  下の(1)〜(4)の条件を満たす場合に限り，本ソフトウェア（本ソフトウェ
 *  アを改変したものを含む．以下同じ）を使用・複製・改変・再配布（以下，
 *  利用と呼ぶ）することを無償で許諾する．
 *  (1) 本ソフトウェアをソースコードの形で利用する場合には，上記の著作
 *      権表示，この利用条件および下記の無保証規定が，そのままの形でソー
 *      スコード中に含まれていること．
 *  (2) 本ソフトウェアを再利用可能なバイナリコード（リロケータブルオブ
 *      ジェクトファイルやライブラリなど）の形で利用する場合には，利用
 *      に伴うドキュメント（利用者マニュアルなど）に，上記の著作権表示，
 *      この利用条件および下記の無保証規定を掲載すること．
 *  (3) 本ソフトウェアを再利用不可能なバイナリコードの形または機器に組
 *      み込んだ形で利用する場合には，次のいずれかの条件を満たすこと．
 *    (a) 利用に伴うドキュメント（利用者マニュアルなど）に，上記の著作
 *        権表示，この利用条件および下記の無保証規定を掲載すること．
 *    (b) 利用の形態を，別に定める方法によって，上記著作権者に報告する
 *        こと．
 *  (4) 本ソフトウェアの利用により直接的または間接的に生じるいかなる損
 *      害からも，上記著作権者を免責すること．
 * 
 *  本ソフトウェアは，無保証で提供されているものである．上記著作権者は，
 *  本ソフトウェアに関して，その適用可能性も含めて，いかなる保証も行わ
 *  ない．また，本ソフトウェアの利用により直接的または間接的に生じたい
 *  かなる損害に関しても，その責任を負わない．
 * 
 *  @(#) $Id: cpu_defs.h,v 1.5 2002/04/10 11:17:16 takayuki Exp $
 */

/*
 *	プロセッサに依存する定義（V850用）
 */

#ifndef _CPU_DEFS_H_
#define _CPU_DEFS_H_

#define V850

	/* 特に何も無いときにPSWの値 */
#define DEFAULT_PSW	0x0

	/* 割込み要因番号 */
#define INT_RESET	0
#define INT_NMI		1
#define INT_WDT		2
#define INT_TRAP0	4
#define INT_TRAP1	5
#define INT_ILGOP	6
#define INT_WDTM	8
#define INT_P0		9
#define INT_P1		10
#define INT_P2		11
#define INT_P3		12
#define INT_P4		13
#define INT_P5		14
#define INT_P6		15
#define INT_WTI		16
#define INT_TM00	17
#define INT_TM01	18
#define INT_TM10	19
#define INT_TM11	20
#define INT_TM2		21
#define INT_TM3		22
#define INT_TM4		23
#define INT_TM5		24
#define INT_CSI0	25
#define INT_SER0	26
#define INT_CSI1	27
#define INT_ST0		28
#define INT_CSI2	29
#define INT_SER1	30
#define INT_SR1		31
#define INT_ST1		32
#define INT_AD		33
#define INT_DMA0	34
#define INT_DMA1	35
#define INT_DMA2	36
#define INT_WT		37



#ifndef _MACRO_ONLY

typedef	UINT		INHNO;		/* 割込みハンドラ番号 */
typedef	UB			IPR;		/* 割込み優先度 */
typedef	UINT		EXCNO;		/* CPU例外ハンドラ番号 */

#endif /* _MACRO_ONLY */
#endif /* _CPU_DEFS_H_ */
