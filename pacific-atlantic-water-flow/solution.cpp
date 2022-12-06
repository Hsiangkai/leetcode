#include <vector>
#include <set>
#include <utility>

using namespace std;

class Solution {
  vector<vector<int>> directions {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

  void dfs(vector<vector<int>>& heights, int x, int y, set<pair<int, int>> &reach) {
    int row = heights.size();
    int col = heights[0].size();

    reach.insert(make_pair(x, y));

    for (auto dir : directions) {
      int new_x = x + dir[0];
      int new_y = y + dir[1];
      auto it = reach.find(make_pair(new_x, new_y));
      if (it != reach.end())
	continue;
      if (new_x >= 0 && new_x < row && new_y >=0 && new_y < col && heights[new_x][new_y] >= heights[x][y]) {
	dfs(heights, new_x, new_y, reach);
      }
    }
  }

  void pacific(vector<vector<int>>& heights, set<pair<int, int>> &reach) {
    int row = heights.size();
    int col = heights[0].size();

    for (int i = 0; i < row; ++i) {
      dfs(heights, i, 0, reach);
    }

    for (int j = 0; j < col; ++j) {
      dfs(heights, 0, j, reach);
    }
  }

  void atlantic(vector<vector<int>>& heights, set<pair<int, int>> &reach) {
    int row = heights.size();
    int col = heights[0].size();

    for (int i = 0; i < row; ++i) {
      dfs(heights, i, col - 1, reach);
    }

    for (int j = 0; j < col; ++j) {
      dfs(heights, row - 1, j, reach);
    }
  }

public:
  vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    set<pair<int, int>> reach1;
    set<pair<int, int>> reach2;

    pacific(heights, reach1);
    atlantic(heights, reach2);

    // intersect of reach1 and reach2
    set<pair<int, int>> reach;
    set_intersection(reach1.begin(), reach1.end(), reach2.begin(), reach2.end(),
                     std::inserter(reach, reach.begin()));

    // convert set to vector
    vector<vector<int>> solution;
    for (auto r : reach) {
      solution.push_back(vector<int>{r.first, r.second});
    }

    return solution;
  }
};

int main() {
  Solution sol;
  vector<vector<int>> input1 {{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}};
  vector<vector<int>> ret;
  ret = sol.pacificAtlantic(input1);

  return 0;
}
