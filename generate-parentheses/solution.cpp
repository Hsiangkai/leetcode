#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
private:
  void generate(vector<string> &results, string &answer, int n, int left_n) {
    if (n == 0 && left_n == 0) {
      results.push_back(answer);
      return;
    }

    if (left_n == 0 && n > left_n) {
      // There is no left parenthesis. Put one.
      answer += "(";
      generate(results, answer, n, left_n + 1);
      answer.erase(answer.end() - 1);
    } else {
      if (n > left_n) {
        // put '('
        answer += "(";
        generate(results, answer, n, left_n + 1);
        answer.erase(answer.end() - 1);
      }

      // or put ')'
      answer += ")";
      generate(results, answer, n - 1, left_n - 1);
      answer.erase(answer.end() - 1);
    }
  }

public:
  vector<string> generateParenthesis(int n) {
    vector<string> results;
    string answer;
    generate(results, answer, n, 0);

    return results;
  }
};

void print(vector<string> &data) {
  for (auto &s : data) {
    cout << s << " ";
  }
  cout << endl;
}

int main() {
  Solution sol;
  vector<string> ret;
  ret = sol.generateParenthesis(3);
  print(ret);
  ret = sol.generateParenthesis(2);
  print(ret);
  ret = sol.generateParenthesis(1);
  print(ret);
  return 0;
}
