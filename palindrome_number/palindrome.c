#include <stdio.h>
#include <stdbool.h>

bool isPalindrome(int x) {
  int reverse = 0;
  int input = x;
  int digit;

  if (x < 0)
    return false;

  while (x) {
    digit = x % 10;
    reverse = reverse * 10 + digit;
    x = x / 10;
  }

  if (reverse == input)
    return true;

  return false;
}

int main()
{
  if (isPalindrome (1234321))
    printf ("palindrome\n");
  else
    printf ("not palindrome\n");

  return 0;
}
