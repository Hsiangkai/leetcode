#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  int missingNumber(vector<int>& nums) {
    int n = nums.size();
    vector<bool> found(n + 1, false);

    for (int i = 0; i < n; ++i) {
      found[nums[i]] = true;
    }

    for (int i = 0; i < n + 1; ++i) {
      if (found[i] == false)
	return i;
    }

    return -1;
  }
};

int main() {
  Solution sol;
  int ret;
  vector<int> data1 {0, 1};
  ret = sol.missingNumber(data1);
  cout << ret << endl;
  return 0;
}
