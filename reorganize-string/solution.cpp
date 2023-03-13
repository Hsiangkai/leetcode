#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

class Solution {
public:
  string reorganizeString(string s) {
    vector<int> counts(26, 0);
    for (auto c : s) {
      counts[c - 'a']++;
    }

    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < 26; ++i) {
      pq.push(make_pair(counts[i], i));
    }
    int n = pq.top().first;
    vector<string> substr(n, "");

    int len = 0;
    int string_len = s.length();
    int count = 0;
    char alphabet;
    while (len < string_len) {
      pair<int, int> value;
      int i;
      for (i = 0; i < n; ++i) {
	if (count == 0 && !pq.empty()) {
          value = pq.top();
          pq.pop();
	  count = value.first;
	  alphabet = value.second + 'a';
	}

	if (count == 0)
	  break;

	substr[i] += alphabet;
	count--;
      }

      len += i;
    }

    string result;
    for (int i = 0; i < n; ++i) {
      result += substr[i];
    }
    if (string_len >= 2 && result[string_len - 1] == result[string_len - 2])
      return "";

    return result;
  }
};

int main() {
  Solution sol;
  string ret;
  ret = sol.reorganizeString("a");
  cout << ret << endl;
  ret = sol.reorganizeString("aab");
  cout << ret << endl;
  ret = sol.reorganizeString("aaab");
  cout << ret << endl;
  ret = sol.reorganizeString("vvvlo");
  cout << ret << endl;
  ret = sol.reorganizeString("snnnnbpngobwznvnnnlnwhvnnnnfjnnlnnnnnnbnknnqkndzefncknnnnnaiqrntnndnnnjninnnunnunqhndnnqnnsjqnnpiqshntnnncnvnnnncnnqenlnninyndnnnljongnnjwnnnngllnnngkbnllnnnnontlbpngjnnenqnsnnnnnjeqqghnfpngepnodnnnnnnvnsrnughbnipvnhqmnzonoonnnjotnnonoennnpnfnnkdnnbmnmnpnqninnxronnnnvnlanlnnnebnnnlnvnfknsnbincnttnmnguqenhnnxunnnntnnnnhnqnzehvunfnvnndvnjnnnbnnpxnqipwnmnonnndlnsnonnninnxnnnjnnnnnesennmyiednnnnnnnnnhimtnnnonjlicnwnwvnntaxmnrntnnnnsnbnanninnecbcfjxncnnkvnnqgnunensanpnngjnzxjnopnnyvnnxskniyytnsnnnnx");
  cout << ret << endl;
  return 0;
}
