#include <string>
#include <map>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
      map<char, int> counts;
      map<char, bool> inserted;
      int n = s.length();
      for (int i = 0; i < n; ++i) {
	if (counts.find(s[i]) == counts.end()) {
	  counts[s[i]] = 1;
	  inserted[s[i]] = false;
	} else
	  counts[s[i]]++;
      }
      stack<char> cstack;
      for (int i = 0; i < n; ++i) {
	counts[s[i]]--;
	if (inserted[s[i]])
	  continue;
	if (cstack.empty() || s[i] > cstack.top()) {
	  cstack.push(s[i]);
	  inserted[s[i]] = true;
	} else {
	  // is it necessary to reverse the order?
	  while (!cstack.empty() && s[i] < cstack.top() && counts[cstack.top()] > 0) {
	    inserted[cstack.top()] = false;
	    cstack.pop();
	  }
	  cstack.push(s[i]);
	  inserted[s[i]] = true;
	}
      }

      string ret;
      while (cstack.size()) {
	ret = cstack.top() + ret;
	cstack.pop();
      }
      return ret;
    }
};

int main() {
  Solution sol;
  string ret;
  ret = sol.removeDuplicateLetters("bcabc");
  cout << ret << endl;
  ret = sol.removeDuplicateLetters("cbacdcbc");
  cout << ret << endl;
  ret = sol.removeDuplicateLetters("cdadabcc");
  cout << ret << endl;
  ret = sol.removeDuplicateLetters("bbcaac");
  cout << ret << endl;
  return 0;
}
