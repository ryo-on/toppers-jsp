/*
 *
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
 *  @(#) $Id: start.c,v 1.1 2000/11/14 16:29:31 honda Exp $
 */ 

#include <signal.h>
#include "jsp_kernel.h"
#include "check.h"

extern void kernel_start();


int main()
{
    struct sigaltstack      ss;
    struct sigaction action;
    /*
     *  �����ʥ륹���å��򡤥ץ����������å���˼�롥
     *  BSD�Υ����ʥ�Ȱۤʤ�ss.ss_flags��SS_ONSTACK��
     *  �񤭹���Ǥ�ȿ�Ǥ���ʤ����ᡢ��������Ω����ɽ��
     *  inSigStack����Ѥ��롣
     */
    

    ss.ss_sp = (void *)(((INT) &ss) - SIGSTACK_MERGIN - SIGSTKSZ);
    ss.ss_size = SIGSTKSZ;
    ss.ss_flags = 0;
    sigaltstack(&ss, 0);

    /*
     *  �����ͥ륹�����ȥ��åץ롼����(kernel_start())
     *  ��SIGUSR1�ǵ�ư����褦�����ꤷ��raise()�ǸƤӽФ���
     *  �����å����ڤ��ؤ���ư��򳫻Ϥ��롣
     */
      action.sa_handler = kernel_start;
      action.sa_flags   =  SA_ONSTACK;
      sigfillset(&action.sa_mask);
      sigaction(SIGUSR1,&action,NULL);
      raise(SIGUSR1);
      
      
    /*
     * ��������뤳�ȤϤʤ���
     */
    return(0);
}
