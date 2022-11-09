#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  // return x^2 + y^2
  int dist(vector<int> &p1, vector<int> &p2) {
    return (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
  }

public:
  bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
    vector<vector<int>> points {p1, p2, p3, p4};
    sort(points.begin(), points.end());

    return dist(points[0], points[1]) != 0 &&
      dist(points[0], points[1]) == dist(points[0], points[2]) &&
      dist(points[0], points[2]) == dist(points[2], points[3]) &&
      dist(points[2], points[3]) == dist(points[1], points[3]) &&
      dist(points[0], points[3]) == dist(points[1], points[2]);
  }
};

int main() {
  Solution sol;
  bool ret;
  vector<int> input1_p1 {0, 0};
  vector<int> input1_p2 {1, 1};
  vector<int> input1_p3 {1, 0};
  vector<int> input1_p4 {0, 1};
  ret = sol.validSquare(input1_p1, input1_p2, input1_p3, input1_p4);
  cout << ret << endl;

  vector<int> input2_p1 {0, 0};
  vector<int> input2_p2 {1, 1};
  vector<int> input2_p3 {1, 0};
  vector<int> input2_p4 {0, 12};
  ret = sol.validSquare(input2_p1, input2_p2, input2_p3, input2_p4);
  cout << ret << endl;

  vector<int> input3_p1 {1, 0};
  vector<int> input3_p2 {-1, 0};
  vector<int> input3_p3 {0, 1};
  vector<int> input3_p4 {0, -1};
  ret = sol.validSquare(input3_p1, input3_p2, input3_p3, input3_p4);
  cout << ret << endl;

  vector<int> input4_p1 {0, 0};
  vector<int> input4_p2 {0, 0};
  vector<int> input4_p3 {0, 0};
  vector<int> input4_p4 {0, 0};
  ret = sol.validSquare(input4_p1, input4_p2, input4_p3, input4_p4);
  cout << ret << endl;
  return 0;
}
