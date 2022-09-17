#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

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

public:
    vector<vector<string>> partition(string s) {
      int n = s.length();
      using value_type = vector<vector<string>>;
      vector<vector<value_type>> answer(n, vector<value_type>(n));

      for (auto i = 0; i < n; ++i) {
	answer[i][i].push_back({{s[i]}});
      }

      for (auto length = 1; length < n; ++length) {
	for (auto start = 0; start < n - length; ++start) {
	  // fill in answer[start][start+length]
	  value_type &current_value = answer[start][start+length];
	  for (auto j = start; j < start + length; ++j) {
	    // answer[start][start+length] = answer[start][j] + answer[j][start+length]
	    for (auto s : answer[start][j]) {
	      for (auto t : answer[j+1][start+length]) {
	        vector<string> sub_answer;
	        sub_answer.insert(sub_answer.end(), s.begin(), s.end());
		sub_answer.insert(sub_answer.end(), t.begin(), t.end());
		if (find(current_value.begin(), current_value.end(), sub_answer)
		    == current_value.end())
	          current_value.push_back(sub_answer);
	      }
	    }
	  }
	  if (isPalindrome(s, start, start+length)) {
	    current_value.push_back(vector<string>(1, s.substr(start, length+1)));
	  }
	}
      }

      return answer[0][n-1];
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
  ans = sol.partition("ssssssssssssss");
  print_answer(ans);
  return 0;
}
