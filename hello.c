#include <stdio.h>

int main (int argc, char *argv[])
{
  int number;
  printf("Enter a number: ");
  scanf("%d", &number);
  printf("cube of number is: %d \n", number*number*number);
  return 0;
}
