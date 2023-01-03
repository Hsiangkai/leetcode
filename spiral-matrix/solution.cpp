#include <vector>
#include <iostream>

using namespace std;

class Solution {
  enum dir {
    RIGHT,
    DOWN,
    LEFT,
    UP,
  };
public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int n = matrix.size() * matrix[0].size();
    int i = 0;
    int row_min = -1;
    int col_min = -1;
    int row_max = matrix.size();
    int col_max = matrix[0].size();
    vector<int> ret;
    int row = 0;
    int col = 0;
    int dir = RIGHT;
    while (i < n) {
      ret.push_back(matrix[row][col]);
      switch (dir) {
	case RIGHT:
	  col++;
	  break;
	case DOWN:
	  row++;
	  break;
	case LEFT:
	  col--;
	  break;
	case UP:
	  row--;
	  break;
      }
      if (col == col_max) {
	dir = DOWN;
	col--;
	row++;
	row_min++;
      } else if (col == col_min) {
	dir = UP;
	col++;
	row--;
	row_max--;
      } else if (row == row_max) {
	dir = LEFT;
	row--;
	col--;
	col_max--;
      } else if (row == row_min) {
	dir = RIGHT;
	row++;
	col++;
	col_min++;
      }
      i++;
    }

    return ret;
  }
};

void print(vector<int>& data) {
  for (int i = 0; i < data.size(); ++i) {
    cout << data[i] << " ";
  }
  cout << endl;
}

int main() {
  Solution sol;
  vector<int> ret;
  vector<vector<int>> data1 {{1,2,3},{4,5,6},{7,8,9}};
  ret = sol.spiralOrder(data1);
  print(ret);
  vector<vector<int>> data2 {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
  ret = sol.spiralOrder(data2);
  print(ret);
  return 0;
}
