#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

long sum = 0;

int
runner(void *args)
{
  for(uint64 i = 0; i < 100; i++) {
    long s = sum;
    for(int k = 0; k < 1000; k++)
      ;
    sum = s + 1;
  }

  exit(0);
}

int
main(int argc, char *argv[])
{
  int procs_count;
  for(procs_count = 0; procs_count < 100; procs_count++)
    if(clone(runner, (void *)0) < 0)
      break;
  for(int i = 0; i < procs_count; i++)
    wait(0);

  printf("sum should be %d\n", 100 * procs_count);
  printf("thread sum is %d\n", sum);
  exit(0);
}