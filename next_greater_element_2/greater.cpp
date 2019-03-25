#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
  vector<int> nextGreaterIndex;

  void init(vector<int>& nums) {
    nextGreaterIndex.resize(nums.size());
    int current_val = nums.back();
    bool found = false;
    for (unsigned i = 0; i < nums.size() - 1; ++i) {
      if (nums[i] > current_val) {
	nextGreaterIndex[nums.size()-1] = i;
	found = true;
	break;
      }
    }

    if (!found)
      nextGreaterIndex[nums.size()-1] = -1;
  }

  void build_index(vector<int>& nums) {

    for (int i = nums.size() - 2; i >= 0; --i) {
      bool found = false;
      for (int j = i + 1, count = 0; count < nums.size() - 1; ++count) {
	if (nums[i] < nums[j]) {
	  nextGreaterIndex[i] = j;
	  found = true;
	  break;
	} else if (i < j && nums[i] == nums[j]) {
	  nextGreaterIndex[i] = nextGreaterIndex[j];
	  found = true;
	  break;
	} else {
	  if (i < j && nums[i] < nums[nextGreaterIndex[j]]) {
	    nextGreaterIndex[i] = nextGreaterIndex[j];
	    found = true;
	    break;
	  }
	}

	if (j == (nums.size() - 1))
	  j = 0;
	else
	  ++j;
      }

      if (!found)
	nextGreaterIndex[i] = -1;
    }
  }

public:
  vector<int> nextGreaterElements(vector<int>& nums) {
    vector<int> greater_nums;

    if (nums.size() == 0)
      return greater_nums;
    else if (nums.size() == 1) {
      greater_nums.push_back(-1);
      return greater_nums;
    }

    init(nums);
    build_index(nums);

    for (int i = 0; i < nums.size(); ++i) {
      if (nextGreaterIndex[i] != -1) {
        greater_nums.push_back(nums[nextGreaterIndex[i]]);
      } else {
	greater_nums.push_back(-1);
      }
    }

    return greater_nums;
  }
};

int main() {
  //vector<int> test = {1, 1, 1, 1, 1};
  //vector<int> test = {1, 2, 1};
  vector<int> test = {1, 2, 3, 2, 1};
  Solution sol;
  vector<int> result = sol.nextGreaterElements(test);
  for (auto i : result) {
    cout << i << " ";
  }
  cout << endl;

  return 0;
}
