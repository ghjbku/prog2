#include <time.h>
#include <stdio.h>

void
delay (unsigned long long loops)
{
  for (unsigned long long i = 0; i < loops; i++);
}

int
main (void)
{
        unsigned int the_Bit = 1;
	int length = 0;
  unsigned long long loops_per_sec = 1;
  unsigned long long ticks;

  printf ("Calibrating delay loop..");
  fflush (stdout);

  while ((loops_per_sec <<= 1))
  {
    ticks = clock ();
    delay (loops_per_sec);
    ticks = clock () - ticks;

    if (ticks >= CLOCKS_PER_SEC)
                    {
	    loops_per_sec = (loops_per_sec / ticks) * CLOCKS_PER_SEC;

	    printf ("ok - %llu.%02llu BogoMIPS\n", loops_per_sec / 500000,
		  (loops_per_sec / 5000) % 100);

	do
		length++;
	while((the_Bit <<= 1));

	printf("A szóhossz mérete: %u\n", length);

	    return 0;}
   }
	
  printf ("failed\n");
  return -1;
}
