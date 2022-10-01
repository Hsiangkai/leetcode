#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
      int n = nums.size();

      if (n == 1)
	return 1;
      if (n == 2) {
	if (nums[0] != nums[1])
	  return 2;
	else
	  return 1;
      }

      int s;
      for (s = 0; s < n - 1; ++s) {
	if (nums[s] != nums[s + 1])
	  break;
      }
      if (s == n - 1)
	return 1;

      bool positive = (nums[s] < nums[s + 1]) ? true : false;
      int count = 1;
      int current = nums[s];
      for (int i = s + 1; i < n; ++i) {
	if (positive) {
	  if (nums[i] < current) {
	    positive = false;
	    current = nums[i];
	    count++;
	  } else if (nums[i] > current)
	    current = nums[i];
	} else {
	  if (nums[i] > current) {
	    positive = true;
	    current = nums[i];
	    count++;
	  } else if (nums[i] < current)
	    current = nums[i];
	}
      }

      count++;

      return count;
    }
};

int main() {
  Solution sol;
  int ret;
  vector<int> test1 {1,7,4,9,2,5};  // 6
  ret = sol.wiggleMaxLength(test1);
  cout << ret << endl;
  vector<int> test2 {1,17,5,10,13,15,10,5,16,8};  // 7
  ret = sol.wiggleMaxLength(test2);
  cout << ret << endl;
  vector<int> test3 {1,2,3,4,5,6,7,8,9};  // 2
  ret = sol.wiggleMaxLength(test3);
  cout << ret << endl;
  vector<int> test4 {0,0};  // 1
  ret = sol.wiggleMaxLength(test4);
  cout << ret << endl;
  vector<int> test5 {0,0,0};  // 1
  ret = sol.wiggleMaxLength(test5);
  cout << ret << endl;
  vector<int> test6 {1,1,7,4,9,2,5};  // 6
  ret = sol.wiggleMaxLength(test6);
  cout << ret << endl;
  vector<int> test7 {0,0,0,0,0,0};   // 1
  ret = sol.wiggleMaxLength(test7);
  cout << ret << endl;
  vector<int> test8 {1,1,1,2,2,2,1,1,1,3,3,3,2,2,2};  // 5
  ret = sol.wiggleMaxLength(test8);
  cout << ret << endl;
}
