#include <math.h>
#include <iostream>
#include <stdlib.h>
class polargenerator
{
public:
 bool nincstar=true;
 double tarolt;

	polargenerator()
	{
	 nincstar=true;
	}
	~polargenerator()
	{
	}
 double kovetkezo()
	{
	if(nincstar)
		{
		double a1,a2,b1,b2,c;
		
			do{
		  a1=std::rand()/(RAND_MAX + 1.0);
		  a2=std::rand()/(RAND_MAX + 1.0);
		  b1=2*a1-1;
		  b2=2*a2-1;
		  c=b1 * b1 + b2 * b2;
		          }while(c>1);
		double r=std::sqrt((-2*std::log(c))/c);
		tarolt=r*b2;
		nincstar=!nincstar;
		return r*b1;
		}
	else
		{
		nincstar=!nincstar;
		return tarolt;		
		}
	
	}

};
int main()
{
	polargenerator g;
	for(int i=0; i<10;++i)
	{
	std::cout<< g.kovetkezo()<<std::endl;
	}
}
