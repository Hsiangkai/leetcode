#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

class Solution {
private:
  int impl(vector<int> &nums, map<int, int> &dict, int end) {
    if (end < 0)
      return 0;

    if (end == 0)
      return nums[0];
    if (end == 1)
      return max(nums[0], nums[1]);

    if (dict.find(end) != dict.end())
      return dict[end];

    int ret = max(nums[end] + impl(nums, dict, end - 2),
	          impl(nums, dict, end - 1));

    dict[end] = ret;
    return ret;
  }

public:
  int rob(vector<int>& nums) {
    if (nums.size() == 0)
      return 0;
    if (nums.size() == 1)
      return nums[0];
    if (nums.size() == 2)
      return max(nums[0], nums[1]);

    vector<int> with_zero_house(nums.begin() + 2, nums.end() - 1);
    vector<int> without_zero_house(nums.begin() + 1, nums.end());
    map<int, int> dict_zero;
    int with_zero = nums[0] + impl(with_zero_house, dict_zero, with_zero_house.size() - 1);
    map<int, int> dict_no_zero;
    int without_zero = impl(without_zero_house, dict_no_zero, without_zero_house.size() - 1);

    return max(with_zero, without_zero);
  }
};

int main() {
  Solution sol;
  int ans;
  // vector<int> input1 {1, 2, 3, 1};
  // ans = sol.rob(input1);
  // cout << ans << endl;
  // vector<int> input2 {2, 7, 9, 3, 1};
  // ans = sol.rob(input2);
  // cout << ans << endl;
  // vector<int> input3 {2, 3, 2};
  // ans = sol.rob(input3);
  // cout << ans << endl;
  // vector<int> input4 {1, 2, 3};
  // ans = sol.rob(input4);
  // cout << ans << endl;
  // vector<int> input5 {0};
  // ans = sol.rob(input5);
  // cout << ans << endl;
  // vector<int> input6 {3, 1};
  // ans = sol.rob(input6);
  // cout << ans << endl;
  vector<int> input7 {1, 2, 1, 1};
  ans = sol.rob(input7);
  cout << ans << endl;
  return 0;
}
