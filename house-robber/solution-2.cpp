#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
    int rob_internal(vector<int>& nums, map<int, int> &dict, int end) {
      if (end == 0)
	return nums[0];
      if (end == 1) {
	return max(nums[0], nums[1]);
      }

      if (dict.find(end) != dict.end())
	return dict[end];

      int ret;
      ret = max(nums[end] + rob_internal(nums, dict, end - 2),
	        rob_internal(nums, dict, end - 1));
      dict[end] = ret;
      return ret;
    }

public:
    int rob(vector<int>& nums) {
      map<int, int> dict;
      return rob_internal(nums, dict, nums.size() - 1);
    }
};

int main() {
  Solution sol;
  int ans;
  vector<int> input1 {1, 2, 3, 1};
  ans = sol.rob(input1);
  cout << ans << endl;
  vector<int> input2 {2, 7, 9, 3, 1};
  ans = sol.rob(input2);
  cout << ans << endl;
  return 0;
}
