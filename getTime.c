#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdint.h>

#define BILLION 1000000000L

int main(void)
{
  uint64_t diff_printf, diff_write;
  struct timespec start, end;

  int len = strlen("Test string");

  clock_gettime(CLOCK_MONOTONIC, &start);
  for (int i = 0; i < 3000000; i++) {
    write(1, "Test string\n", len+1);
    // puts("Test string");
  }
  clock_gettime(CLOCK_MONOTONIC, &end);

  diff_write = BILLION * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;

  clock_gettime(CLOCK_MONOTONIC, &start);
  for (int i = 0; i < 3000000; i++) {
    printf("Test string\n");
  }
  clock_gettime(CLOCK_MONOTONIC, &end);

  diff_printf = BILLION * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;

  printf("\n\n");
  printf("printf: %llu nanoseconds\n", (long long unsigned int) diff_printf);
  printf("write: %llu nanoseconds\n", (long long unsigned int)diff_write);
}