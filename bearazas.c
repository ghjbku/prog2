#include "stdio.h"
#include "math.h"
//#include "std_lib_facilities.h"

void kiir(vector<double> tomb){
for(int i=0;i<tomb.size();i++)
 {
 printf("PageRank [%d]: %lf\n", i, tomb[i]);
 }
}

double tavolsag(vector<double> PR, vector<double> PRv)
{
double osszeg=0.0;
 for(int i=0;i<PR.size();++i)
 {
 osszeg+= abs(PR[i]- PRv[i]);
 }
return osszeg;
}

int main(void)
{
vector<vector<double>> L=
{
{0.0,0.0,1.0 / 3.0,0.0},
{1.0,1.0 / 2.0,1.0 / 3.0,1.0},
{0.0,1.0 / 2.0,0.0,0.0},
{0.0,0.0,1.0 / 3.0,0.0}
};
vector<double> PR={0.0,0.0,0.0,0.0};
vector<double> PRv={1.0 / 4.0,1.0 / 4.0,1.0 / 4.0,1.0 / 4.0};

int i,j;
 for(;;)
 { 
  for(i=0;i<4;++i)
  PR[i]=PRv[i];
 for (i=0;i<4;i++)
 { 
  double temp=0;
  for(j=0;j<4;++j)
  temp+=L[i][j] * PR[j];
  PRv[i]=temp;
}

 if ( tavolsag(PR,PRv) < 0.0000000001)
break;
}
kiir (PR);
return 0;

} 

