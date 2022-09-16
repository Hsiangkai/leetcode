#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
      int height = triangle.size();

      for (auto i = 1; i < height; ++i) {
	triangle[i][0] += triangle[i-1][0];
	for (auto j = 1; j < i; ++j) {
	  int a = triangle[i-1][j-1];
	  int b = triangle[i-1][j];
	  triangle[i][j] += (a < b) ? a : b;
	}
	triangle[i][i] += triangle[i-1][i-1];
      }

      return *min_element(triangle[height-1].begin(), triangle[height-1].end());
    }
};

int main() {
  Solution sol;
  vector<vector<int>> test {
    {2},
    {3, 4},
    {6, 5, 7},
    {4, 1, 8, 3},
  };
  int ans = sol.minimumTotal(test);
  cout << ans << endl;

  vector<vector<int>> test2 {
    {-10},
  };
  ans = sol.minimumTotal(test2);
  cout << ans << endl;
  return 0;
}
