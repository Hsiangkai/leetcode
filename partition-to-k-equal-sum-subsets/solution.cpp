#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
private:
  bool impl(vector<int>& nums, int partial_sum, vector<bool> &visited, int target, int k, int next_index) {
    if (k == 1)
      return true;

    if (partial_sum == target)
      return impl(nums, 0, visited, target, k - 1, 0);

    for (int i = next_index; i < nums.size(); ++i) {
      if (visited[i] == false && partial_sum + nums[i] <= target) {
	visited[i] = true;
	if (impl(nums, partial_sum + nums[i], visited, target, k, i + 1))
	  return true;
	visited[i] = false;
      }
    }

    return false;
  }

public:
  bool canPartitionKSubsets(vector<int>& nums, int k) {
    int sum = 0;
    for (auto &num : nums) {
      sum += num;
    }
    int target = sum / k;
    if (target * k != sum)
      return false;

    sort(nums.begin(), nums.end(), greater<int>());
    if (nums[0] > target)
      return false;

    int n = nums.size();
    int i;
    for (i = 0; i < n; ++i) {
      if (nums[i] < target)
	break;
    }
    k -= i;
    if (k == 0)
      return true;
    nums.erase(nums.begin(), nums.begin() + i);

    n = nums.size();
    vector<bool> visited(n, false);
    return impl(nums, 0, visited, target, k, 0);
  }
};

int main() {
  Solution sol;
  bool ret;
  // vector<int> data1 {4, 3, 2, 3, 5, 2, 1};
  // ret = sol.canPartitionKSubsets(data1, 4);
  // cout << ret << endl;
  // vector<int> data2 {1, 2, 3, 4};
  // ret = sol.canPartitionKSubsets(data2, 3);
  // cout << ret << endl;
  // vector<int> data3 {1, 1, 1, 1, 2, 2, 2, 2};
  // ret = sol.canPartitionKSubsets(data3, 4);
  // cout << ret << endl;
  // vector<int> data4 {85,35,40,64,86,45,63,16,5364,110,5653,97,95};
  // ret = sol.canPartitionKSubsets(data4, 7);
  // cout << ret << endl;
  // vector<int> data5 {4,5,9,3,10,2,10,7,10,8,5,9,4,6,4,9};
  // ret = sol.canPartitionKSubsets(data5, 5); // true
  // cout << ret << endl;
  vector<int> data6 {1, 1, 1};
  ret = sol.canPartitionKSubsets(data6, 3); // true
  cout << ret << endl;
  vector<int> data7 {3,3,10,2,6,5,10,6,8,3,2,1,6,10,7,2};
  ret = sol.canPartitionKSubsets(data7, 6); // true
  cout << ret << endl;
  return 0;
}
