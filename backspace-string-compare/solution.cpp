#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
  bool backspaceCompare(string s, string t) {
    int sn = s.size();
    int tn = t.size();

    int i = sn - 1;
    int j = tn - 1;

    while (i >= 0 || j >= 0) {
      int count = 0;
      while (i >= 0) {
	if (s[i] == '#') {
	  count++;
	} else if (count > 0) {
	  count--;
	} else {
	  break;
	}
	i--;
      }
      count = 0;
      while (j >= 0) {
	if (t[j] == '#') {
	  count++;
	} else if (count > 0) {
	  count--;
	} else {
	  break;
	}
	j--;
      }
      if (i >= 0 && j >= 0 && s[i] != t[j]) {
	return false;
      } else if (i < 0 && j < 0) {
	return true;
      } else if (i >= 0 && j < 0 && s[i] != '#') {
	return false;
      } else if (i < 0 && j >= 0 && t[j] != '#') {
	return false;
      }

      i--;
      j--;
    }

    return true;
  }
};

int main() {
  Solution sol;
  bool ret;
  ret = sol.backspaceCompare(string("ab#c"), string("ad#c"));
  cout << ret << endl;
  ret = sol.backspaceCompare(string("ab##"), string("c#d#"));
  cout << ret << endl;
  ret = sol.backspaceCompare(string("a#c"), string("b"));
  cout << ret << endl;
  ret = sol.backspaceCompare(string("xywrrmp"), string("xywrrmu#p")); // true
  cout << ret << endl;
  ret = sol.backspaceCompare(string("xywrrmp"), string("xywrrmp"));   // true
  cout << ret << endl;
  ret = sol.backspaceCompare(string("xywrrmu#p"), string("xywrrmp")); // true
  cout << ret << endl;
  ret = sol.backspaceCompare(string("nzp#o#g"), string("b#nzp#o#g")); // true
  cout << ret << endl;
  ret = sol.backspaceCompare(string("nzp#o#g"), string("b#nzp#o#g")); // true
  cout << ret << endl;
  ret = sol.backspaceCompare(string(""), string("")); // true
  cout << ret << endl;
  return 0;
}
