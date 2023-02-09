#include <vector>
#include <iostream>

using namespace std;

class Solution {
  private:
    void dfs(vector<vector<char>>& grid, int x, int y, int row, int col,
	vector<vector<bool>> &visited) {
      int x_offset[] = {0, 0, 1, -1};
      int y_offset[] = {1, -1, 0, 0};

      for (int i = 0; i < 4; ++i) {
	int new_x = x + x_offset[i];
	int new_y = y + y_offset[i];

	if (new_x >= 0 && new_x < row && new_y >=0 && new_y < col) {
	  if (visited[new_x][new_y] == false) {
	    visited[new_x][new_y] = true;
	    if (grid[new_x][new_y] == '1') {
	      dfs(grid, new_x, new_y, row, col, visited);
	    }
	  }
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
	  if (grid[i][j] == '1' && visited[i][j] == false) {
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
