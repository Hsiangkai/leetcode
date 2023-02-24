class Solution {
private:
  void kthToRowCol(int k, int &row, int &col, int n) {
    col = k % n;
    row = k / n;
  }

public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int row_n = matrix.size();
    int col_n = matrix[0].size();
    int begin = 0;
    int end = row_n * col_n - 1;
    int mid = (begin + end) / 2;

    while (begin <= end) {
      int row;
      int col;
      kthToRowCol(mid, row, col, col_n);
      if (matrix[row][col] == target)
	return true;
      else if (matrix[row][col] < target)
	begin = mid + 1;
      else if (matrix[row][col] > target)
	end = mid - 1;

      mid = (begin + end) / 2;
    }

    return false;
  }
};
