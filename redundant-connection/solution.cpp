#include <vector>
#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
  bool connected(int src, int dest, unordered_map<int, vector<int>> &graph, int n) {
    queue<int> work_queue;
    work_queue.push(src);
    vector<bool> visited(n, false);
    while (work_queue.size()) {
      int start = work_queue.front();
      work_queue.pop();
      visited[start] = true;
      for (int end : graph[start]) {
	if (end == dest)
	  return true;
	if (visited[end] == false) {
	  work_queue.push(end);
	}
      }
    }
    return false;
  }

public:
  vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    int n = edges.size();
    unordered_map<int, vector<int>> graph;
    vector<bool> visited(n, false);
    vector<int> answer;

    for (auto &edge : edges) {
      int src = edge[0];
      int dest = edge[1];

      if (visited[src] && visited[dest] && connected(src, dest, graph, n))
	answer = edge;

      visited[src] = true;
      visited[dest] = true;
      if (graph.find(src) == graph.end())
	graph.emplace(src, vector<int>{dest});
      else
	graph[src].push_back(dest);

      if (graph.find(dest) == graph.end())
	graph.emplace(dest, vector<int>{src});
      else
	graph[dest].push_back(src);
    }

    return answer;
  }
};

int main() {
  Solution sol;
  vector<vector<int>> input1 {{1,2},{1,3},{2,3}};
  vector<int> ret;
  ret = sol.findRedundantConnection(input1);
  cout << ret[0] << " " << ret[1] << endl;  // 2, 3
  vector<vector<int>> input2 {{1,2},{2,3},{3,4},{1,4},{1,5}};
  ret = sol.findRedundantConnection(input2);
  cout << ret[0] << " " << ret[1] << endl;  // 1, 4
  vector<vector<int>> input3 {{3,4},{1,2},{2,4},{3,5},{2,5}};
  ret = sol.findRedundantConnection(input3);
  cout << ret[0] << " " << ret[1] << endl;  // 2, 5
  return 0;
}
