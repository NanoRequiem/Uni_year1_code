#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int b;
  int c;
} DoubleNumb;

typedef struct
{
  char *magic_number[2];
  int width, height;
  int maxGray;
} Image;


int main(int argc, char const *argv[]) {
  DoubleNumb r;
  Image I;
  I.width = 1;
  r.b = 1;
  r.c = 2;

  printf("b=%d, c=%d",r.b, r.c);
  printf("width = %d", I.width);
  return 0;
}
