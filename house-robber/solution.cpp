#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
    int rob_internal(vector<int>& nums, map<int, int> &dict, int begin) {
      if (begin >= nums.size())
	return 0;

      if (dict.find(begin) != dict.end())
	return dict[begin];

      int ret;
      if (begin == nums.size() - 1)
	ret = nums[begin] + rob_internal(nums, dict, begin + 2);
      else
        ret = max(nums[begin] + rob_internal(nums, dict, begin + 2),
	          nums[begin + 1] + rob_internal(nums, dict, begin + 3));

      dict[begin] = ret;
      return ret;
    }

public:
    int rob(vector<int>& nums) {
      map<int, int> dict;
      return rob_internal(nums, dict, 0);
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
