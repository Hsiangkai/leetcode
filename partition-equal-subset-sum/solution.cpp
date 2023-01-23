#include <vector>
#include <map>
#include <iostream>

using namespace std;

class Solution {
private:
  bool canSum(vector<int> &nums, int target) {
    vector<bool> prev(target + 1, false);
    vector<bool> curr(target + 1, false);

    prev[0] = curr[0] = true;
    if (target >= nums[0])
      prev[nums[0]] = true;

    int n = nums.size();
    for (int i = 1; i < n; ++i) {
      for (int j = 0; j <= target; ++j) {
	bool without_num_i = prev[j];
	bool with_num_i = false;
	if (j >= nums[i])
	  with_num_i = prev[j - nums[i]];
	curr[j] = without_num_i | with_num_i;
      }

      prev = curr;
    }

    return prev[target];
  }

public:
  bool canPartition(vector<int>& nums) {
    int n = nums.size();
    if (n == 1)
      return false;

    int sum = 0;
    for (auto &num : nums) {
      sum += num;
    }
    if (sum % 2)
      return false;
    return canSum(nums, sum / 2);
  }
};

int main() {
  Solution sol;
  bool ret;
  vector<int> data1 {1, 5, 11, 5};
  ret = sol.canPartition(data1);
  cout << ret << endl;
  vector<int> data2 {1, 2, 3, 5};
  ret = sol.canPartition(data2);
  cout << ret << endl;
  vector<int> data3 {100};
  ret = sol.canPartition(data3);
  cout << ret << endl;
  vector<int> data4 {99, 1};
  ret = sol.canPartition(data4);
  cout << ret << endl;
  return 0;
}
