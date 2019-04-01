#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {

      bool minus;
      if ((denominator < 0 && numerator > 0) ||
	  (denominator > 0 && numerator < 0)) {
	minus = true;
      } else {
	minus = false;
      }

      long long denom = denominator;
      long long num = numerator;
      if (denominator < 0)
	denom = (long long)0 - denominator;
      if (numerator < 0)
	num = (long long)0 - numerator;

      string answer;
      vector<long long> quotient;
      vector<long long> remainder;
      int repi = -1;

      long long q = num / denom;
      long long r = num % denom;
      quotient.push_back(q);
      remainder.push_back(r);

      while (r != 0) {
	long long n = (long long)r * 10;
	q = n / denom;
	quotient.push_back(q);

	r = n % denom;
	// search for repetition
	auto rep = find(remainder.begin(), remainder.end(), r);
	if (rep != remainder.end()) {
	  repi = distance(remainder.begin(), rep) + 1;
	  break;
	}
	remainder.push_back(r);
      }

      if (minus)
	answer.append("-");
      if (r == 0) {
	for (int i = 0; i < quotient.size(); ++i) {
	  if (i == 1)
	    answer.append(".");
	  answer.append(to_string(quotient[i]));
	}
      } else if (repi != -1) {
	int i = 0;
	for (; i < repi; ++i) {
	  answer.append(to_string(quotient[i]));
	  if (i == 0)
	    answer.append(".");
	}
	answer.append("(");
	for (; i < quotient.size(); ++i) {
	  answer.append(to_string(quotient[i]));
	}
	answer.append(")");
      }

      return answer;
    }
};

int main()
{
  Solution sol;

  cout << sol.fractionToDecimal(-1, -2147483648) << endl;
  return 0;
}
