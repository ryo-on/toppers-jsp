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
 *  @(#) $Id: device.h,v 1.3 2002/04/10 11:27:26 takayuki Exp $
 */

#ifndef __DEVICE_H_
#define __DEVICE_H_

#include "resource.h"       // メイン シンボル
#include "devicemanagerCP.h"

/////////////////////////////////////////////////////////////////////////////
// CDevice
class ATL_NO_VTABLE CDevice : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CDevice, &CLSID_Device>,
	public IConnectionPointContainerImpl<CDevice>,
	public IDevice,
	public CProxy_IDeviceEvents< CDevice >
{
public:
	CDevice();
	~CDevice();

DECLARE_REGISTRY_RESOURCEID(IDR_DEVICE)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CDevice)
	COM_INTERFACE_ENTRY(IDevice)
	COM_INTERFACE_ENTRY(IConnectionPointContainer)
	COM_INTERFACE_ENTRY_IMPL(IConnectionPointContainer)
END_COM_MAP()
BEGIN_CONNECTION_POINT_MAP(CDevice)
CONNECTION_POINT_ENTRY(IID__IDeviceEvents)
END_CONNECTION_POINT_MAP()


// IDevice
public:
	STDMETHOD(RaiseInterrupt)(unsigned long inhno);
	STDMETHOD(Unmap)(unsigned long address);
	STDMETHOD(Map)(unsigned long address, unsigned long size);
	STDMETHOD(SetDeviceName)(BSTR devname);
	STDMETHOD(IsValid)(BOOL * valid);

	DeviceID DevID;
	CComBSTR DeviceName;
};

#endif //__DEVICE_H_
