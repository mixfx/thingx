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

	typedef int (*AddFunc)(int,int); //���Ͷ��壬��ӦDLL ADD������Func�Զ��壬���д�� 
	HINSTANCE hInstLibrary; 
	AddFunc _AddFunc; //��ӳ�� 
	CLEI()
	{
		//��ʼ����DLL�����м��㡣 
		hInstLibrary = LoadLibrary(L"ThingShare.dll");//��д�õ�DLL�ļ����ڴ���Ŀ���ɵ�Ŀ¼�� 
		if (hInstLibrary == NULL) 
		{ 
		FreeLibrary(hInstLibrary);//��Դ�ͷ� 
		}else{ 
		} 
		//���÷��������ط�������� 
		_AddFunc = (AddFunc)GetProcAddress(hInstLibrary, "Add"); 
	}

DECLARE_REGISTRY_RESOURCEID(IDR_LEI)


BEGIN_COM_MAP(CLEI)
	COM_INTERFACE_ENTRY(ILEI)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IConnectionPointContainer)
	COM_INTERFACE_ENTRY(IObjectWithSite)
	//����һ��һ�У���ȫ��ʾ�����--���������������ʱ��������ʾ��ȫ���⡣ 
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
