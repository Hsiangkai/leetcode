#include <stdio.h>
#include <limits.h>

static int reverse (int x)
{
  int minus = 0;
  int converted = 0;
  int digit;

  if (x < 0) {
    minus = 1;
    x = -x;
  }

  /* 123 => 321 */
  while (x) {
    digit = x % 10;

    /* overflow detection */
    /* (converted * 10 + digit) > INT_MAX
     * => converted > (INT_MAX - digit) / 10
     * */
    if (converted > (INT_MAX - digit) / 10)
      return 0;

    converted = converted * 10 + digit;
    x = x / 10;
  }

  if (minus == 1) {
    converted = -converted;
  }

  return converted;
}

int main (void)
{
  int answer = reverse (-123);
  printf ("answer: %d\n", answer);

  answer = reverse (1534236469);
  printf ("answer: %d\n", answer);

  return 0;
}
