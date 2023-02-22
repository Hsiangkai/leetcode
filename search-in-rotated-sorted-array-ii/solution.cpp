#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  bool search(vector<int>& nums, int target) {
    int n = nums.size();
    int begin = 0;
    int end = n - 1;
    int left_most_number = nums[0];
    int mid = (begin + end) / 2;

    if (target == left_most_number)
      return true;

    while (begin <= end) {
      if (nums[mid] > left_most_number) {
	if (target == nums[mid]) {
	  return true;
	} else if (target > nums[mid]) {
	  begin = mid + 1;
	} else { // target < nums[mid]
	  if (target > left_most_number) {
	    end = mid - 1;
	  } else if (target < left_most_number) {
	    begin = mid + 1;
	  }
	}
      } else if (nums[mid] < left_most_number) {
	if (target == nums[mid]) {
	  return true;
	} else if (target < nums[mid]) {
	  end = mid - 1;
	} else { // target > nums[mid]
	  if (target > left_most_number) {
	    end = mid - 1;
	  } else if (target < left_most_number) {
	    begin = mid + 1;
	  }
	}
      } else { // nums[mid] == left_most_number
	for (int i = begin; i <= end; ++i) {
	  if (nums[i] == target)
	    return true;
	}
	return false;
      }
      mid = (begin + end) / 2;
    }

    return false;
  }
};

int main() {
  Solution sol;
  bool ret;
  vector<int> data1 {2,5,6,0,0,1,2};
  // ret = sol.search(data1, 0);
  // cout << ret << endl;
  ret = sol.search(data1, 3);
  cout << ret << endl;

  return 0;
}
