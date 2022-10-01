#include <iostream>

using namespace std;

class Solution {
    int countSetBits(long long n) {
        if (n == 0)
            return 0;
        else
            return 1 + countSetBits(n & (n - 1));
    }

public:
    int integerReplacement(int n) {
      int count = 0;

      long long input = n;
      while (input != 1) {
	if (input & 0x1) {
	  long long add_one = input + 1;
	  long long sub_one = input - 1;
	  int add_one_bits = countSetBits(add_one);
	  int sub_one_bits = countSetBits(sub_one);

	  if ((input == 3) || (add_one_bits > sub_one_bits))
	    input = sub_one;
	  else
	    input = add_one;
	} else {
	  input = input >> 1;
	}
	count++;
      }

      return count;
    }
};

int main() {
    Solution sol;
    int ret;
    ret = sol.integerReplacement(8);  // 3
    cout << ret << endl;
    ret = sol.integerReplacement(7);  // 4
    cout << ret << endl;
    ret = sol.integerReplacement(4);  // 2
    cout << ret << endl;
    ret = sol.integerReplacement(65535);  // 17
    cout << ret << endl;
    ret = sol.integerReplacement(65536);  // 16
    cout << ret << endl;
    ret = sol.integerReplacement(3);  // 2
    cout << ret << endl;
    ret = sol.integerReplacement(100000000);   // 31
    cout << ret << endl;
    ret = sol.integerReplacement(2147483647);  // 32
    cout << ret << endl;
    return 0;
}
