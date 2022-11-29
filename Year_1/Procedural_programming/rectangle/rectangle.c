#include <stdio.h>
int main()
{
  int Length, Width, Area, Perimeter;

  printf("Enter the Length (m):");
  scanf("%i", &Length);
  printf("Enter the Width (m):");
  scanf("%i", &Width);

  Area = Length * Width;
  Perimeter = (Length + Width) *2;

  printf("The area of the land is %i square meters \n",Area);
  printf("The perimeter of the land is %i meters \n",Perimeter);

  return 0;
}
