#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int *y, int *x)
{
  int t = *y;
  *y = *x;
  *x = t;
}

void main()
{
  int x = 3;
  int y = 4;
  printf("x = %i and y = %i\n", x, y);
  swap(&y, &x);
  printf("x = %i and y = %i\n", x, y);
}
