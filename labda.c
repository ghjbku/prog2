#include<stdio.h>
#include<math.h>

#define SZEL 80  
#define MAG 24

int putX(x,y)
{
int ix,iy;

for(ix=0;ix<x;ix++)
printf("\n");

for(iy=0;iy<y;iy++)
printf(" ");

printf("O\n");

return 0;
}

int main()
{
long int x=0,y=0;

while(1)
{
system("clear");
putX(abs(MAG-(x++%(MAG*2))),abs(SZEL-(y++%(SZEL*2))));
usleep(15000);
}

return 0;
} 

