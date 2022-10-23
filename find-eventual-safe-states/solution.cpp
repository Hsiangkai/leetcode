#include <vector>

using namespace std;

class Solution {
  bool traversal(int node, vector<vector<int>> &graph, vector<int> &safe_states, vector<int> &visited) {
    if (graph[node].size() == 0) {
      safe_states.push_back(node);
      visited[node] = 1;
      return true;
    }

    if (visited[node] == 0)
      return false;
    else if (visited[node] == 1)
      return true;
    else if (visited[node] == 2)
      return false;

    visited[node] = 2;
    bool isSafe = true;
    // A node is a safe node if every possible path starting from
    // that node leads to a terminal node (or another safe node).
    for (auto dest : graph[node]) {
      if (visited[dest] == -1) {
	if (!traversal(dest, graph, safe_states, visited)) {
	  isSafe = false;
	  visited[dest] = 0;
	} else
	  visited[dest] = 1;
      } else if (visited[dest] == 0) {
	isSafe = false;
      } else if (visited[dest] == 2) {
	isSafe = false;
      }
    }
    if (isSafe) {
      safe_states.push_back(node);
      visited[node] = 1;
    } else
      visited[node] = 0;

    return isSafe;
  }
public:
  vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> safe_states;
    // -1: unvisited, 0: non-safe node, 1: safe node, 2: visited
    vector<int> visited(n, -1);

    for (int i = 0; i < n; ++i) {
      if (visited[i] == -1)
        traversal(i, graph, safe_states, visited);
    }

    sort(safe_states.begin(), safe_states.end());
    return safe_states;
  }
};

int main() {
  Solution sol;
  vector<int> ret;
  vector<vector<int>> input1 = {{1,2},{2,3},{5},{0},{5},{},{}};
  ret = sol.eventualSafeNodes(input1);  // 2, 4, 5, 6
  vector<vector<int>> input2 = {{1,2,3,4},{1,2},{3,4},{0,4},{}};
  ret = sol.eventualSafeNodes(input2);  // 4
  return 0;
}
