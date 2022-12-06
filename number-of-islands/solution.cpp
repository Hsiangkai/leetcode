#include <vector>
#include <iostream>

using namespace std;

class Solution {
  private:
    const vector<vector<int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    void dfs(vector<vector<char>>& grid, int x, int y, int row, int col,
	vector<vector<bool>> &visited) {

      visited[x][y] = true;

      for (auto dir : directions) {
	int new_x = x + dir[0];
	int new_y = y + dir[1];

	if (new_x >= 0 && new_x < row && new_y >=0 && new_y < col &&
	    grid[new_x][new_y] == '1' && visited[new_x][new_y] == false) {
	  dfs(grid, new_x, new_y, row, col, visited);
	}
      }
    }

  public:
    int numIslands(vector<vector<char>>& grid) {
      int row = grid.size();
      int col = grid[0].size();

      vector<vector<bool>> visited(row, vector<bool>(col, false));
      int num_of_island = 0;
      for (int i = 0; i < row; ++i) {
	for (int j = 0; j < col; ++j) {
	  if (visited[i][j] == false && grid[i][j] == '1') {
	    dfs(grid, i, j, row, col, visited);
	    num_of_island++;
	  }
	}
      }

      return num_of_island;
    }
};

int main() {
  Solution sol;
  int ret;
  vector<vector<char>> input1 {
      {'1','1','0','0','0'},
      {'1','1','0','0','0'},
      {'0','0','1','0','0'},
      {'0','0','0','1','1'}};
  ret = sol.numIslands(input1);
  cout << ret << endl;

  vector<vector<char>> input2 {
      {'1','1','1','1','0'},
      {'1','1','0','1','0'},
      {'1','1','0','0','0'},
      {'0','0','0','0','0'}};
  ret = sol.numIslands(input2);
  cout << ret << endl;

  return 0;
}
