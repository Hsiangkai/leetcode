#include <vector>
#include <numeric>
#include <iostream>

using namespace std;

class Solution {
public:
  int minSubArrayLen(int target, vector<int>& nums) {
    int n = nums.size();
    int sum = 0;
    int left = 0;
    int result = INT_MAX;
    for (int i = 0; i < n; ++i) {
      sum += nums[i];
      if (sum >= target) {
	while (sum >= target) {
	  sum -= nums[left];
	  left++;
	}
	result = min(result, i - left + 2);
      }
    }

    return result == INT_MAX ? 0 : result;
  }
};

int main() {
  Solution sol;
  int ret;
  vector<int> data1 {2,3,1,2,4,3};
  ret = sol.minSubArrayLen(7, data1);
  cout << ret << endl;
  vector<int> data2 {1, 4, 4};
  ret = sol.minSubArrayLen(4, data2);
  cout << ret << endl;
  return 0;
}
