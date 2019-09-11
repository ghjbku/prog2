#include <stdio.h>

int main()
{
unsigned int loops_per_sec=1;
unsigned int a=0;
while (loops_per_sec <<=1){
loops_per_sec = loops_per_sec << 1;
loops_per_sec = loops_per_sec & 0xF;
printf(": %u\n",loops_per_sec);
a++;
printf(": %u\n",a);
};
return 0;
}
