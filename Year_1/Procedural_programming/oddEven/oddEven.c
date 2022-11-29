#include <stdio.h>

int main()
{
  int userInput;
  printf("Enter a number: ");
  scanf("%i", &userInput);

  if(userInput % 2 == 0)
  {
    printf("%i is even!\n", userInput);
  }
  else
  {
    printf("%i is not even\n", userInput);
  }
}
