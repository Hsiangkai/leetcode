#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  int uniquePaths(int m, int n) {
    if (m == 1)
      return 1;

    vector<int> prev(n, 1);
    vector<int> curr(n, 0);
    
    for (int i = 1; i < m; ++i) {
      curr[0] = 1;
      for (int j = 1; j < n; ++j) {
	curr[j] = curr[j - 1] + prev[j];
      }
      prev.assign(curr.begin(), curr.end());
    }

    return prev[n - 1];
  }
};

int main() {
  Solution sol;
  int ret;
  ret = sol.uniquePaths(3, 2);
  cout << ret << endl;
}
