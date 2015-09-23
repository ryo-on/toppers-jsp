/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 *
 *  Copyright (C) 2000-2002 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2001,2002 by Dep. of Computer Science and Engineering
 *                   Tomakomai National College of Technology, JAPAN
 *  Copyright (C) 2001,2002 by Industrial Technology Institute,
 *                              Miyagi Prefectural Government, JAPAN
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
 *  @(#) $Id: makeoffset.c,v 1.2 2002/04/13 13:14:45 imai Exp $
 */


#include "jsp_kernel.h"
#include "task.h"

#define offsetof(structure, field) \
                        ((INT) &(((structure *) 0)->field))

#define OFFSET_DEF(TYPE, FIELD)						\
	  int offset_of_##TYPE##_##FIELD (void) {				\
	  	return offsetof(TYPE, FIELD);				\
	  }

#define OFFSET_DEF2(TYPE, FIELD, FIELDNAME)	 			\
	  int offset_of_##TYPE##_##FIELDNAME (void) {			\
	  	return offsetof(TYPE, FIELD);				\
	  }

#define BIT_FIELD_OFFSET_DEF(TYPE, FIELD)				\
int bit_field_offset_of_##TYPE##_##FIELD(void)				\
{									\
	 TYPE tmp;						\
	return (tmp.FIELD);						\
}



#define BIT_LABEL(TYPE, FIELD)	bit_of_##TYPE##_##FIELD##_bit

OFFSET_DEF (TCB, tinib)
OFFSET_DEF2(TCB, tskctxb.sp, sp)
OFFSET_DEF2(TCB, tskctxb.pc, pc)
OFFSET_DEF (TINIB, task)
OFFSET_DEF (TINIB, exinf)
OFFSET_DEF (TCB, texptn)
BIT_FIELD_OFFSET_DEF (TCB, enatex)


TCB	BIT_LABEL(TCB, enatex) = {
		{ NULL, NULL }, NULL, 0, 0,
		FALSE, FALSE, TRUE,
		0, NULL, { NULL, NULL }
	};

