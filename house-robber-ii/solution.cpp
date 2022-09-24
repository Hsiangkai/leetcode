#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

class Solution {
private:
    map<int, int> _dict;
    int rob_internal(vector<int> &nums, int begin) {
      if (begin >= nums.size())
	return 0;

      if (_dict.find(begin) != _dict.end())
	return _dict[begin];

      int ret;
      if (begin == nums.size() - 1)
	ret = nums[begin] + rob_internal(nums, begin + 2);
      else
        ret = max(nums[begin] + rob_internal(nums, begin + 2),
	          nums[begin + 1] + rob_internal(nums, begin + 3));

      _dict[begin] = ret;
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
      _dict.clear();
      int with_zero = nums[0] + rob_internal(with_zero_house, 0);
      _dict.clear();
      int without_zero = rob_internal(without_zero_house, 0);
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
