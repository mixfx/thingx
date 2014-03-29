#include <iostream> 
#define DLL_EXPORT 
#include "thing.h" 
extern "C" 
{ 
// 这里主要用到 ADD 方法。 
DECLDIR int Add( int a, int b ) 
{ 
return( a + b ); 
} 
DECLDIR void Function( void ) 
{ 
std::cout << "DLL Called!" << std::endl; 
} 
} 