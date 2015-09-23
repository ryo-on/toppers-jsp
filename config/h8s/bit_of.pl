#! /usr/bin/perl
#
#  TOPPERS/JSP Kernel
#      Toyohashi Open Platform for Embedded Real-Time Systems/
#      Just Standard Profile Kernel
# 
#  Copyright (C) 2000-2002 by Embedded and Real-Time Systems Laboratory
#                              Toyohashi Univ. of Technology, JAPAN
#  Copyright (C) 2001,2002 by Industrial Technology Institute,
#                              Miyagi Prefectural Government, JAPAN
# 
#  上記著作権者は，Free Software Foundation によって公表されている 
#  GNU General Public License の Version 2 に記述されている条件か，以
#  下の(1)〜(4)の条件を満たす場合に限り，本ソフトウェア（本ソフトウェ
#  アを改変したものを含む．以下同じ）を使用・複製・改変・再配布（以下，
#  利用と呼ぶ）することを無償で許諾する．
#  (1) 本ソフトウェアをソースコードの形で利用する場合には，上記の著作
#      権表示，この利用条件および下記の無保証規定が，そのままの形でソー
#      スコード中に含まれていること．
#  (2) 本ソフトウェアを再利用可能なバイナリコード（リロケータブルオブ
#      ジェクトファイルやライブラリなど）の形で利用する場合には，利用
#      に伴うドキュメント（利用者マニュアルなど）に，上記の著作権表示，
#      この利用条件および下記の無保証規定を掲載すること．
#  (3) 本ソフトウェアを再利用不可能なバイナリコードの形または機器に組
#      み込んだ形で利用する場合には，次のいずれかの条件を満たすこと．
#    (a) 利用に伴うドキュメント（利用者マニュアルなど）に，上記の著作
#        権表示，この利用条件および下記の無保証規定を掲載すること．
#    (b) 利用の形態を，別に定める方法によって，上記著作権者に報告する
#        こと．
#  (4) 本ソフトウェアの利用により直接的または間接的に生じるいかなる損
#      害からも，上記著作権者を免責すること．
# 
#  本ソフトウェアは，無保証で提供されているものである．上記著作権者は，
#  本ソフトウェアに関して，その適用可能性も含めて，いかなる保証も行わ
#  ない．また，本ソフトウェアの利用により直接的または間接的に生じたい
#  かなる損害に関しても，その責任を負わない．
# 
#  @(#) $Id: bit_of.pl,v 1.1 2002/04/13 13:14:45 imai Exp $
# 
#入力はそのシステムの標準の改行コードにする事！
$kwd = "";
$find = "function: *bit_field_offset_of_";
$offset = "MOV\.W +";
$bit = "BLD.B +";
while (<>){
	s/\r\n/\n/;
	chomp;
	if(/$find/){
		/$find/;
		$kwd = $';
		next;
	}
	if (($kwd ne "") && (/$offset/)){
		/$offset/;
		$num = $';
		/(\d+):.*/;
		$num = $1 - 3;
		print "$kwd:\t.DEFINE\t\"$num\"\n";
	}
	if (($kwd ne "") && (/$bit/)){
		/$bit/;
		$num = $';
		/(\d+)/;
		$num = $1;
		print "$kwd";
		print "_bit:\t.DEFINE\t\"$num\"\n";
		$kwd = "";
	}
}
