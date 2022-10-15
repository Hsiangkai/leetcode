#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
  int findMinArrowShots(vector<vector<int>>& points) {
    sort(points.begin(), points.end());
    int inter_begin = points[0][0];
    int inter_end = points[0][1];
    int arrows = 1;
    for (int i = 1; i < points.size(); ++i) {
      if (points[i][0] > inter_end) {
	arrows++;
	inter_begin = points[i][0];
	inter_end = points[i][1];
      } else if (inter_begin <= points[i][0] && points[i][0] <= inter_end) {
	inter_begin = points[i][0];
	inter_end = min(inter_end, points[i][1]);
      }
    }
    return arrows;
  }
};

int main() {
  Solution sol;
  int ans;
  vector<vector<int>> test2 {
      {10, 16},
      {2, 8},
      {1, 6},
      {7, 12}};
  ans = sol.findMinArrowShots(test2);
  cout << ans << endl;
  vector<vector<int>> test3 {
      {1, 2},
      {3, 4},
      {5, 6},
      {7, 8}};
  ans = sol.findMinArrowShots(test3);
  cout << ans << endl;
  vector<vector<int>> test1 {
      {1, 2},
      {2, 3},
      {3, 4},
      {4, 5}};
  ans = sol.findMinArrowShots(test1);
  cout << ans << endl;

  return 0;
}
