#include <stdlib.h>
#include <stdio.h>

int *alloc_1d(int cols)
{
  int *new_arr = malloc(cols * sizeof(int));
  return new_arr;
}

void alloc_id_example(void)
{
  int *my_array = alloc_1d(12);

  my_array[8] = 3490;

  // The same array access could be made with pointer arithmetic:
  *(my_array + 8) = 3490;

  // By the C spec, the array notation and pointer arithmetic notation
  // are 100% equivalent.

  printf("my_array[8] = %d\n", my_array[8]);

  free(my_array);
}

int main(void)
{
  alloc_id_example();
  return 0;
}