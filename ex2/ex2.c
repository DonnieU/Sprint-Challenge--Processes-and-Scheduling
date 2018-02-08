#include <stdlib.h>
#include <stdio.h>

int **alloc_2d(int rows, int cols)
{
  int **new_arr = (int **) malloc(rows * sizeof(int *));
  
  for (int i = 0; i < rows; i++) {
    new_arr[i] = (int *) malloc(cols * sizeof(int));
  }
  return new_arr;
}

int alloc_2d_example(void)
{
  int **my_array = alloc_2d(5, 10);

  // First array index is a row, second is column:
  my_array[2][3] = 3490;
  printf("my_array[2][3] = %d\n", my_array[2][3]); // should print 3490

  // The same array access could be made with pointer arithmetic:
  *(*(my_array+2)+3) = 3491;

  // By the C spec, the array notation and pointer arithmetic notation
  // are 100% equivalent.

  printf("my_array[2][3] = %d\n", my_array[2][3]); // should print 3491

  free(my_array);
}

int main(void)
{
  alloc_2d_example();
  return 0;
}