#include <string>
#include <set>
#include <iostream>

using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
      set<char> dict;
      int n = s.length();
      int palindrome_len = 0;

      for (int i = 0; i < n; ++i) {
	if (dict.find(s[i]) == dict.end()) {
	  dict.insert(s[i]);
	} else {
	  palindrome_len += 2;
	  dict.erase(s[i]);
	}
      }

      if (dict.size() > 0)
	palindrome_len++;

      return palindrome_len;
    }
};

int main(){
  Solution sol;
  int ret;
  ret = sol.longestPalindrome("abccccdd");
  cout << ret << endl;
  ret = sol.longestPalindrome("a");
  cout << ret << endl;
  return 0;
}
