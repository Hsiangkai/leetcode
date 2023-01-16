#include <vector>
#include <iostream>

using namespace std;

class Solution {
  void impl(int &count, vector<int> &nums, int target, int start) {

    if (start == nums.size() && target == 0) {
      count++;
      return;
    }

    if (start < nums.size()) {
      impl(count, nums, target - nums[start], start + 1);
      impl(count, nums, target + nums[start], start + 1);
    }
  }

public:
  int findTargetSumWays(vector<int>& nums, int target) {
    int count = 0;
    impl(count, nums, target, 0);
    return count;
  }
};

int main() {
  Solution sol;
  int ret;
  vector<int> data1 {1, 1, 1, 1, 1};
  ret = sol.findTargetSumWays(data1, 3);
  cout << ret << endl;
  vector<int> data2 {1};
  ret = sol.findTargetSumWays(data2, 1);
  cout << ret << endl;
  return 0;
}
