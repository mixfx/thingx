#ifndef _DLLTUT_DLL_H_ 
#define _DLLTUT_DLL_H_ 
#if defined DLL_EXPORT 
#define DECLDIR __declspec(dllexport) 
#else 
#define DECLDIR __declspec(dllimport) 
#endif 
//extern "C"���߱������ò��ֿ�����C/C++��ʹ�á� 
extern "C" 
{ 
DECLDIR int Add( int a, int b ); 
DECLDIR void Function( void ); 
} 
#endif 