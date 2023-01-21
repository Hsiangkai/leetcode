#include <vector>
#include <string>
#include <map>
#include <iostream>

using namespace std;

class Solution {
  bool impl(string s, vector<string> &dict, map<string, bool> &dp) {
    if (s.empty())
      return true;

    if (dp.find(s) != dp.end())
      return dp[s];

    int n = s.length();
    for (int len = 1; len <= n; ++len) {
      int start = n - len;
      string substr = s.substr(start, len);
      if (find(dict.begin(), dict.end(), substr) != dict.end()) {
	if (impl(s.substr(0, start), dict, dp)) {
	  dp[s] = true;
	  return true;
	}
      }
    }

    dp[s] = false;
    return false;
  }

public:
  bool wordBreak(string s, vector<string>& wordDict) {
    map<string, bool> dp;
    return impl(s, wordDict, dp);
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
