#include <queue>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    vector<vector<int>> ret;

    auto comp = [&](int i, int j) {
      return (points[i][0] * points[i][0] + points[i][1] * points[i][1]) >
             (points[j][0] * points[j][0] + points[j][1] * points[j][1]);
    };

    priority_queue<int, vector<int>, decltype(comp)> pq(comp);

    int n = points.size();
    for (int i = 0; i < n; ++i) {
      pq.push(i);
    }

    while (k) {
      int index = pq.top();
      pq.pop();
      ret.emplace_back(vector<int>{points[index][0], points[index][1]});
      k--;
    }

    return ret;
  }
};

void print(vector<vector<int>> &points) {
  for (auto &point : points) {
    cout << "(" << point[0] << ", " << point[1] << "), ";
  }
  cout << endl;
}

int main() {
  Solution sol;
  vector<vector<int>> ret;
  vector<vector<int>> data1 {{1,3},{-2,2}};
  ret = sol.kClosest(data1, 1);
  print(ret);
  vector<vector<int>> data2 {{3,3},{5,-1},{-2,4}};
  ret = sol.kClosest(data2, 2);
  print(ret);
  return 0;
}
