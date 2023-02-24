#include <string>
#include <unordered_set>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  int numDecodings(string s) {
    int n = s.size();
    if (n == 0)
      return 0;

    if (s[0] == '0')
      return 0;

    if (n == 1)
      return 1;

    vector<int> dp(n, 0);
    dp[0] = 1;

    if ('1' <= s[1] && s[1] <= '9') {
      dp[1] += dp[0];
    }
    if (s[0] == '1' || (s[0] == '2' && s[1] <= '6')) {
      dp[1] += 1;
    }
    for (int start = 2; start < n; ++start) {
      if ('1' <= s[start] && s[start] <= '9') {
	dp[start] += dp[start - 1];
      }
      if (s[start - 1] == '1' || (s[start - 1] == '2' && s[start] <= '6')) {
	dp[start] += dp[start - 2];
      }
    }

    return dp[n - 1];
  }
};

int main() {
  Solution sol;
  int ret;
  ret = sol.numDecodings("1");     // 1
  cout << ret << endl;
  ret = sol.numDecodings("12");    // 2
  cout << ret << endl;
  ret = sol.numDecodings("226");   // 3
  cout << ret << endl;
  ret = sol.numDecodings("1123");  // 5
  cout << ret << endl;
  ret = sol.numDecodings("06");    // 0
  cout << ret << endl;
  return 0;
}
