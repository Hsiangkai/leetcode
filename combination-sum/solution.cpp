#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
private:
  void combination_impl(vector<vector<int>> &results, vector<int> &answer, vector<int> &candidates,
                        int target, int start) {
    if (target == 0) {
      results.push_back(answer);
      return;
    }

    int n = candidates.size();
    for (int i = start; i < n; ++i) {
      int num = candidates[i];
      if (num > target)
	return;

      answer.push_back(num);
      combination_impl(results, answer, candidates, target - num, i);
      answer.pop_back();
    }
  }

public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> results;
    vector<int> answer;
    combination_impl(results, answer, candidates, target, 0);

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
  vector<vector<int>> results;
  vector<int> data1 {2, 3, 6, 7};
  results = sol.combinationSum(data1, 7);
  print(results);
  vector<int> data2 {2, 3, 5};
  results = sol.combinationSum(data2, 8);
  print(results);
  vector<int> data3 {2};
  results = sol.combinationSum(data3, 1);
  print(results);
  return 0;
}
