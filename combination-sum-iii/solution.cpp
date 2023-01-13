#include <vector>
#include <iostream>

using namespace std;

class Solution {
private:
  void impl(vector<vector<int>> &results, vector<int> &answer, int k, int n, int select) {

    if (k == 0 && n == 0) {
      results.push_back(answer);
      return;
    }

    if (select >= 10)
      return;

    if (select <= n) {
      answer.push_back(select);
      impl(results, answer, k - 1, n - select, select + 1);
      answer.pop_back();
    }

    impl(results, answer, k, n, select + 1);
  }

public:
  vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> results;
    vector<int> answer;
    impl(results, answer, k, n, 1);

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
  ret = sol.combinationSum3(3, 7);
  print(ret);
  ret = sol.combinationSum3(3, 9);
  print(ret);
  ret = sol.combinationSum3(4, 1);
  print(ret);
  return 0;
}
