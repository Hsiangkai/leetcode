#include <vector>
#include <iostream>

using namespace std;

class Solution {
private:
  void combine_impl(vector<vector<int>> &results, vector<int> &nums, vector<int> &combination,
                    int n, int k, int start) {
    if (combination.size() == k) {
      results.push_back(combination);
      return;
    }

    for (int i = start; i < n; ++i) {
      combination.push_back(nums[i]);
      combine_impl(results, nums, combination, n, k, i + 1);
      combination.pop_back();
    }
  }

public:
  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> results;
    vector<int> nums;
    vector<int> combination;
    for (int i = 1; i <= n; ++i) {
      nums.push_back(i);
    }
    combine_impl(results, nums, combination, n, k, 0);

    return results;
  }
};

void print(vector<vector<int>> & data) {
  for (auto &vec : data) {
    for (auto &d : vec) {
      cout << d << " ";
    }
    cout << endl;
  }
  cout << endl;
}

int main() {
  Solution sol;
  vector<vector<int>> ret;
  ret = sol.combine(1, 1);
  print(ret);
  ret = sol.combine(2, 1);
  print(ret);
  ret = sol.combine(4, 2);
  print(ret);
}
