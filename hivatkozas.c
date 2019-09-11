#include <stdio.h>

int main()
{
	 int inline asdfunc(int a)
	{
	int b = a*a;
	a=b*a;
	return a;
	}

asdfunc(5);
return 0;
}
