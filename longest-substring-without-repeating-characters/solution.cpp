#include <string>
#include <set>
#include <iostream>

using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int max_len = 0;
    set<char> exists;
    int n = s.size();
    int len = 0;
    int left = 0;

    for (int i = 0; i < n; ++i) {
      char c = s[i];
      auto ret = exists.insert(c);
      if (ret.second == false) {
	max_len = max(max_len, len);
	for (; left < i; ++left, --len) {
	  exists.erase(s[left]);
	  if (s[left] == c) {
	    left++;
	    len--;
	    i--;
	    break;
	  }
	}
      } else {
	len++;
      }
    }
    max_len = max(max_len, len);

    return max_len;
  }
};

int main() {
  Solution sol;
  int ret;
  ret = sol.lengthOfLongestSubstring("abcabcbb");  // 3
  cout << ret << endl;
  ret = sol.lengthOfLongestSubstring("bbbbb");  // 1
  cout << ret << endl;
  ret = sol.lengthOfLongestSubstring("pwwkew");  // 3
  cout << ret << endl;
  ret = sol.lengthOfLongestSubstring("aab");  // 2
  cout << ret << endl;
  return 0;
}
