#include <vector>
#include <unordered_map>
#include <iostream>
#include <queue>

using namespace std;

class Solution {
public:
  int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size();
    unordered_map<int, vector<int>> graph;

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
	if (isConnected[i][j] == 1) {
	  graph[i].push_back(j);
	  graph[j].push_back(i);
	}
      }
    }
    int components = 0;
    vector<bool> visited(n, false);
    queue<int> work_queue;
    for (auto &it : graph) {
      int node = it.first;
      if (visited[node])
	continue;

      work_queue.push(node);
      while (work_queue.size()) {
	int n = work_queue.front();
	work_queue.pop();
	visited[n] = true;
	for (auto adj : graph[n]) {
	  if (visited[adj] == false)
	    work_queue.push(adj);
	}
      }
      components++;
    }

    return components;
  }
};

int main() {
  Solution sol;
  int ret;
  vector<vector<int>> input1 {{1,1,0},{1,1,0},{0,0,1}};
  ret = sol.findCircleNum(input1);
  cout << ret << endl;
  vector<vector<int>> input2 {{1,0,0},{0,1,0},{0,0,1}};
  ret = sol.findCircleNum(input2);
  cout << ret << endl;
  return 0;
}
