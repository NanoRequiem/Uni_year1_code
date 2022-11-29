include <stdio.h>

int main()
{
  int userScore;

  printf("Please inputer your score: ");
  scanf("%i\n", &userScore);

  if(userScore > 0 && userScore < 50)
  {
    printf("Sorry, you have failed\n");
  }

  else if(userScore > 49 && userScore < 60)
  {
    printf("Ok, you are not bad");
  }

  else if(userScore > 59 && userScore < 80)
  {
    printf("That is good")
  }

  else if(userScore > 79 && userScore < 90)
  {
    printf("very good");
  }

  else
  {
    printf("You are excellent")
  }



  return 0;
}
