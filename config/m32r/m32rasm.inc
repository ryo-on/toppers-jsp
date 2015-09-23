/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2002 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 * 
 *  �嵭����Ԥϡ�Free Software Foundation �ˤ�äƸ�ɽ����Ƥ��� 
 *  GNU General Public License �� Version 2 �˵��Ҥ���Ƥ����狼����
 *  ����(1)��(4)�ξ������������˸¤ꡤ�ܥ��եȥ��������ܥ��եȥ���
 *  ������Ѥ�����Τ�ޤࡥ�ʲ�Ʊ���ˤ���ѡ�ʣ�������ѡ������ۡʰʲ���
 *  ���ѤȸƤ֡ˤ��뤳�Ȥ�̵���ǵ������롥
 *  (1) �ܥ��եȥ������򥽡��������ɤη������Ѥ�����ˤϡ��嵭������
 *      ��ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ��꤬�����Τޤޤη��ǥ���
 *      ����������˴ޤޤ�Ƥ��뤳�ȡ�
 *  (2) �ܥ��եȥ�����������Ѳ�ǽ�ʥХ��ʥꥳ���ɡʥ���������֥륪��
 *      �������ȥե������饤�֥��ʤɡˤη������Ѥ�����ˤϡ�����
 *      ��ȼ���ɥ�����ȡ����Ѽԥޥ˥奢��ʤɡˤˡ��嵭�����ɽ����
 *      �������Ѿ�浪��Ӳ�����̵�ݾڵ����Ǻܤ��뤳�ȡ�
 *  (3) �ܥ��եȥ�������������Բ�ǽ�ʥХ��ʥꥳ���ɤη��ޤ��ϵ������
 *      �߹�����������Ѥ�����ˤϡ����Τ����줫�ξ������������ȡ�
 *    (a) ���Ѥ�ȼ���ɥ�����ȡ����Ѽԥޥ˥奢��ʤɡˤˡ��嵭������
 *        ��ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ����Ǻܤ��뤳�ȡ�
 *    (b) ���Ѥη��֤��̤�������ˡ�ˤ�äơ��嵭����Ԥ���𤹤�
 *        ���ȡ�
 *  (4) �ܥ��եȥ����������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������뤤���ʤ�»
 *      ������⡤�嵭����Ԥ����դ��뤳�ȡ�
 * 
 *  �ܥ��եȥ������ϡ�̵�ݾڤ��󶡤���Ƥ����ΤǤ��롥�嵭����Ԥϡ�
 *  �ܥ��եȥ������˴ؤ��ơ�����Ŭ�Ѳ�ǽ����ޤ�ơ������ʤ��ݾڤ�Ԥ�
 *  �ʤ����ޤ����ܥ��եȥ����������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū����������
 *  ���ʤ�»���˴ؤ��Ƥ⡤������Ǥ�����ʤ���
 * 
 *  @(#) $Id: m32rasm.inc,v 1.2 2002/04/05 09:01:40 takayuki Exp $
 */

#ifndef __M32RASM_INC
#define __M32RASM_INC

/*
 * 32�ӥå�¨�ͥ�����
 */

	.macro	lea reg, value
		seth	\reg, ((\value) >> 16)
		or3		\reg, \reg, ((\value) & 0xffff)
	.endm


/*
 * ����ߵ���
 *  �����ϤĤ֤��Ƥ⤤���쥸����
 */
	.macro	ei work=r0
		mvfc	\work, psw
		or3		\work, \work, 0x40
		mvtc	\work, psw
	.endm

/*
 * ����߶ػ�
 *  �����ϤĤ֤��Ƥ⤤���쥸����
 */
	.macro	di work=r0
		mvfc	\work, psw
		and3	\work, \work, 0xcf
		mvtc	\work, psw
	.endm

/* �������Ȳ�ǽ�ʥ���ܥ�κ��� */
	.macro Label name
		.globl \name
		\name:
	.endm

/* �ؿ�����ȥ�κ��� */
	.macro Function name
		.text
		.align 4
		.globl \name
		\name:
	.endm

/* �ؿ���������� */
	.macro rts
		jmp  r14
	.endm

/* �ؿ��ƽ� */
	.macro call \name
		st	r14,@-r15
		bl	\name
	.endm

/* �����å��Ѥ� */
	.macro stmdb regset
		.irp reg, \regset
			st	\reg, @-r15
		.endr
	.endm

/* �����å��ᤷ */
	.macro ldmia regset
		.irp reg, \regset
			ld	\reg, @r15+
		.endr
	.endm

#endif