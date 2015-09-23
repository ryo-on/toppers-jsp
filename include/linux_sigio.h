/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
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
 *  @(#) $Id: linux_sigio.h,v 1.1 2000/11/14 16:27:57 honda Exp $
 */

/*
 *  LINUX�� �Υ�֥��å���I/O ���ݡ��ȥ⥸�塼��
 *
 *  �Υ�֥��å���I/O ���ݡ��ȥ⥸�塼��ϡ�SIGIO �����ʥ�ˤ�ꡤ�桼
 *  ������Ͽ����������Хå��ؿ���ƤӽФ���ǽ����ġ�
 *
 *  SIGIO �����ʥ�ˤ�ꥳ����Хå��ؿ���¹Ԥ����������ˤϡ�SIGIO 
 *  ���Υ��٥�ȥ֥��å����Ѱդ������� callback �ե�����ɤ˥�����Х�
 *  ���ؿ���arg �ե�����ɤ˥�����Хå��ؿ����Ϥ����������ꤷ��
 *  eneuque_sigioeb ���Ѥ��� SIGIO ���Υ��٥�ȥ��塼����Ͽ���롥
 *
 *  �ƤӽФ��줿������Хå��ؿ��� 0 ���֤��ȡ���Ϣ���� SIGIO ���Υ���
 *  ��ȥ֥��å� �ϥ��塼����Ͽ���줿�ޤޤȤʤꡤ³�� SIGIO �����ʥ��
 *  �Ƥ�Ʊ������ ��Хå��ؿ����ƤӽФ���롥������Хå��ؿ��� 0 �ʳ�
 *  ���֤��ȡ�SIGIO ���Υ��٥�ȥ֥��å��ϥ��塼���������졤������Х�
 *  ���ؿ��Ϥ���ʹ߸ƤӽФ���ʤ��ʤ롥
 */

#ifndef	_LINUX_SIGIO_
/*
 *  SIGIO ���Υ��٥�ȥ֥��å������
 */
typedef BOOL	(*SIGIO_CBACK)(VP);	/* SIGIO ������Хå��ؿ��η� */

typedef struct bsd_sigio_event_block {
	VP		queue[2];	/* SIGIO ���Υ��٥�ȥ��塼���ꥢ */
	SIGIO_CBACK	callback;	/* SIGIO ������Хå��ؿ� */
	VP		arg;		/* ������Хå��ؿ����Ϥ����� */
} SIGIOEB;

/*
 *  SIGIO ���Υ��٥�ȥ֥��å�����Ͽ
 */
extern ER	enqueue_sigioeb(SIGIOEB *sigioeb);

/*
 *  �����ƥ൯ư���� SIGIO ���Υ��٥�ȥ֥��å�����Ͽ
 */
extern ER	enqueue_sigioeb_initialize(SIGIOEB *sigioeb);

/*
 *   �Υ�֥��å���I/O �⥸�塼�뵯ư�롼����
 */

extern void linux_sigio_initialize(VP_INT exinf);

/*
 *  ����ߥϥ�ɥ�Υ٥����ֹ�
 */
#define	INHNO_SIGIO	SIGIO

/*
 *  SIGIO�����ߥϥ�ɥ�
 */

extern void linux_sigio_handler();
    
/*
 * SIGIO������������
 */
#define LINUX_SIGIO_PRIORITY      2
#define LINUX_SIGIO_STACK_SIZE 1024

extern void linux_sigio_task(void);

#endif /* _LINUX_SIGIO_ */


