#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  int findJudge(int n, vector<vector<int>>& trust) {
    vector<int> in_degrees(n, 0);
    vector<int> out_degrees(n, 0);

    for (auto edge : trust) {
      int src = edge[0] - 1;
      int dest = edge[1] - 1;
      out_degrees[src]++;
      in_degrees[dest]++;
    }

    int judge = -1;
    for (int i = 0; i < n; ++i) {
      if (out_degrees[i] == 0 && in_degrees[i] == n - 1) {
	if (judge != -1)
	  return -1;
	judge = i + 1;
      }
    }

    return judge;
  }
};

int main() {
  Solution sol;
  int ret;
  vector<vector<int>> input1 {{1, 2}};
  ret = sol.findJudge(2, input1);
  cout << ret << endl;
  vector<vector<int>> input2 {{1,3},{2,3}};
  ret = sol.findJudge(3, input2);
  cout << ret << endl;
  vector<vector<int>> input3 {{1,3},{2,3},{3,1}};
  ret = sol.findJudge(3, input3);
  cout << ret << endl;
  return 0;
}
