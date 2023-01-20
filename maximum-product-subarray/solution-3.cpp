#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  int maxProduct(vector<int>& nums) {
    int n = nums.size();

    vector<vector<int>> dp (n, vector<int>(n, INT_MIN));
    int max_result = INT_MIN;
    for (int i = 0; i < n; ++i) {
      dp[i][i] = nums[i];
      if (nums[i] > max_result)
	max_result = nums[i];
    }

    for (int len = 2; len <= n; ++len) {
      for (int start = 0; start <= n - len; ++start) {
	int end = start + len - 1;
	for (int j = start; j < end; ++j) {
	  int product = dp[start][j] * dp[j+1][end];
	  if (product > dp[start][end]) {
	    dp[start][end] = product;
	    if (product > max_result)
	      max_result = product;
	  }
	}
      }
    }

    return max_result;
  }
};

int main() {
  Solution sol;
  int ret;
  vector<int> data1 {2,3,-2,4};
  ret = sol.maxProduct(data1);
  cout << ret << endl;
  vector<int> data2 {-2};
  ret = sol.maxProduct(data2);
  cout << ret << endl;
  return 0;
}
