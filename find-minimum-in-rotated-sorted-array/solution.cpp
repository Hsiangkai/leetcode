#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  int findMin(vector<int>& nums) {
    int n = nums.size();
    if (n == 1)
      return nums[0];

    int left_most_num = nums[0];
    int right_most_num = nums[n - 1];
    if (left_most_num < right_most_num)
      return nums[0];

    int begin = 0;
    int end = n - 1;
    int mid;

    while (1) {
      mid = (begin + end) / 2;
      if (nums[mid] >= left_most_num) {
	begin = mid + 1;
      } else if (nums[mid] < left_most_num) {  // nums[mid] < left_most_num
	if (nums[mid - 1] > nums[mid])
	  break;
	end = mid - 1;
      }
    }

    return nums[mid];
  }
};

int main() {
  Solution sol;
  int ret;
  vector<int> data1 {3,4,5,1,2};  // 1
  ret = sol.findMin(data1);
  cout << ret << endl;
  vector<int> data2 {4,5,6,7,0,1,2}; // 0
  ret = sol.findMin(data2);
  cout << ret << endl;
  vector<int> data3 {11,13,15,17};  // 11
  ret = sol.findMin(data3);
  cout << ret << endl;
  vector<int> data4 {2, 1};  // 1
  ret = sol.findMin(data4);
  cout << ret << endl;
  return 0;
}
