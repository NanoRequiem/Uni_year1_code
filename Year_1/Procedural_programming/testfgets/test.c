#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  char str[20];
  int numblines = 0;

  FILE *f = fopen("lmao.txt", "r");

  if(f == NULL)
  {
    printf("error\n");
    return -1;
  }

  else
  {
    while(numblines < 5)
    {
      fgets(str, 20, f);
      printf("%s", str);
      numblines = numblines + 1;
    }
  }

  fclose(f);

  return 0;
}
