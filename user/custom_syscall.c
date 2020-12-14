#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  int ret;

  printf("=====================\n");
  printf("custom_print\n");
  ret = custom_print();
  printf("%d\n", ret);

  printf("=====================\n");
  printf("custom_print_int\n");
  ret = custom_print_int(12345);
  printf("%d\n", ret);

  printf("=====================\n");
  printf("custom_print_pid\n");
  ret = custom_print_pid();
  printf("%d\n", ret);

  printf("=====================\n");
  printf("custom_print_str\n");
  char *hello = "Hello, using system call!\n";
  ret = custom_print_str(hello, strlen(hello));
  printf("%d\n", ret);

  exit(0);
}
