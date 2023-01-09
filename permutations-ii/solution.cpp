#include <vector>
#include <iostream>

using namespace std;

class Solution {
  void permute_impl(vector<vector<int>> &results, vector<int> &nums, vector<bool> &visited,
      vector<int> &partial) {

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
	for (int j = i+1; j < n; ++j) {
	  if (nums[j] == nums[i])
	    i++;
	}
      }
    }
  }

public:
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    sort(nums.begin(), nums.end());

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
  vector<int> data1 {1, 1, 2};
  results = sol.permuteUnique(data1);
  print(results);
  vector<int> data2 {1, 2, 3};
  results = sol.permuteUnique(data2);
  print(results);

  return 0;
}
