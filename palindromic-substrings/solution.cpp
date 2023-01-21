#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  int countSubstrings(string s) {
    int n = s.length();
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    int count = 0;
    for (int i = 0; i < n; ++i) {
      dp[i][i] = true;
      count++;
      if (i < n - 1 && s[i] == s[i + 1]) {
	dp[i][i + 1] = true;
	count++;
      }
    }

    for (int len = 3; len <= n; ++len) {
      for (int start = 0; start <= n - len; ++start) {
	int end = start + len - 1;
	if (dp[start + 1][end - 1] && s[start] == s[end]) {
	  dp[start][end] = true;
	  count++;
	}
      }
    }

    return count;
  }
};

int main() {
  Solution sol;
  int ret;
  ret = sol.countSubstrings("abc");
  cout << ret << endl;
  ret = sol.countSubstrings("aaa");
  cout << ret << endl;
  return 0;
}
