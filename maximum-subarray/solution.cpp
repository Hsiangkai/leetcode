#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  int maxSubArray(vector<int>& nums) {
    if (nums.size() == 0)
      return 0;

    int subsum = nums[0];
    int maximum = nums[0];
    int n = nums.size();
    for (int i = 1; i < n; ++i) {
      subsum = subsum < 0 ? nums[i] : nums[i] + subsum;
      if (subsum > maximum)
	maximum = subsum;
    }

    return maximum;
  }
};

int main() {
  Solution sol;
  int ret;
  vector<int> data1 {-2,1,-3,4,-1,2,1,-5,4};
  ret = sol.maxSubArray(data1);
  cout << ret << endl;
  return 0;
}
