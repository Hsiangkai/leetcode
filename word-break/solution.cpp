#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
      int n = s.length();
      vector<vector<bool>> dp(n+1, vector<bool>(n+1, false));

      for (auto len = 1; len <= n; ++len) {
	for (auto start = 0; start <= n-len; ++start) {
	  auto end = start + len;
	  auto sub_str = s.substr(start, len);
	  if (find(wordDict.begin(), wordDict.end(), sub_str) != wordDict.end()) {
	    dp[start][end] = true;
	    continue;
	  }
	  for (auto k = start+1; k < end; ++k) {
	    if (dp[start][k] && dp[k][end]) {
	      dp[start][end] = true;
	      break;
	    }
	  }
	}
      }

      return dp[0][n];
    }
};

int main() {
  Solution sol;
  bool ans;
  string s {"leetcode"};
  vector<string> dict {"leet", "code"};
  ans = sol.wordBreak(s, dict);
  cout << ans << endl;

  string s2 {"applepenapple"};
  vector<string> dict2 {"apple", "pen"};
  ans = sol.wordBreak(s2, dict2);
  cout << ans << endl;

  string s3 {"catsandog"};
  vector<string> dict3 {"cats", "dog", "sand", "and", "cat"};
  ans = sol.wordBreak(s3, dict3);
  cout << ans << endl;
}
