#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int evalRPN(vector<string>& tokens) {
    vector<long long> stack;

    for (auto token : tokens) {
      if (token[0] == '+') {
	long long b = stack.back();
	stack.pop_back();
	long long a = stack.back();
	stack.pop_back();
	stack.push_back(a + b);
      } else if (token[0] == '-' && token.size() == 1) {
	long long b = stack.back();
	stack.pop_back();
	long long a = stack.back();
	stack.pop_back();
	stack.push_back(a - b);
      } else if (token[0] == '*') {
	long long b = stack.back();
	stack.pop_back();
	long long a = stack.back();
	stack.pop_back();
	stack.push_back(a * b);
      } else if (token[0] == '/') {
	long long b = stack.back();
	stack.pop_back();
	long long a = stack.back();
	stack.pop_back();
	stack.push_back(a / b);
      } else {
	long long number = stoi(token);
	stack.push_back(number);
      }
    }

    return (int)stack.back();
  }
};

int main() {
  Solution sol;
  int ret;
  vector<string> input1 {"2","1","+","3","*"};
  ret = sol.evalRPN(input1);
  cout << ret << endl;
  vector<string> input2 {"4","13","5","/","+"};
  ret = sol.evalRPN(input2);
  cout << ret << endl;
  vector<string> input3 {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
  ret = sol.evalRPN(input3);
  cout << ret << endl;
  return 0;
}
