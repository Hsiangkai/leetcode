#include <string>
#include <unordered_set>
#include <map>
#include <iostream>

using namespace std;

class Solution {
private:
  void init() {
    for (int i = 1; i <= 26; ++i) {
      dict.insert(std::to_string(i));
    }
  }

  int impl(string s, map<string, int> &dp) {
    if (s.empty())
      return 1;

    if (dp.find(s) != dp.end())
      return dp[s];

    int n = s.length();
    int count = 0;
    for (int len = 1; len <= n; ++len) {
      int start = n - len;
      string substr = s.substr(start, len);
      if (dict.find(substr) != dict.end()) {
	count += impl(s.substr(0, start), dp);
      }
    }

    dp[s] = count;
    return count;
  }

  unordered_set<string> dict;

public:
  Solution() { init(); }

  int numDecodings(string s) {
    map<string, int> dp;
    return impl(s, dp);
  }
};

int main() {
  Solution sol;
  int ret;
  // ret = sol.numDecodings("12");
  // cout << ret << endl;
  // ret = sol.numDecodings("226");
  // cout << ret << endl;
  ret = sol.numDecodings("1123");
  cout << ret << endl;
  return 0;
}
