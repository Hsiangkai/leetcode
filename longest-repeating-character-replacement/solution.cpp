#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
  int characterReplacement(string s, int k) {
    if (s.size() == 0)
      return 0;

    int n = s.size();
    int left;
    char current;
    int len;
    int count;
    int max_len = 1;
    for (int a = 0; a <= k; a++) {
      left = a;
      current = s[left];
      len = a + 1;
      count = k - a;
      for (int i = a + 1; i < n; ++i) {
        if (s[i] != current) {
          if (count == 0) {
            max_len = max(max_len, len);
	    break;
          } else
            count--;
        }
        len++;
      }
      max_len = max(max_len, len);
    }

    left = 0;
    current = s[left];
    len = 1;
    count = k;
    for (int i = 1; i < n; ++i) {
      if (s[i] != current) {
        if (count == 0) {
          max_len = max(max_len, len);
          for (int j = left; j <= i; ++j) {
            if (s[j] != current) {
              left = j;
              current = s[left];
              len = 0;
              count = k;
              i = j;
              break;
            }
          }
        } else
          count--;
      }
      len++;
    }

    max_len = max(max_len, min(len + count, n));

    return max_len;
  }
};

int main() {
  Solution sol;
  int ret;
  ret = sol.characterReplacement("ABAB", 2);  // 4
  cout << ret << endl;
  ret = sol.characterReplacement("AABABBA", 1);  // 4
  cout << ret << endl;
  ret = sol.characterReplacement("ABAA", 0);  // 2
  cout << ret << endl;
  ret = sol.characterReplacement("ABBB", 2);  // 4
  cout << ret << endl;
  ret = sol.characterReplacement("KRSCDCSONAJNHLBMDQGIFCPEKPOHQIHLTDIQGEKLRLCQNBOHNDQGHJPNDQPERNFSSSRDEQLFPCCCARFMDLHADJADAGNNSBNCJQOF", 4);  // 7
  cout << ret << endl;
  ret = sol.characterReplacement("ABCCCCC", 2);  // 7
  cout << ret << endl;
  ret = sol.characterReplacement("AAAAABBBBCBB", 4);  // 10
  cout << ret << endl;

  return 0;
}
