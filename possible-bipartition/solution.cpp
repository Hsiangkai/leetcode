#include <vector>
#include <map>
#include <queue>
#include <iostream>

using namespace std;

class Solution {
public:
  bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
    // create adjacent graph
    map<int, vector<int>> graph;
    for (auto edge : dislikes) {
      int src = edge[0];
      int dest = edge[1];
      graph[src].push_back(dest);
      graph[dest].push_back(src);
    }

    vector<bool> visited(n + 1, false);
    vector<int> bipartite(n + 1, 0);
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
      if (bipartite[i] == 0) {
	bipartite[i] = 1;
	visited[i] = true;
        q.push(i);
      }

      while (q.size()) {
	int node = q.front();
	q.pop();
	int kind = bipartite[node] == 1 ? 2 : 1;
	for (int dest : graph[node]) {
	  if (visited[dest] == false) {
	    visited[dest] = true;
	    bipartite[dest] = kind;
	    q.push(dest);
	  } else {
	    if (bipartite[dest] == bipartite[node])
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
  vector<vector<int>> input1 {{1,2},{1,3},{2,4}};
  ret = sol.possibleBipartition(4, input1);
  cout << ret << endl;
  vector<vector<int>> input2 {{1,2},{1,3},{2,3}};
  ret = sol.possibleBipartition(3, input2);
  cout << ret << endl;
  vector<vector<int>> input3 {{1,2},{2,3},{3,4},{4,5},{1,5}};
  ret = sol.possibleBipartition(5, input3);
  cout << ret << endl;
  vector<vector<int>> input4 {};
  ret = sol.possibleBipartition(5, input4);
  cout << ret << endl;
  return 0;
}
