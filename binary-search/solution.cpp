#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
      int n = nums.size();
      if (n == 0)
	return -1;

      int low = 0;
      int high = n;
      while (low < high) {
	int mid = (low + high) / 2;
	if (nums[mid] == target) {
	  return mid;
	} else if (nums[mid] < target) {
	  low = mid + 1;
	} else if (nums[mid] > target) {
	  high = mid;
	}
      }

      return -1;
    }
};

int main() {
  Solution sol;
  int ret;
  vector<int> data1 {-1,0,3,5,9,12};
  ret = sol.search(data1, 9);
  cout << ret << endl;
  return 0;
}
