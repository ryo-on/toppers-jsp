/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 * 
 *  上記著作権者は，以下の条件を満たす場合に限り，本ソフトウェア（本ソ
 *  フトウェアを改変したものを含む．以下同じ）を使用・複製・改変・再配
 *  布（以下，利用と呼ぶ）することを無償で許諾する．
 *  (1) 本ソフトウェアをソースコードの形で利用する場合には，上記の著作
 *      権表示，この利用条件および下記の無保証規定が，そのままの形でソー
 *      スコード中に含まれていること．
 *  (2) 本ソフトウェアをバイナリコードの形または機器に組み込んだ形で利
 *      用する場合には，次のいずれかの条件を満たすこと．
 *    (a) 利用に伴うドキュメント（利用者マニュアルなど）に，上記の著作
 *        権表示，この利用条件および下記の無保証規定を掲載すること．
 *    (b) 利用の形態を，別に定める方法によって，上記著作権者に報告する
 *        こと．
 *  (3) 本ソフトウェアの利用により直接的または間接的に生じるいかなる損
 *      害からも，上記著作権者を免責すること．
 * 
 *  本ソフトウェアは，無保証で提供されているものである．上記著作権者は，
 *  本ソフトウェアに関して，その適用可能性も含めて，いかなる保証も行わ
 *  ない．また，本ソフトウェアの利用により直接的または間接的に生じたい
 *  かなる損害に関しても，その責任を負わない．
 * 
 *  @(#) $Id: sys_config.c,v 1.1 2000/11/14 16:30:22 honda Exp $
 */


#include "jsp_kernel.h"
#include "card_e09a.h"


/*
 *  プロセッサ識別のための変数 (マルチプロセッサ対応)
 */
INT	board_id;			/* ボードID */
INT	board_addr;			/* ローカルメモリの先頭アドレス */


/*
 *  ターゲットシステム依存 初期化ルーチン
 */

void
sys_initialize()
{
#ifndef WITH_STUB
    SCIF.SCSCR2 = 0;                 /* SCIFを停止,内部Pクロックを使う */
    SCIF.SCFCR2 = SCFCR2_TFRST | SCFCR2_RFRST; /* 受信送信FIFOをクリア */
    SCIF.SCSMR2 = 0;         /* Async,8data,1stop,no parity */
    SCIF.SCBRR2 = SCIF_BPS_VALUE; /* ボーレートの設定 */



    /*
     * ボーレートの設定後、1カウント分待たなければならない。
     * バスステートコントローラのリフレッシュカウンタを使い
     * 1カウント分待つ
     */

    *RFCR = RFCR_CLEAR;
    while( *RFCR < WAIT_RFCR_FOR_SCI);
    
    
    SCIF.SCFCR2 = 0x30;           /* R-FIFO=1,T-FIFO=1 トリガの設定 */

    SCIF.SCSSR2 = 0x0060;         /* エラーフラグをクリア */
    SCIF.SCSCR2 = 0x30;           /* Start TE = 1 RE = 1  */
#endif
    
    /*
     *  ISHボード上のデバッグ用LEDを発光
     */
    led_init();
    led_set(0xf0f0);
}


/*
 *  ターゲットシステムの終了ルーチン
 *
 *  システムを終了する時に使う．通常はモニタ呼び出しで実現する．
 *  
 */
void
sys_exit(void)
{
  Asm("trapa #0xff"::);
}


/*
 *   システム文字出力先の指定
 */

#ifdef WITH_STUB
#define SYS_PUT_CHAR(c) stub_putc(c)
#else
#define SYS_PUT_CHAR(c) scif_putc(c)
#endif /* WITH_STUB */


void
sys_putc(char c)
{
    if (c == '\n') {
        SYS_PUT_CHAR('\r');
    }
    SYS_PUT_CHAR(c);
}







