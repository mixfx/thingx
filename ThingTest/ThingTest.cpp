// ThingTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{



	return 0;
}

#include <iostream> 
#include <windows.h> 
using namespace std; 
typedef int (*AddFunc)(int,int); //����ָ�뺯�����ӿڡ� 
typedef void (*FunctionFunc)(); 
int main() 
{ 
AddFunc _AddFunc; 
FunctionFunc _FunctionFunc; 
cout <<"---��ȡDLL---."<< endl; 
// L ��ʾʹ��UNICODE �ַ�����Ҫ����Ŀ���ַ�������һ�¡� 
HINSTANCE hInstLibrary = LoadLibrary(L"F:\\ThingX\\Debug\\ThingShare.dll"); 
if (hInstLibrary == NULL) 
{ 
cout <<"Dll ���ء�ʧ�ܡ�."<< endl; 
FreeLibrary(hInstLibrary); 
}else{ 
cout <<"Dll ���ء��ɹ���."<< endl; 
} 
_AddFunc = (AddFunc)GetProcAddress(hInstLibrary, "Add"); 
_FunctionFunc = (FunctionFunc)GetProcAddress(hInstLibrary, "Function"); 
if ((_AddFunc == NULL) || (_FunctionFunc == NULL)) 
{ 
FreeLibrary(hInstLibrary);//�ͷ� 
}else{ 
cout <<"---��ȡDLL������OK��---."<< endl; 
} 
cout << _AddFunc(1, 1) << endl; // ��ʼ���� 
_FunctionFunc(); // 
cin.get(); // ��ý��㣬�����Ͳ������Ͳ���һ�������ˡ� 
FreeLibrary(hInstLibrary);//�������Ҫ�ͷ��ڴ档 
return(1); 
} 