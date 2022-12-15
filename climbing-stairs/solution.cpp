#include <iostream>

using namespace std;

class Solution {
public:
  int climbStairs(int n) {
    if (n == 1)
      return 1;
    if (n == 2)
      return 2;

    int n_minus_1 = 2;
    int n_minus_2 = 1;
    int answer;
    for (int i = 3; i <= n; i++) {
      answer = n_minus_1 + n_minus_2;
      n_minus_2 = n_minus_1;
      n_minus_1 = answer;
    }

    return answer;
  }
};

int main() {
  int ret;
  Solution sol;
  ret = sol.climbStairs(2);
  cout << ret << endl;
  ret = sol.climbStairs(3);
  cout << ret << endl;
  ret = sol.climbStairs(4);
  cout << ret << endl;
}
