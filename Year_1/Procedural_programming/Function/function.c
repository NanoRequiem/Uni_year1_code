#include <stdio.h>
#include <math.h>

int main()
{
  float x;

  for(x = 0.0; x < 3.2; x=x+0.2)
  {
      float y = pow(x,2) + 1;
      printf ("x = %lf and y = %lf\n",x ,y);
  }

  return 0;
}
