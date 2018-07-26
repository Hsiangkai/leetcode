#include <iostream>

using namespace std;

class Solution {
public:
  int divide(int dividend, int divisor) {
    bool minus = false;
    if (dividend < 0 && divisor > 0) {
      dividend = -dividend;
      minus = true;
    }
    if (dividend > 0 && divisor < 0) {
      divisor = -divisor;
      minus = true;
    }
    if (dividend < 0 && divisor < 0) {
      dividend = -dividend;
      divisor = -divisor;
    }

    int quotient = 0;
    int remain = dividend;
    while (remain >= divisor) {
      quotient++;
      remain -= divisor;
    }

    if (minus)
      quotient = -quotient;

    return quotient;
  }
};

int main()
{
  Solution sol;
  cout << "-7 / 3 = " << sol.divide(-7, 3) << endl;
  cout << "7 / -3 = " << sol.divide(7, -3) << endl;
  cout << "7 / 3 = " << sol.divide(7, 3) << endl;
  cout << "-7 / -3 = " << sol.divide(-7, -3) << endl;
  cout << "1 / 1 = " << sol.divide(1, 1) << endl;
}
