/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 *
 *  Copyright (C) 2000,2001 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2001 by Industrial Technology Institute,
 *                              Miyagi Prefectural Government, JAPAN
 *
 *  �嵭����Ԥϡ��ʲ��ξ������������˸¤ꡤ�ܥ��եȥ��������ܥ�
 *  �եȥ���������Ѥ�����Τ�ޤࡥ�ʲ�Ʊ���ˤ���ѡ�ʣ�������ѡ�����
 *  �ۡʰʲ������ѤȸƤ֡ˤ��뤳�Ȥ�̵���ǵ������롥
 *  (1) �ܥ��եȥ������򥽡��������ɤη������Ѥ�����ˤϡ��嵭������
 *      ��ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ��꤬�����Τޤޤη��ǥ���
 *      ����������˴ޤޤ�Ƥ��뤳�ȡ�
 *  (2) �ܥ��եȥ�������Х��ʥꥳ���ɤη��ޤ��ϵ�����Ȥ߹����������
 *      �Ѥ�����ˤϡ����Τ����줫�ξ������������ȡ�
 *    (a) ���Ѥ�ȼ���ɥ�����ȡ����Ѽԥޥ˥奢��ʤɡˤˡ��嵭������
 *        ��ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ����Ǻܤ��뤳�ȡ�
 *    (b) ���Ѥη��֤��̤�������ˡ�ˤ�äơ��嵭����Ԥ���𤹤�
 *        ���ȡ�
 *  (3) �ܥ��եȥ����������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������뤤���ʤ�»
 *      ������⡤�嵭����Ԥ����դ��뤳�ȡ�
 *
 *  �ܥ��եȥ������ϡ�̵�ݾڤ��󶡤���Ƥ����ΤǤ��롥�嵭����Ԥϡ�
 *  �ܥ��եȥ������˴ؤ��ơ�����Ŭ�Ѳ�ǽ����ޤ�ơ������ʤ��ݾڤ�Ԥ�
 *  �ʤ����ޤ����ܥ��եȥ����������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū����������
 *  ���ʤ�»���˴ؤ��Ƥ⡤������Ǥ�����ʤ���
 *
 *  @(#) $Id: sys_config.c,v 1.1 2001/05/04 09:10:29 imai Exp $
 */


#include "jsp_kernel.h"
#include "tokiwa_sh1.h"


/*
 *  �ץ����å����̤Τ�����ѿ� (�ޥ���ץ����å��б�)
 */
INT	board_id;			/* �ܡ���ID */
INT	board_addr;			/* ��������������Ƭ���ɥ쥹 */


/*
 *  �������åȥ����ƥ��¸ ������롼����
 */
void
sys_initialize()
{
			/*  ���ꥢ0���꡼�ɥ��������WAIT����ˤ��  	*/
			/*  �������ȥ��ơ��������ʤ�  			*/
	*WCR1 &= ~WCR1_RW0;
			/*  ���ꥢ0,2��1���ơ��ȥ��󥰥�������  	*/
	*WCR3 &= WCR3_A02LW_MASK;
}


/*
 *  �������åȥ����ƥ�ν�λ�롼����
 *
 *  �����ƥ��λ������˻Ȥ����̾�ϥ�˥��ƤӽФ��Ǽ¸����롥
 *  	���ա���˥�������˼���
 */
void
sys_exit(void)
{
#ifdef WITH_STUB
  Asm("trapa #0xff"::);
#else
	while(1);
#endif /* WITH_STUB */
}

/*
 *   �����ƥ�ʸ��������λ���
 */

#ifdef WITH_STUB
#define SYS_PUT_CHAR(c) stub_putc(c)
#else
#include "serial.h"	/*  serial_write( )  */
#define SYS_PUT_CHAR(c) {		\
	char cc=c;			\
	serial_write(1, &cc, 1);	\
}
#endif /* WITH_STUB */


void
sys_putc(char c)
{
    if (c == '\n') {
        SYS_PUT_CHAR('\r');
    }
    SYS_PUT_CHAR(c);
}

