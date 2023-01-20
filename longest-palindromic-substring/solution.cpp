#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  string longestPalindrome(string s) {
    int n = s.length();
    if (n == 1)
      return s;

    int max_len = 1;
    int max_start = 0;
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    for (int i = 0; i < n; ++i) {
      dp[i][i] = true;
      if (i < n - 1) {
	if (s[i] == s[i + 1]) {
	  dp[i][i + 1] = true;
	  max_len = 2;
	  max_start = i;
	}
      }
    }

    for (int len = 3; len <= n; ++len) {
      for (int start = 0; start <= n - len; ++start) {
	int end = start + len - 1;
	if (s[start] == s[end] && dp[start+1][end-1]) {
	  dp[start][end] = true;
	  if (len > max_len) {
	    max_len = len;
	    max_start = start;
	  }
	}
      }
    }

    return s.substr(max_start, max_len);
  }
};

int main() {
  Solution sol;
  string ret;
  ret = sol.longestPalindrome("babad");
  cout << ret << endl;
  ret = sol.longestPalindrome("cbbd");
  cout << ret << endl;
  return 0;
}
