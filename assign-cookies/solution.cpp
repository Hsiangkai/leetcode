#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
  int findContentChildren(vector<int>& g, vector<int>& s) {
    int satisfied = 0;
    int gn = g.size();
    int sn = s.size();

    if (sn == 0)
      return 0;

    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    int current_max_cookie = sn - 1;
    for (int i = gn - 1; i >= 0; --i) {
      // child i cannot be content with.
      if (g[i] > s[current_max_cookie]) {
	continue;
      }
      satisfied++;
      current_max_cookie--;
      // all cookies are eaten
      if (current_max_cookie < 0)
	break;
    }

    return satisfied;
  }
};

int main() {
  int ans;
  Solution sol;
  vector<int> g1{1, 2, 3};
  vector<int> s1{1, 1};
  ans = sol.findContentChildren(g1, s1);
  cout << ans << endl;
  vector<int> g2{1, 2};
  vector<int> s2{1, 2, 3};
  ans = sol.findContentChildren(g2, s2);
  cout << ans << endl;
  vector<int> g3{1, 2, 3};
  vector<int> s3;
  ans = sol.findContentChildren(g3, s3);
  cout << ans << endl;
}
