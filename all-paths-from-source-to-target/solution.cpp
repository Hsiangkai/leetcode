#include <vector>

using namespace std;

class Solution {
  bool traverse(int node, vector<vector<int>> &graph, vector<int> &path, vector<vector<int>> &paths) {
    int n = graph.size();

    if (node == n-1)  // reach the end
      return true;

    if (path.size() > n)
      return false;

    for (auto dest : graph[node]) {
      path.push_back(dest);
      if (traverse(dest, graph, path, paths)) {
	// add path to the result values
	paths.push_back(path);
      }
      path.pop_back();
    }

    return false;
  }

public:
  vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    vector<vector<int>> paths = {};
    vector<int> path = {0};

    traverse(0, graph, path, paths);

    return paths;
  }
};

int main() {
  Solution sol;
  vector<vector<int>> ret;
  vector<vector<int>> input1 {{1,2},{3},{3},{}};
  ret = sol.allPathsSourceTarget(input1);
  vector<vector<int>> input2 {{4,3,1},{3,2,4},{3},{4},{}};
  ret = sol.allPathsSourceTarget(input2);
  return 0;
}
