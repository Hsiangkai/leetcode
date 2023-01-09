#include <vector>
#include <iostream>

using namespace std;

class Solution {
  void permute_impl(vector<vector<int>> &results, vector<int> & nums,
      vector<bool> &visited, vector<int> &partial) {
    int n = nums.size();

    if (partial.size() == n) {
      results.push_back(partial);
      return;
    }

    for (int i = 0; i < n; ++i) {
      if (visited[i] == false) {
        partial.push_back(nums[i]);
        visited[i] = true;
        permute_impl(results, nums, visited, partial);
        partial.pop_back();
        visited[i] = false;
      }
    }
  }

public:
  vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> results;
    vector<bool> visited(nums.size(), false);
    vector<int> partial;

    permute_impl(results, nums, visited, partial);
    return results;
  }
};

void print(vector<vector<int>> &data) {
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
  vector<vector<int>> results;
  vector<int> data1 {1, 2, 3};
  results = sol.permute(data1);
  print(results);
  vector<int> data2 {0, 1};
  results = sol.permute(data2);
  print(results);
  vector<int> data3 {1};
  results = sol.permute(data3);
  print(results);

  return 0;
}
