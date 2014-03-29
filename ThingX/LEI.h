// LEI.h : Declaration of the CLEI

#pragma once
#include "resource.h"       // main symbols



#include "ThingX_i.h"
#include "_ILEIEvents_CP.h"
#include <wininet.h>



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

using namespace ATL;


// CLEI

class ATL_NO_VTABLE CLEI :
	public IObjectSafetyImpl<CLEI, INTERFACESAFE_FOR_UNTRUSTED_CALLER| INTERFACESAFE_FOR_UNTRUSTED_DATA>,
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CLEI, &CLSID_LEI>,
	public IConnectionPointContainerImpl<CLEI>,
	public CProxy_ILEIEvents<CLEI>,
	public IObjectWithSiteImpl<CLEI>,
	public IDispatchImpl<ILEI, &IID_ILEI, &LIBID_ThingXLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:

	typedef int (*AddFunc)(int,int); //类型定义，对应DLL ADD方法。Func自定义，随便写。 
	HINSTANCE hInstLibrary; 
	AddFunc _AddFunc; //类映射 
	CLEI()
	{
		//开始调用DLL，进行计算。 
		hInstLibrary = LoadLibrary(L"ThingShare.dll");//把写好的DLL文件放在此项目生成的目录下 
		if (hInstLibrary == NULL) 
		{ 
		FreeLibrary(hInstLibrary);//资源释放 
		}else{ 
		} 
		//调用方法，返回方法句柄。 
		_AddFunc = (AddFunc)GetProcAddress(hInstLibrary, "Add"); 
	}

DECLARE_REGISTRY_RESOURCEID(IDR_LEI)


BEGIN_COM_MAP(CLEI)
	COM_INTERFACE_ENTRY(ILEI)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IConnectionPointContainer)
	COM_INTERFACE_ENTRY(IObjectWithSite)
	//增加一下一行：安全提示解除，--当运行浏览器调用时，不会提示安全问题。 
	COM_INTERFACE_ENTRY(IObjectSafety)

END_COM_MAP()

BEGIN_CONNECTION_POINT_MAP(CLEI)
	CONNECTION_POINT_ENTRY(__uuidof(_ILEIEvents))
END_CONNECTION_POINT_MAP()


	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
		FreeLibrary(hInstLibrary); 
	}

public:


	CComQIPtr<IWebBrowser2, &IID_IWebBrowser2> m_spWebBrowser2;

	int GetContent(long a, long b)
	{
		return 0;
	}
	STDMETHOD(GetContent)(LONG a, LONG b, LONG* o);
	STDMETHOD(test)(LONG a, LONG* b);
};

OBJECT_ENTRY_AUTO(__uuidof(LEI), CLEI)
