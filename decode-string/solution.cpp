#include <string>
#include <stack>
#include <iostream>

using namespace std;

class Solution {
  void putInStack(stack<string> &str_stack, stack<int> &times_stack, string &substr, string &retstr) {
    if (times_stack.size() == 0) {
      retstr += substr;
    } else if (times_stack.size() > str_stack.size()) {
      str_stack.push(substr);
    } else if (times_stack.size() == str_stack.size()) {
      substr = str_stack.top() + substr;
      str_stack.pop();
      str_stack.push(substr);
    }
    substr = "";
  }

public:
  string decodeString(string s) {
    stack<string> str_stack;
    stack<int> times_stack;
    string ret;

    int times = 0;
    string substr = "";
    for (auto c : s) {
      if ('0' <= c && c <= '9') {
	if (substr != "")
	  putInStack(str_stack, times_stack, substr, ret);
	times = times * 10 + (c - '0');
      } else if ('a' <= c && c <= 'z') {
	substr += c;
	times = 0;
      } else if (c == '[') {
	times_stack.push(times);
	times = 0;
	if (substr != "")
	  putInStack(str_stack, times_stack, substr, ret);
      } else if (c == ']') {
	if (substr != "")
	  putInStack(str_stack, times_stack, substr, ret);
	int val = times_stack.top(); times_stack.pop();
	string str = str_stack.top(); str_stack.pop();
	string tmp = "";
	for (int i = 0; i < val; ++i)
	  tmp += str;
	putInStack(str_stack, times_stack, tmp, ret);
	times = 0;
      }
    }

    if (str_stack.size()) {
      while (str_stack.size()) {
	ret = str_stack.top() + ret;
	str_stack.pop();
      }
    }

    return ret + substr;
  }
};

int main() {
  Solution sol;
  string ret;
  ret = sol.decodeString("3[a]2[bc]");
  cout << ret << endl; // aaabcbc
  ret = sol.decodeString("3[a2[c]]");
  cout << ret << endl; // accaccacc
  ret = sol.decodeString("2[abc]3[cd]ef");
  cout << ret << endl; // abcabccdcdcdef
  ret = sol.decodeString("abcde");
  cout << ret << endl; // abcde
  ret = sol.decodeString("3[z]2[2[y]pq4[2[jk]e1[f]]]ef");
  cout << ret << endl; // zzzyypqjkjkefjkjkefjkjkefjkjkefyypqjkjkefjkjkefjkjkefjkjkefef
  ret = sol.decodeString("2[f2[e]g]i");
  cout << ret << endl; // feegfeegi
  ret = sol.decodeString("sd2[f2[e]g]i");
  cout << ret << endl; // sdfeegfeegi
  return 0;
}
