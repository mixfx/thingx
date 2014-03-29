#ifndef _DLLTUT_DLL_H_ 
#define _DLLTUT_DLL_H_ 
#if defined DLL_EXPORT 
#define DECLDIR __declspec(dllexport) 
#else 
#define DECLDIR __declspec(dllimport) 
#endif 
//extern "C"告诉编译器该部分可以在C/C++中使用。 
extern "C" 
{ 
DECLDIR int Add( int a, int b ); 
DECLDIR void Function( void ); 
} 
#endif 