#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
  FILE *books;
  int c;
  char line[40];

  books = fopen ("books.txt", "r");


  while(c != EOF)
  {
    c = getc(books);
    putchar(c);
    fgets(line, 40, books);
    printf("%s", line);
  }
  return 0;
}
