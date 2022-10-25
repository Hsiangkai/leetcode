#include <vector>
#include <map>

using namespace std;

class Solution {
  int traverse(int node, map<int, vector<int>> &graph, vector<int> &quiet, vector<bool> &visited, vector<int> &ret) {
    visited[node] = true;

    for (int dest : graph[node]) {
      int qindex;
      if (visited[dest] == false) {
        qindex = traverse(dest, graph, quiet, visited, ret);
      } else {
        qindex = ret[dest];
      }
      if (quiet[ret[node]] > quiet[qindex]) {
        ret[node] = qindex;
      }
    }

    return ret[node];
  }

public:
  vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
    map<int, vector<int>> graph;
    int n = quiet.size();
    vector<int> cnt(n, 0);

    for (auto edge : richer) {
      int src = edge[1];
      int dest = edge[0];
      graph[src].push_back(dest);
      cnt[dest]++;
    }

    vector<int> ret (n);
    for (int i = 0; i < n; ++i) {
      ret[i] = i;
    }
    vector<bool> visited (n, false);
    for (int i = 0; i < n; ++i) {
      if (visited[i] == false && cnt[i] == 0) {
        int qindex = traverse(i, graph, quiet, visited, ret);
        ret[i] = qindex;
      }
    }

    return ret;
  }
};

int main() {
  Solution sol;
  vector<int> ret;
  vector<vector<int>> input1 {{1,0},{2,1},{3,1},{3,7},{4,3},{5,3},{6,3}};
  vector<int> quiet1 {3,2,5,4,6,1,7,0};
  ret = sol.loudAndRich(input1, quiet1);  // [5, 5, 2, 5, 4, 5, 6, 7]
  vector<vector<int>> input2 {};
  vector<int> quiet2 {0};
  ret = sol.loudAndRich(input2, quiet2);  // [0]
  vector<vector<int>> input3 {{0, 1}};
  vector<int> quiet3 {0, 1};
  ret = sol.loudAndRich(input3, quiet3);  // [0, 0]
  vector<vector<int>> input4 {{0,1},{0,2}};
  vector<int> quiet4 {0, 1, 2};
  ret = sol.loudAndRich(input4, quiet4);  // [0, 0, 0]

  return 0;
}
