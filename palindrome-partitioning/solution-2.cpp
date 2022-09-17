#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
private:
    map<string, vector<vector<string>>> _dict;
    bool isPalindrome(string &s, int start, int end) {
      // 3, 5 => n = 1
      // 3, 6 => n = 1
      int n = (end - start) / 2;
      for (auto i = 0; i <= n; ++i) {
	if (s[start+i] != s[end-i]) {
	  return false;
	}
      }
      return true;
    }

    vector<vector<string>> partition(string s, map<string, vector<vector<string>>> &dict) {
      vector<vector<string>> ret_values;
      int n = s.length();
      if (n == 0)
	return {{""}};

      if (dict.find(s) != dict.end())
	return dict[s];

      vector<vector<string>> ret;
      for (auto i = 0; i < n; ++i) {
	if (isPalindrome(s, n - i - 1, n - 1)) {
	  ret = partition(s.substr(0, n - i - 1), dict);
	  for (auto val : ret) {
	    if (val[0].empty())
	      val[0] = s.substr(n - i - 1, i + 1);
	    else
	      val.push_back(s.substr(n - i - 1, i + 1));
	    ret_values.push_back(val);
	  }
	}
      }

      dict[s] = ret_values;
      return ret_values;
    }

public:
    vector<vector<string>> partition(string s) {
      return partition(s, _dict);
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
  ans = sol.partition("a");
  print_answer(ans);
  // ans = sol.partition("ssssssssssssss");
  // print_answer(ans);
  return 0;
}

