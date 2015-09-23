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
 *  @(#) $Id: linux_sigio.c,v 1.1 2000/11/14 16:27:57 honda Exp $
 */


#include <jsp_services.h>
#include "../kernel/jsp_kernel.h"
#include "../kernel/queue.h"
#include "kernel_id.h"
#include <signal.h>
#include <linux_sigio.h>


/*
 *  SIGIO$BDLCN%$%Y%s%H%-%e!<(B
 */

static QUEUE	sigio_queue;

/*
 *  SIGIO$BDLCN%O%s%I%i(B
 *
 *  SIGIO$BDLCN=hM}%?%9%/$r5/>2$9$k!%(B
 */

void
linux_sigio_handler()
{
	syscall(iwup_tsk(TSK_LINUX_SIGIO));
}

/*
 *  $B%N%s%V%m%C%-%s%0(BI/O $B%b%8%e!<%k5/F0%k!<%A%s(B
 *
 *  SIGIO$BDLCN%$%Y%s%H%-%e!<$r=i4|2=!%(BSIGIO$BDLCN=hM}%?%9%/$H%;%^%U%)$r@8(B
 *  $B@.!%(BSIGIO$BDLCN%O%s%I%i$r@_Dj!%(B
 */

static int	initflag = 0;		/* $B=i4|2=:Q%U%i%0(B */

void
linux_sigio_initialize(VP_INT exinf)
{
    
	if (!initflag) {
		queue_initialize(&sigio_queue);
		initflag = 1;
	}
}

/*
 *  SIGIO$BDLCN=hM}%?%9%/K\BN(B
 */

void
linux_sigio_task(void)
{
	QUEUE	*q;
	SIGIOEB	*event;

	while (slp_tsk() == E_OK) {
		/*
		 *  SIGIO$BDLCN%$%Y%s%H%-%e!<Cf$N3F%$%Y%s%H%V%m%C%/$N%3!<(B
		 *  $B%k%P%C%/%k!<%A%s$r8F$S$@$9!%%3!<%k%P%C%/%k!<%A%s$,(B
		 *  0 $B0J30$rJV$7$?>l9g!$$=$N%$%Y%s%H%V%m%C%/$r:o=|$9$k!%(B
		 */
		syscall(wai_sem(SEM_LINUX_SIGIO));
		q = sigio_queue.next;
		while (q != &sigio_queue) {
			event = ((SIGIOEB *) q);
			q = q->next;
			if ((*(event->callback))(event->arg)) {
				queue_delete((QUEUE *) &(event->queue));
			}
		}
		syscall(sig_sem(SEM_LINUX_SIGIO));
	}
	ext_tsk();
}

/*
 *  SIGIO$BDLCN%$%Y%s%H$r(BSIGIO$BDLCN%$%Y%s%H%-%e!<$XA^F~(B
 *
 *  $B%7%9%F%`%*%V%8%'%/%H$K%"%/%;%9$9$k$?$a$K!$3HD%(BSVC$B%O%s%I%i$H$7$FF0(B
 *  $B:n$5$;$F$$$k!%(B
 */

ER
enqueue_sigioeb(SIGIOEB *event)
{
	syscall(wai_sem(SEM_LINUX_SIGIO));
	queue_insert_prev(&sigio_queue , (QUEUE *) &(event->queue));
	syscall(sig_sem(SEM_LINUX_SIGIO));
	return(E_OK);
}


/*
 *   $B%7%9%F%`5/F0;~EPO?MQ(B
 *   $B%7%9%F%`5/F0;~!"=i4|2=%k!<%A%s$OHs%?%9%/%3%s%F%-%9%H$+$i(B
 *   $B8F$P$l$k$?$a(Benqueue_sigioeb()$B$G%;%^%U%)$,;HMQ$G$-$J$$(B
 */

ER
enqueue_sigioeb_initialize(SIGIOEB *event)
{
	queue_insert_prev(&sigio_queue , (QUEUE *) &(event->queue));
	return(E_OK);
}






























