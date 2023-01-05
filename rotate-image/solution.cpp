#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  void rotate(vector<vector<int>>& matrix) {
    int left_boundary = 0;
    int right_boundary = matrix.size() - 1;

    vector<int> backup;
    while (left_boundary < right_boundary) {
      vector<int> &current_row = matrix[left_boundary];
      backup.assign(current_row.begin() + left_boundary, current_row.begin() + right_boundary);

      for (int i = 0; i < right_boundary - left_boundary; ++i) {
        // copy column left_boundary to row left_boundary
	matrix[left_boundary][left_boundary + i] = matrix[right_boundary - i][left_boundary];
        // copy row right_boundary to column left_boundary
	matrix[right_boundary - i][left_boundary] = matrix[right_boundary][right_boundary - i];
        // copy col right_boundary to row right_boundary
	matrix[right_boundary][right_boundary - i] = matrix[left_boundary + i][right_boundary];
        // copy backup to col right_boundary
	matrix[left_boundary + i][right_boundary] = backup[i];
      }

      left_boundary++;
      right_boundary--;
    }
  }
};

void print(vector<vector<int>>& matrix) {
  for (int i = 0; i < matrix.size(); ++i) {
    for (int j = 0; j < matrix[0].size(); ++j) {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

int main() {
  Solution sol;
  vector<vector<int>> data1{{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
  sol.rotate(data1);
  print(data1);
  return 0;
}
