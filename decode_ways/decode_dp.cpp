#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
      int n = s.length();
      if (n == 0)
	return 0;
      if (s[0] == '0')
	return 0;

      vector<int> len;
      len.reserve(n + 1);
      len[0] = 1;
      len[1] = 1;
      for (int i = 2; i <= n; ++i) {
	len[i] = s[i - 1] == '0' ? 0 : len[i - 1];
	if (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6')) {
	  len[i] += len[i - 2];
	}
      }

      return len[n];
    }
};

int main() {
  string s("9355141842519423434975558424574331479338913773268525913972842463395324957127519863135646135786662832");
  //string s("12");
  Solution sol;
  int ans = sol.numDecodings(s);
  cout << ans << endl;
  return 0;
}
