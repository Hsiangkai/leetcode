#include <vector>
#include <iostream>

using namespace std;

class Solution {
  vector<vector<int>> impl(vector<int>& nums, int size) {
    vector<vector<int>> ret;
    if (size == 1) {
      ret.push_back(vector<int>{});
      ret.push_back(vector<int>{nums[0]});
      return ret;
    }
    ret = impl(nums, size - 1);
    int last_num = nums[size-1];
    int n = ret.size();
    for (int i = 0; i < n; ++i) {
      vector<int> new_vec(ret[i].begin(), ret[i].end());
      new_vec.push_back(last_num);
      ret.push_back(new_vec);
    }
    return ret;
  }
public:
  vector<vector<int>> subsets(vector<int>& nums) {
    return impl(nums, nums.size());
  }
};

void print(vector<vector<int>> &data) {
  cout << "solution:" << endl;
  for (auto &vec : data) {
    for (auto &num : vec) {
      cout << num << " ";
    }
    cout << endl;
  }
  cout << endl;
}

int main() {
  Solution sol;
  vector<vector<int>> ret;
  vector<int> data1 {1};
  ret = sol.subsets(data1);
  print(ret);
  vector<int> data2 {1, 2};
  ret = sol.subsets(data2);
  print(ret);
  vector<int> data3 {1, 2, 3};
  ret = sol.subsets(data3);
  print(ret);
  return 0;
}
