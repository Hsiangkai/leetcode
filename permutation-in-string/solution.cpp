#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  bool checkInclusion(string s1, string s2) {
    vector<int> counts(26, 0);
    for (auto c : s1) {
      counts[c - 'a']++;
    }

    int n = s2.size();
    bool found = false;
    int left = 0;
    for (int i = 0; i < n; ++i) {
      int pos = s2[i] - 'a';
      if (counts[pos] == 0) {
	counts[s2[left] - 'a']++;
	left++;
	i--;
      } else {
	counts[pos]--;
	// check counts
	found = true;
	for (int j = 0; j < 26; ++j) {
	  if (counts[j] != 0) {
	    found = false;
	    break;
	  }
	}
	if (found == true)
	  break;
      }
    }

    return found;
  }
};

int main() {
  Solution sol;
  bool ret;
  ret = sol.checkInclusion("ab", "eidbaooo");
  cout << ret << endl;
  ret = sol.checkInclusion("ab", "eidboaoo");
  cout << ret << endl;
  ret = sol.checkInclusion("adc", "dcda");
  cout << ret << endl;

  return 0;
}
