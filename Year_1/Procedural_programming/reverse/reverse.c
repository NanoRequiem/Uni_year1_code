#include <stdio.h>
int main()
{
  int a[10];
  int n; int i;
  printf("How many numbers are there in the sequence?");
  scanf("%i", &n);
  // read the senquence
  printf("Enter the sequence:");
  for(i = 0 ; i < n ; i++)
    scanf("%i" , &a[i]);
  // print sequence backwards
  for (i = n-1 ; i >= 0 ; i--)
    printf("%i , " , a[i]); // notice the space before and after the comma in the format string
  return 0;
}
