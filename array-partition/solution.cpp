#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
  int arrayPairSum(vector<int>& nums) {
    int sum = 0;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i += 2) {
      sum += nums[i];
    }

    return sum;
  }
};

int main() {
  Solution sol;
  int ret;
  vector<int> input1 {1, 4, 3, 2};
  ret = sol.arrayPairSum(input1);
  cout << ret << endl;
  vector<int> input2 {6, 2, 6, 5, 1, 2};
  ret = sol.arrayPairSum(input2);
  cout << ret << endl;

  return 0;
}
