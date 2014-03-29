// LEI.cpp : Implementation of CLEI

#include "stdafx.h"
#include "LEI.h"
#include "WinInet.h"
#include "atlenc.h"
#pragma comment(lib, "wininet.lib")
// CLEI



STDMETHODIMP CLEI::GetContent(LONG a, LONG b, LONG* o)
{
	// TODO: Add your implementation code here

	int sum = this->_AddFunc(static_cast<int>(a),static_cast<int>(b)); 
	*o = static_cast<LONG>(sum); 
	this->_AtlFinalRelease();
	
	return S_OK;
}


STDMETHODIMP CLEI::test(LONG a, LONG* b)
{
	// TODO: Add your implementation code here
	//int sum = this->_AddFunc(static_cast<int>(a),static_cast<int>(a)); 
	//m_spUnkSite.QueryInterface()
	*b = a+10;

	//m_spWebBrowser2 = m_spUnkSite;

	HRESULT hr;   
	if(m_spWebBrowser2 == NULL){

    CComPtr<IServiceProvider> sp;   

    hr = m_spUnkSite->QueryInterface(&sp);

	hr = sp->QueryService(IID_IWebBrowserApp, IID_IWebBrowser2, (void**)&m_spWebBrowser2); 
	}

	CComPtr<IDispatch> pDisp;
	hr = m_spWebBrowser2->get_Document(&pDisp);
	CComQIPtr<IHTMLDocument2, &IID_IHTMLDocument2> spHTML;
	spHTML = pDisp;

	CComPtr<IHTMLElement> m_pBody;
	hr = spHTML->get_body(&m_pBody);

	BSTR bstrHTMLText;
	hr = m_pBody->get_outerHTML(&bstrHTMLText);

	spHTML->put_title(CComBSTR(L"·Ç³£ºÃ"));

	//m_pBody->put_title(_T("sdfsdfsdfs"));

	//m_spWebBrowser2->get_HWND();

	MessageBoxEx(NULL,bstrHTMLText,_T("a"),0,0);
	Base64Decode(NULL,0,0,0);

	HINTERNET hInet = InternetOpen( L"cow_shit", INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, 0 );
	HINTERNET hConnect = InternetConnectW( hInet, CComBSTR(L"http://www.google.com"), 80, NULL, NULL, INTERNET_SERVICE_HTTP, 0, 0 );
    HINTERNET hRequest = HttpOpenRequestW( hConnect, L"GET", L"wechat", HTTP_VERSION, NULL, NULL, INTERNET_FLAG_KEEP_CONNECTION | INTERNET_FLAG_NO_CACHE_WRITE | INTERNET_FLAG_FORMS_SUBMIT, 0 );
	HttpAddRequestHeadersW( hRequest, L"", 0, HTTP_ADDREQ_FLAG_REPLACE );
	HttpSendRequestExW( hRequest, NULL, NULL, HSR_INITIATE, 0 );
	

	return S_OK;
}
