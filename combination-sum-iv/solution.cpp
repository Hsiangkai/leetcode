#include <vector>
#include <map>
#include <iostream>

using namespace std;

class Solution {
private:
  int impl(vector<int> &nums, int target, map<int, int> &dp) {
    if (target < 0)
      return 0;
    if (target == 0)
      return 1;

    if (dp.find(target) != dp.end())
      return dp[target];

    int n = nums.size();
    int count = 0;
    for (int i = 0; i < n; ++i) {
      int ret = impl(nums, target - nums[i], dp);
      count += ret;
    }

    dp[target] = count;
    return count;
  }

public:
  int combinationSum4(vector<int>& nums, int target) {
    map<int, int> dp;
    return impl(nums, target, dp);
  }
};

int main() {
  Solution sol;
  int ret;
  vector<int> data1 {1, 2, 3};
  ret = sol.combinationSum4(data1, 4);
  cout << ret << endl;
  vector<int> data2 {9};
  ret = sol.combinationSum4(data2, 3);
  cout << ret << endl;
  vector<int> data3 {1, 2, 3};
  ret = sol.combinationSum4(data3, 32);
  cout << ret << endl;
  return 0;
}
