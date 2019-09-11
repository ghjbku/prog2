#include "std_lib_facilities.h"   

int main()
{
unsigned long long int i = 1;
int s=0;
while ((i <<= 1))
 { 
i <<=1;
//cout << i;
s=s+1;

 }
 
 cout << "\nA szó hossza: "<< s << "\n";
}

