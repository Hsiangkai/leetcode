#include <vector>
#include <stack>
#include <iostream>

using namespace std;

class Solution {
public:
  int findUnsortedSubarray(vector<int>& nums) {
    int n = nums.size();
    int sorted_min_index = n;
    int sorted_max_index = -1;
    stack<int> buffer;

    buffer.push(0);
    for (int i = 1; i < n; ++i) {
      if (sorted_min_index == n && nums[i] >= nums[buffer.top()]) {
	buffer.push(i);
      } else {
	while (buffer.size() && nums[i] < nums[buffer.top()])
	  buffer.pop();
	if (buffer.size())
	  sorted_min_index = buffer.top();
	else
	  sorted_min_index = -1;
      }
    }

    if (sorted_min_index == n)
      return 0;

    while (buffer.size())
      buffer.pop();

    buffer.push(n - 1);
    for (int i = n - 2; i >= 0; --i) {
      if (sorted_max_index == -1 && nums[i] <= nums[buffer.top()]) {
	buffer.push(i);
      } else {
	while (buffer.size() && nums[i] > nums[buffer.top()])
	  buffer.pop();
	if (buffer.size())
	  sorted_max_index = buffer.top();
	else
	  sorted_max_index = n;
      }
    }

    return sorted_max_index - sorted_min_index - 1;
  }
};

int main() {
  Solution sol;
  int ret;
  vector<int> input1 {2,6,4,8,10,9,15};
  ret = sol.findUnsortedSubarray(input1);
  cout << ret << endl;
  vector<int> input2 {1,2,3,4};
  ret = sol.findUnsortedSubarray(input2);
  cout << ret << endl;
  vector<int> input3 {1};
  ret = sol.findUnsortedSubarray(input3);
  cout << ret << endl;
  vector<int> input4 {2,1};
  ret = sol.findUnsortedSubarray(input4);
  cout << ret << endl;
  vector<int> input5 {1,3,5,4,2};
  ret = sol.findUnsortedSubarray(input5);
  cout << ret << endl;
  vector<int> input6 {1,5,3,2,4};
  ret = sol.findUnsortedSubarray(input6);
  cout << ret << endl;
  return 0;
}
