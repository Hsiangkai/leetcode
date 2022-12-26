#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
      int majority;
      int count = 0;
      for (int num : nums) {
	if (count == 0) {
	  majority = num;
	}
	if (num == majority)
	  count++;
	else
	  count--;
      }

      return majority;
    }
};

int main() {
  Solution sol;
  int ret;
  vector<int> data1 {1};
  ret = sol.majorityElement(data1);
  cout << ret << endl;
  vector<int> data2 {3, 2, 3};
  ret = sol.majorityElement(data2);
  cout << ret << endl;
  return 0;
}

