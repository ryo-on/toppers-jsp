;
;  TOPPERS/JSP Kernel
;      Toyohashi Open Platform for Embedded Real-Time Systems/
;      Just Standard Profile Kernel
;
;  Copyright (C) 2000-2004 by Embedded and Real-Time Systems Laboratory
;                              Toyohashi Univ. of Technology, JAPAN
;  Copyright (C) 2001-2007 by Industrial Technology Institute,
;                              Miyagi Prefectural Government, JAPAN
;  Copyright (C) 2001-2004 by Dep. of Computer Science and Engineering
;                   Tomakomai National College of Technology, JAPAN
;
;  �嵭����Ԥϡ��ʲ��� (1)��(4) �ξ�狼��Free Software Foundation
;  �ˤ�äƸ�ɽ����Ƥ��� GNU General Public License �� Version 2 �˵�
;  �Ҥ���Ƥ���������������˸¤ꡤ�ܥ��եȥ��������ܥ��եȥ�����
;  ����Ѥ�����Τ�ޤࡥ�ʲ�Ʊ���ˤ���ѡ�ʣ�������ѡ������ۡʰʲ���
;  ���ѤȸƤ֡ˤ��뤳�Ȥ�̵���ǵ������롥
;  (1) �ܥ��եȥ������򥽡��������ɤη������Ѥ�����ˤϡ��嵭������
;      ��ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ��꤬�����Τޤޤη��ǥ���
;      ����������˴ޤޤ�Ƥ��뤳�ȡ�
;  (2) �ܥ��եȥ������򡤥饤�֥������ʤɡ�¾�Υ��եȥ�������ȯ�˻�
;      �ѤǤ�����Ǻ����ۤ�����ˤϡ������ۤ�ȼ���ɥ�����ȡ�����
;      �ԥޥ˥奢��ʤɡˤˡ��嵭�����ɽ�����������Ѿ�浪��Ӳ���
;      ��̵�ݾڵ����Ǻܤ��뤳�ȡ�
;  (3) �ܥ��եȥ������򡤵�����Ȥ߹���ʤɡ�¾�Υ��եȥ�������ȯ�˻�
;      �ѤǤ��ʤ����Ǻ����ۤ�����ˤϡ����Τ����줫�ξ�����������
;      �ȡ�
;    (a) �����ۤ�ȼ���ɥ�����ȡ����Ѽԥޥ˥奢��ʤɡˤˡ��嵭����
;        �ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ����Ǻܤ��뤳�ȡ�
;    (b) �����ۤη��֤��̤�������ˡ�ˤ�äơ�TOPPERS�ץ��������Ȥ�
;        ��𤹤뤳�ȡ�
;  (4) �ܥ��եȥ����������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������뤤���ʤ�»
;      ������⡤�嵭����Ԥ����TOPPERS�ץ��������Ȥ����դ��뤳�ȡ�
;
;  �ܥ��եȥ������ϡ�̵�ݾڤ��󶡤���Ƥ����ΤǤ��롥�嵭����Ԥ�
;  ���TOPPERS�ץ��������Ȥϡ��ܥ��եȥ������˴ؤ��ơ�����Ŭ�Ѳ�ǽ����
;  �ޤ�ơ������ʤ��ݾڤ�Ԥ�ʤ����ޤ����ܥ��եȥ����������Ѥˤ��ľ
;  ��Ū�ޤ��ϴ���Ū�������������ʤ�»���˴ؤ��Ƥ⡤������Ǥ�����ʤ���
;
;  @(#) $Id: cpu_rename.inc,v 1.2 2007/03/23 07:59:26 honda Exp $
;

 .AIFDEF _CPU_RENAME_INC_
 .AELSE

_CPU_RENAME_INC_: .DEFINE ""


;
;������ܥ�Υ�͡���
;

;
;��������
;

;�������ѿ�
_runtsk:                .DEFINE         "__kernel_runtsk"
_schedtsk:              .DEFINE         "__kernel_schedtsk"
_reqflg:                .DEFINE         "__kernel_reqflg"
_enadsp:                .DEFINE         "__kernel_enadsp"
;�������ؿ�
_call_texrtn            .DEFINE         "__kernel_call_texrtn"

;
;��cpu_config.c
;

;�������ѿ�
_intnest:               .DEFINE         "__kernel_intnest"
_iscpulocked:           .DEFINE         "__kernel_iscpulocked"
_task_intmask:          .DEFINE         "__kernel_task_intmask"
;�������ؿ�
_cpu_experr:            .DEFINE         "__kernel_cpu_experr"

;
;��cpu_support.src
;

;�������ؿ�
_dispatch:              .DEFINE         "__kernel_dispatch"
_exit_and_dispatch:     .DEFINE         "__kernel_exit_and_dispatch"
_activate_r:            .DEFINE         "__kernel_activate_r"
_no_reg_exception       .DEFINE         "__kernel_no_reg_exception"
_current_ccr            .DEFINE         "__kernel_current_ccr"
_set_ccr                .DEFINE         "__kernel_set_ccr"
_current_exr            .DEFINE         "__kernel_current_exr"
_set_exr                .DEFINE         "__kernel_set_exr"
;��������¾
_common_interrupt_process .DEFINE       "__kernel_common_interrupt_process"

;
;��start.src
;
start                   .DEFINE         "__kernel_start"
_clear_b_section        .DEFINE         "__kernel_clear_b_section"

 .AENDI ;  _CPU_RENAME_INC_