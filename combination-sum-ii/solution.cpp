#include <vector>
#include <iostream>

using namespace std;

class Solution {
  void combination_impl(vector<vector<int>> &results, vector<int> &answer, vector<bool> &visited,
      vector<int> &nums, int target, int start) {

    if (target == 0) {
      results.push_back(answer);
      return;
    }

    int n = nums.size();
    if (start >= n)
      return;

    if (visited[start] == false && nums[start] <= target) {
      // pick nums[start]
      answer.push_back(nums[start]);
      visited[start] = true;
      combination_impl(results, answer, visited, nums, target - nums[start], start + 1);
      visited[start] = false;
      answer.pop_back();
    }

    if (nums[start] < target) {
      // no pick nums[start]
      while ((start + 1) < n && nums[start] == nums[start + 1]) {
	start++;
      }
      combination_impl(results, answer, visited, nums, target, start + 1);
    }
  }

public:
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> results;
    vector<int> answer;
    vector<bool> visited(candidates.size(), false);
    sort(candidates.begin(), candidates.end());
    combination_impl(results, answer, visited, candidates, target, 0);

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
  vector<int> data1 {10,1,2,7,6,1,5};
  ret = sol.combinationSum2(data1, 8);
  print(ret);
  vector<int> data2 {2, 5, 2, 1, 2};
  ret = sol.combinationSum2(data2, 5);
  print(ret);
  vector<int> data3 {14,6,25,9,30,20,33,34,28,30,16,12,31,9,9,12,34,16,25,32,8,7,30,12,33,20,21,29,24,17,27,34,11,17,30,6,32,21,27,17,16,8,24,12,12,28,11,33,10,32,22,13,34,18,12};
  ret = sol.combinationSum2(data3, 27);
  print(ret);
  vector<int> data4 {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
  ret = sol.combinationSum2(data4, 30);
  print(ret);

  return 0;
}
