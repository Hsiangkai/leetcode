#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
private:
  unordered_map<char, string> telephone;
  void init() {
    telephone['2'] = "abc";
    telephone['3'] = "def";
    telephone['4'] = "ghi";
    telephone['5'] = "jkl";
    telephone['6'] = "mno";
    telephone['7'] = "pqrs";
    telephone['8'] = "tuv";
    telephone['9'] = "wxyz";
  }

  void impl(vector<string> &results, string &answer, string &digits, int pos) {
    int n = digits.length();
    if (pos == n) {
      results.push_back(answer);
      return;
    }

    char c = digits[pos];
    string &dict = telephone[c];
    int dict_len = dict.length();
    for (int i = 0; i < dict_len; ++i) {
      answer.push_back(dict[i]);
      impl(results, answer, digits, pos + 1);
      answer.pop_back();
    }
  }

public:
  Solution () { init(); }
  vector<string> letterCombinations(string digits) {
    vector<string> results;
    if (digits.length() == 0)
      return results;
    string answer;
    impl(results, answer, digits, 0);
    return results;
  }
};

void print(vector<string> &data) {
  for (auto &d : data) {
    cout << d << ", ";
  }
  cout << endl;
}

int main() {
  Solution sol;
  vector<string> ret;
  ret = sol.letterCombinations("23");
  print(ret);
  ret = sol.letterCombinations("");
  print(ret);
  ret = sol.letterCombinations("2");
  print(ret);
  return 0;
}
