#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
  bool containsDuplicate(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for (int i = 0; i < n - 1; ++i) {
      if (nums[i] == nums[i+1])
	return true;
    }
    return false;
  }
};

int main() {
  Solution sol;
  bool ret;
  vector<int> input1 {1,2,3,1};
  ret = sol.containsDuplicate(input1);
  cout << ret << endl;
  return 0;
}
