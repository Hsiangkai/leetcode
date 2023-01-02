#include <set>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  vector<int> findDuplicates(vector<int>& nums) {
    int n = nums.size();
    set<int> duplicated;
    for (int i = 0; i < n; ++i) {
      int expected_pos = nums[i] - 1;
      if (expected_pos != i) {
	if (nums[i] == nums[expected_pos])
	  duplicated.insert(nums[i]);
	else {
	  swap(nums[i], nums[expected_pos]);
	  i--;
	}
      }
    }
    vector<int> answer(duplicated.begin(), duplicated.end());
    return answer;
  }
};

void print(vector<int> &data) {
  for (int d : data) {
    cout << d << " ";
  }
  cout << endl;
}

int main() {
  Solution sol;
  vector<int> ret;
  vector<int> data1 {4,3,2,7,8,2,3,1};
  ret = sol.findDuplicates(data1);
  print(ret);

  return 0;
}
