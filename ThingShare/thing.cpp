#include <iostream> 
#define DLL_EXPORT 
#include "thing.h" 
extern "C" 
{ 
// ������Ҫ�õ� ADD ������ 
DECLDIR int Add( int a, int b ) 
{ 
return( a + b ); 
} 
DECLDIR void Function( void ) 
{ 
std::cout << "DLL Called!" << std::endl; 
} 
} 