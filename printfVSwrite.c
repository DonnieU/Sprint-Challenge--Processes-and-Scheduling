#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

int main(void)
{
  clock_t beg_printf, end_printf, beg_write, end_write;
  
  int len = strlen("Test string");

  beg_write = clock();
  for (int i = 0; i < 3000000; i++) {
    write(1, "Test string\n", len+1);
    // puts("Test string");
  }
  end_write = clock();

  beg_printf = clock();
  for (int i = 0; i < 3000000; i++) {
    printf("Test string\n");
  }
  end_printf = clock();

  printf("\n\n");
  // printf("printf: %lf\n", (end_printf - beg_printf)*1.0/CLOCKS_PER_SEC);
  // printf("write: %lf\n", (end_write - beg_write)*1.0/CLOCKS_PER_SEC);
  printf("printf: %ld\n", end_printf - beg_printf);
  printf("write/puts: %ld\n", end_write - beg_write);
  printf("CLOCKS_PER_SEC: %ld\n", CLOCKS_PER_SEC);
  // printf("%lf\n", clock()/CLOCKS_PER_SEC);
  return 0;
}