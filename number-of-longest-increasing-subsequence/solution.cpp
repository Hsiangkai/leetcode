#include <vector>
#include <utility>
#include <iostream>

using namespace std;

class Solution {
public:
  int findNumberOfLIS(vector<int>& nums) {
    int n = nums.size();
    // pair: (LIS length ending at i, 
    vector<pair<int, int>> dp(n, {1, 1});

    int max_len = 0;
    int res;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
	if (nums[j] < nums[i]) {
	  if (dp[i].first < dp[j].first + 1) {
	    dp[i] = {dp[j].first + 1, dp[j].second};
	  } else if (dp[i].first == dp[j].first + 1) {
	    dp[i].second += dp[j].second;
	  }
	}
      }

      if (dp[i].first == max_len) {
	res += dp[i].second;
      } else if (dp[i].first > max_len) {
	max_len = dp[i].first;
	res = dp[i].second;
      }
    }

    return res;
  }
};

int main() {
  Solution sol;
  int ret;
  vector<int> data1 {1, 3, 5, 4, 7};
  ret = sol.findNumberOfLIS(data1);
  cout << ret << endl;
  vector<int> data2 {2, 2, 2, 2, 2};
  ret = sol.findNumberOfLIS(data2);
  cout << ret << endl;
  return 0;
}
