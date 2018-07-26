#include <iostream>

using namespace std;

#define MAX_INT 2147483647

class Solution {
public:
  int divide(int dividend, int divisor) {
    bool minus = false;
    bool overflow = false;
    if (dividend < 0 && divisor > 0) {
      minus = true;
    }
    if (dividend > 0 && divisor < 0) {
      minus = true;
    }

    if (divisor == 1)
      return dividend;
    if (divisor == 2)
      return dividend >> 1;

    int quotient = 0;
    int remain = dividend;
    if (dividend > 0 && divisor > 0) {
      while (remain >= divisor) {
	quotient++;
	remain -= divisor;
      }
    } else if (dividend < 0 && divisor < 0) {
      while (remain <= divisor) {
	if (quotient == MAX_INT) {
	  overflow = true;
	  break;
	}
	quotient++;
	remain -= divisor;
      }
    } else if (dividend > 0 && divisor < 0) {
      if (divisor != -divisor) {
	while (remain >= -divisor) {
	  if (quotient == MAX_INT) {
	    overflow = true;
	    break;
	  }
	  quotient++;
	  remain += divisor;
	}
      } else {
	while (-remain <= divisor) {
	  if (quotient == MAX_INT) {
	    overflow = true;
	    break;
	  }
	  quotient++;
	  remain += divisor;
	}
      }
    } else if (dividend < 0 && divisor > 0) {
      if (divisor != -divisor) {
	while (remain <= -divisor) {
	  if (quotient == MAX_INT) {
	    overflow = true;
	    break;
	  }
	  quotient++;
	  remain += divisor;
	}
      } else {
	while (-remain >= divisor) {
	  if (quotient == MAX_INT) {
	    overflow = true;
	    break;
	  }
	  quotient++;
	  remain += divisor;
	}
      }
    }

    if (overflow)
      return MAX_INT;

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
  cout << "2147483647 / 1 = " << sol.divide(2147483647, 1) << endl;
  cout << "-2147483648 / -1 = " << sol.divide(-2147483648, -1) << endl;
  cout << "-2147483648 / -3 = " << sol.divide(-2147483648, -3) << endl;
  cout << "-2147483648 / 3 = " << sol.divide(-2147483648, 3) << endl;
  cout << "1038925803 / -2147483648 = " << sol.divide(1038925803, -2147483648) << endl;
  cout << "3 / -7 = " << 3 / -7 << endl;
}
