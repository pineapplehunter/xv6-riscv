#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  char *hello = "Hello World!\n";
  write(1, hello, strlen(hello));
  exit(0);
}