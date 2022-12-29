#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
    int original_n = original.size();
    if (m * n != original_n)
      return {};

    vector<vector<int>> ret(m, vector<int>(n, 0));
    for (int i = 0, row = 0, col = 0; i < original_n; i++, col++) {
      ret[row][col] = original[i];
      if (col + 1 == n) {
	row++;
	col = -1;
      }
    }

    return ret;
  }
};

void print(vector<vector<int>> &data) {
  for (auto row : data) {
    for (auto d : row) {
      cout << d << " ";
    }
    cout << endl;
  }
  cout << endl;
}

int main() {
  Solution sol;
  vector<vector<int>> ret;
  vector<int> data1 {1, 2, 3, 4};
  ret = sol.construct2DArray(data1, 2, 2);
  print(ret);
  return 0;
}
