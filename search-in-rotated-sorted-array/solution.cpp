#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  int search(vector<int>& nums, int target) {
    int n = nums.size();
    int begin = 0;
    int end = n - 1;
    int mid = (begin + end) / 2;
    int left_most_number = nums[0];

    while (begin <= end) {
      if (nums[mid] >= left_most_number) {
	if (nums[mid] == target)
	  return mid;
	else if (target > nums[mid])
	  begin = mid + 1;
	else if (target < nums[mid]) {
	  if (target >= left_most_number)
	    end = mid - 1;
	  else
	    begin = mid + 1;
	}
      } else if (nums[mid] < left_most_number) { // nums[mid] < left_most_number
        if (nums[mid] == target)
	  return mid;
	else if (target > nums[mid]) {
	  if (target < left_most_number)
	    begin = mid + 1;
	  else
	    end = mid - 1;
	} else if (target < nums[mid]) {
	  end = mid - 1;
	}
      }
      mid = (begin + end) / 2;
    }

    return -1;
  }
};

int main() {
  Solution sol;
  int ret;
  vector<int> data1 {4,5,6,7,0,1,2};
  ret = sol.search(data1, 0);
  cout << ret << endl;
  ret = sol.search(data1, 3);
  cout << ret << endl;
  vector<int> data2 {1};
  ret = sol.search(data2, 0);
  cout << ret << endl;
  return 0;
}
