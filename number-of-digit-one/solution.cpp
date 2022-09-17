#include <iostream>

using namespace std;

class Solution {
public:
    int countDigitOne(int n) {
      int digit_one = 0;
      long long factor = 10;
      int pre_factor = 1;
      int pre_remainder = 1;

      while (1) {
	int quotient = n / factor;
	int remainder = n % factor;
	int ones = quotient;

	if ((remainder / pre_factor) > 1)
	  ones += 1;

	digit_one += ones * pre_factor;

	if ((remainder / pre_factor) == 1)
	  digit_one += pre_remainder;

	if (quotient == 0)
	  break;

	pre_remainder = remainder + 1;
	factor *= 10;
	pre_factor *= 10;
      }

      return digit_one;
    }
};

int main() {
  Solution sol;
  int ans;
  ans = sol.countDigitOne(0);  // 0
  cout << ans << endl;
  ans = sol.countDigitOne(1);  // 1
  cout << ans << endl;
  ans = sol.countDigitOne(11);  // 4
  cout << ans << endl;
  ans = sol.countDigitOne(21); // 13
  cout << ans << endl;
  ans = sol.countDigitOne(111); // 36
  cout << ans << endl;
  ans = sol.countDigitOne(31);  // 14
  cout << ans << endl;
  ans = sol.countDigitOne(1000000000);
  cout << ans << endl;
  return 0;
}
