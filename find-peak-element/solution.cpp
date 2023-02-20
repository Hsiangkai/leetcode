#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  int findPeakElement(vector<int>& nums) {
    int n = nums.size();
    int begin = 0;
    int end = n - 1;

    if (n == 1)
      return 0;
    if (n == 2)
      return nums[0] > nums[1] ? 0 : 1;

    int mid;
    while (begin <= end) {
      mid = (begin + end) / 2;
      if (mid == 0) {
	if (nums[1] < nums[0])
	  return 0;
	else
	  return 1;
      } else if (mid == n - 1) {
	return n - 1;
      } else if (nums[mid - 1] < nums[mid]) {
	if (nums[mid] > nums[mid + 1])
	  break;
	else
	  begin = mid + 1;
      } else if (nums[mid - 1] > nums[mid]) {
	end = mid - 1;
      } else if (nums[mid - 1] == nums[mid]) {
	if (nums[mid] > nums[mid + 1]) {
	  end = mid - 1;
	} else {
	  begin = mid + 1;
	}
      }
    }

    return mid;
  }
};

int main() {
  Solution sol;
  int ret;
  vector<int> data1 {1, 2, 3, 1};
  ret = sol.findPeakElement(data1);
  cout << ret << endl;
  vector<int> data2 {6,5,4,3,2,3,2};
  ret = sol.findPeakElement(data2);
  cout << ret << endl;
  vector<int> data3 {1, 2, 3, 4};
  ret = sol.findPeakElement(data3);
  cout << ret << endl;
  return 0;
}
