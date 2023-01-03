#include <vector>
#include <set>
#include <iostream>

using namespace std;

class Solution {
public:
  void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix[0].size();
    int n = matrix.size();
    set<int> col;
    set<int> row;

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
	if (matrix[i][j] == 0) {
	  col.insert(j);
	  row.insert(i);
	}
      }
    }

    for (int i = 0; i < n; ++i) {
      for (auto c : col)
	matrix[i][c] = 0;
    }

    for (int j = 0; j < m; ++j) {
      for (auto r : row)
	matrix[r][j] = 0;
    }
  }
};

void print(vector<vector<int>> &data) {
  int m = data[0].size();
  int n = data.size();

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cout << data[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

int main() {
  Solution sol;
  vector<vector<int>> data1{{0,1,2,0},{3,4,5,2},{1,3,1,5}};
  sol.setZeroes(data1);
  print(data1);
  return 0;
}
