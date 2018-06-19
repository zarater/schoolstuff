#include <stdio.h>
#include <string.h>
#include <sys/time.h>

#define TRIALS 1000000L
#define FAST_TRIALS 1L

void crcInit(void);
char crcFast(char* message, long nBytes);
extern char crcTable[256]; 

void printTable()
{
   int i,j;
   unsigned int temp;
   printf("CRC Table:\n");
   for(i=0; i< 16; i++)
   {
      for(j=0; j< 16; j++)
      {
         temp = (unsigned char) crcTable[i*16+j];
         printf("%02X ", temp);
      }
      printf("\n");
   }

}

int main(int argc, char*argv[])
{
  unsigned char retval = 0;
  long i=0;
  struct timeval tf, ti;
  unsigned long timems=0;

  if (argc != 2)
  {
      printf("Usage: hw2 message\n");
      return 1;
  }

  gettimeofday(&ti, NULL);
  for (i = 0; i < FAST_TRIALS; i++)
  {
      crcInit();
      if (i==0) printTable();
      retval = crcFast(argv[1], strlen(argv[1]));
  }
  gettimeofday(&tf, NULL);

  timems=(tf.tv_sec*1000+tf.tv_usec/1000) - (ti.tv_sec*1000+tf.tv_usec/1000);
  printf("CRC:%X\n", retval);
printf("Iterations: %lu, TotalTime : %lu ms, IterTime : %lu us\n", i, timems, (1000*timems)/TRIALS);
  return 0;
}

