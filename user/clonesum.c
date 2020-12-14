#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

long sum = 0;

int
runner(void *args)
{
  for(uint64 i = 0; i < 100; i++)
    sum++;
  exit(0);
}

int
main(int argc, char *argv[])
{

  for(int i = 0; i < 100; i++)
    clone(runner, (void *)0);
  for(int i = 0; i < 100; i++)
    wait(0);

  printf("sum should be %d\n", 100 * 100);
  printf("thread sum is %d\n", sum);
  exit(0);
}