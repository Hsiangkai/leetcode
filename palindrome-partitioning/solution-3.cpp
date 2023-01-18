#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution {
private:
    bool isPalindrome(string &s, int start, int end) {
      // 3, 5 => n = 2
      // 3, 6 => n = 3
      int n = (end - start) / 2;
      for (auto i = 0; i <= n; ++i) {
	if (s[start+i] != s[end-i]) {
	  return false;
	}
      }
      return true;
    }

    vector<vector<string>> impl(string &s, map<string, vector<vector<string>>> &dp) {
      vector<vector<string>> results;
      int slen = s.length();
      if (slen == 0) {
	return results;
      }

      if (dp.find(s) != dp.end())
	return dp[s];

      for (int i = 1; i <= slen; ++i) {
	if (isPalindrome(s, slen - i, slen - 1)) {
	  string s_head = s.substr(0, slen - i);
	  string s_tail = s.substr(slen - i, i);
	  if (s_head.length() == 0) {
	    results.push_back(vector<string>{s_tail});
	  } else {
            vector<vector<string>> ret;
	    ret = impl(s_head, dp);
	    for (auto &item : ret) {
	      item.push_back(s_tail);
	    }
	    results.insert(results.end(), ret.begin(), ret.end());
	  }
	}
      }
      dp[s] = results;

      return results;
    }

public:
    vector<vector<string>> partition(string s) {
      map<string, vector<vector<string>>> dp;
      return impl(s, dp);
    }
};

void print_answer(vector<vector<string>> answer) {
  cout << "answer: " << endl;
  for (auto row : answer) {
    for (auto s : row) {
      cout << s << " ";
    }
    cout << endl;
  }
}

int main() {
  vector<vector<string>> ans;
  Solution sol;
  ans = sol.partition("aab");
  print_answer(ans);
  ans = sol.partition("sss");
  print_answer(ans);
  ans = sol.partition("a");
  print_answer(ans);
  ans = sol.partition("ssssssssssssss");
  print_answer(ans);
  return 0;
}

