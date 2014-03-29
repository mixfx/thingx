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
typedef int (*AddFunc)(int,int); //定义指针函数、接口。 
typedef void (*FunctionFunc)(); 
int main() 
{ 
AddFunc _AddFunc; 
FunctionFunc _FunctionFunc; 
cout <<"---获取DLL---."<< endl; 
// L 表示使用UNICODE 字符集，要和项目的字符集保持一致。 
HINSTANCE hInstLibrary = LoadLibrary(L"F:\\ThingX\\Debug\\ThingShare.dll"); 
if (hInstLibrary == NULL) 
{ 
cout <<"Dll 加载【失败】."<< endl; 
FreeLibrary(hInstLibrary); 
}else{ 
cout <<"Dll 加载【成功】."<< endl; 
} 
_AddFunc = (AddFunc)GetProcAddress(hInstLibrary, "Add"); 
_FunctionFunc = (FunctionFunc)GetProcAddress(hInstLibrary, "Function"); 
if ((_AddFunc == NULL) || (_FunctionFunc == NULL)) 
{ 
FreeLibrary(hInstLibrary);//释放 
}else{ 
cout <<"---获取DLL函数【OK】---."<< endl; 
} 
cout << _AddFunc(1, 1) << endl; // 开始调用 
_FunctionFunc(); // 
cin.get(); // 获得焦点，这样就不会程序就不会一闪而过了。 
FreeLibrary(hInstLibrary);//调用完后，要释放内存。 
return(1); 
} 