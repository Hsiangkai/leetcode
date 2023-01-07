#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
private:
  vector<string> permute(string s, int length) {
    vector<string> ret;
    if (length == 1) {
      ret.push_back(s.substr(0, 1));
      if (isalpha(s[0])) {
	if (islower(s[0])) {
	  ret.emplace_back(1, toupper(s[0]));
	} else {
	  ret.emplace_back(1, tolower(s[0]));
	}
      }
      return ret;
    }
    ret = permute(s, length - 1);
    char last = s[length-1];
    if (isalpha(last)) {
      char conv;
      if (islower(last)) {
	conv = toupper(last);
      } else if (isupper(last)) {
	conv = tolower(last);
      }
      int n = ret.size();
      for (int i = 0; i < n; ++i) {
	string &str = ret[i];
	string newstr(str);
        str.append(1, last);
	ret.emplace_back(newstr.append(1, conv));
      }
    } else if (isdigit(last)) {
      for (auto &str : ret) {
        str.append(1, last);
      }
    }

    return ret;
  }

public:
  vector<string> letterCasePermutation(string s) {
    return permute(s, s.size());
  }
};

void print(vector<string> &data) {
  for (auto s : data) {
    cout << s << endl;
  }
}

int main() {
  Solution sol;
  vector<string> ret;
  ret = sol.letterCasePermutation("a");
  print(ret);
  ret = sol.letterCasePermutation("a2B");
  print(ret);
  return 0;
}
