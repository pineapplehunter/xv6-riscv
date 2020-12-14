#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int ret = 0;

int
runner(void *args)
{

  int arg = *(int *)args;
  printf("I am a new thread and the argument was %d\n", arg);
  custom_print_pid();

  ret = arg;
  for(uint64 i = 0; i < 100000000; i++)
    ;

  exit(0);
}

int
main(int argc, char *argv[])
{

  int a = 771;
  int b = 115;
  clone(runner, (void *)&a);
  clone(runner, (void *)&b);
  for(uint64 i = 0; i < 100000000; i++)
    ;

  printf("Hello!\n");
  custom_print_pid();

  printf("return value was %d!\n", ret);

  wait(0);
  wait(0);

  for(uint64 i = 0; i < 100000000; i++)
    ;
  exit(0);
}