#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  bool isLegalChar(char c) {
    if ('a' <= c && c <= 'z')
      return true;
    if ('A' <= c && c <= 'Z')
      return true;
    if ('0' <= c && c <= '9')
      return true;
    if (c == ' ')
      return true;
    if (c == '.')
      return true;

    return false;
  }

  void pushInStack(vector<string> &stack, int level, string &name) {
    if (stack.size() == level) {
      stack.push_back(name);
    } else {
      while (stack.size() > level) {
        stack.pop_back();
      }
      stack.push_back(name);
    }
  }

  string getPath(vector<string> &stack) {
    string path("");
    for (auto n : stack) {
      path += n;
      path += '/';
    }
    path.pop_back();

    return path;
  }

public:
  int lengthLongestPath(string input) {
    string name("");
    int level = 0;
    vector<string> s;
    string max_path("");
    for (auto c : input) {
      if (isLegalChar(c)) {
	name += c;
      } else if (c == '\n') {
	pushInStack(s, level, name);
	if (name.find('.') != string::npos) {
	  string path = getPath(s);
	  if (path.size() > max_path.size())
	    max_path = path;
	}
	name = "";
	level = 0;
      } else if (c == '\t') {
	level++;
      }
    }

    if (name != "") {
      pushInStack(s, level, name);
      if (name.find('.') != string::npos) {
        string path = getPath(s);
        if (path.size() > max_path.size())
    	  max_path = path;
      }
    }

    return max_path.size();
  }
};

int main() {
  Solution sol;
  int ret;
  string input1("dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext");
  ret = sol.lengthLongestPath(input1);
  cout << ret << endl;
  string input2("dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext");
  ret = sol.lengthLongestPath(input2);
  cout << ret << endl;
  string input3("a");
  ret = sol.lengthLongestPath(input3);
  cout << ret << endl;
}
