#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  vector<int> findDisappearedNumbers(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
      int c = nums[i];
      if (c == 0)
	continue;
      if (i != c - 1) {
	if (c != nums[c-1]) {
	  swap(nums[i], nums[c-1]);
	  i--;
	} else {
	  nums[i] = 0;
	}
      }
    }

    vector<int> answer;
    for (int i = 0; i < n; ++i) {
      if (nums[i] == 0) {
	answer.push_back(i+1);
      }
    }

    return answer;
  }
};

void print(vector<int> &data) {
  for (auto d : data)
    cout << d << ", ";
  cout << endl;
}

int main() {
  Solution sol;
  vector<int> ret;
  vector<int> data1 {4,3,2,7,8,2,3,1};
  ret = sol.findDisappearedNumbers(data1);
  print(ret);
  vector<int> data2 {1, 1};
  ret = sol.findDisappearedNumbers(data2);
  print(ret);
  return 0;
}
