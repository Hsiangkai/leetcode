#include <vector>
#include <queue>
#include <iostream>

using namespace std;

class Solution {
public:
  bool isBipartite(vector<vector<int>>& g) {
    // convert to adjacent graph
    int n = g.size();
    vector<vector<int>> graph(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
      for (int dest : g[i]) {
	graph[i][dest] = 1;
      }
    }

    queue<int> buf;
    vector<int> sides (n, -1);  // -1: unvisited, 0: group1, 1: group2
    for (int i = 0; i < n; ++i) {
      if (sides[i] == -1) {
	sides[i] = 0;  // group1
	buf.push(i);
      } else
	continue;

      while (buf.size()) {
	int node = buf.front();
	buf.pop();
	for (int j = 0; j < n; ++j) {
	  if (graph[node][j] == 1) {
	    if (sides[j] == -1) {
	      sides[j] = sides[node] == 0 ? 1 : 0;
	      buf.push(j);
	    } else if (sides[j] == sides[node])
	      return false;
	  }
	}
      }
    }

    return true;
  }
};

int main() {
  Solution sol;
  bool ret;
  vector<vector<int>> input1 {{1, 3}, {0, 2}, {1, 3}, {0, 2}};
  ret = sol.isBipartite(input1);
  cout << ret << endl;
  vector<vector<int>> input2 {{1, 2, 3}, {0, 2}, {0, 1, 3}, {0, 2}};
  ret = sol.isBipartite(input2);
  cout << ret << endl;
  return 0;
}
