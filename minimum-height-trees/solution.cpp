#include <vector>
#include <iostream>
#include <utility>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:
  vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    // convert edges to adjacent graph
    vector<vector<int>> graph(n);
    vector<int> degrees(n, 0);

    // convert to a graph
    for (auto &edge : edges) {
      int src = edge[0];
      int dest = edge[1];
      graph[src].push_back(dest);
      graph[dest].push_back(src);
      degrees[src]++;
      degrees[dest]++;
    }

    // traverse
    vector<bool> visited(n, false);
    int visited_cnt = 0;
    queue<int> work;
    queue<int> next_work;
    for (int i = 0; i < n; ++i) {
      if (degrees[i] == 1) {
        work.push(i);
      }
    }
    while (1) {
      if (n - visited_cnt == 1) {
	auto it = find_if(visited.begin(), visited.end(),
	                  [](const bool &a){ return a == false;});
	int index = it - visited.begin();
	return {index};
      }
      if (n - visited_cnt == 2) {
	int node1 = work.front();
	work.pop();
	int node2 = work.front();
	work.pop();
	return {node1, node2};
      }

      while (work.size()) {
	int node = work.front();
	work.pop();
	visited[node] = true;
	visited_cnt++;
	degrees[node]--;
	for (auto next : graph[node]) {
	  if (visited[next] == false) {
	    degrees[next]--;
	    if (degrees[next] == 1)
	      next_work.push(next);
	  }
	}
      }
      swap(work, next_work);
    }
  }
};

static void out(const vector<int> &in) {
  for (int i : in) {
    cout << i << " ";
  }
  cout << endl;
}

int main() {
  Solution sol;
  vector<int> ret;
  vector<vector<int>> input1 {{1, 0}, {1, 2}, {1, 3}};
  ret = sol.findMinHeightTrees(4, input1);
  out(ret);  // 1
  vector<vector<int>> input2 {{3, 0}, {3, 1}, {3, 2}, {3, 4}, {5, 4}};
  ret = sol.findMinHeightTrees(6, input2);
  out(ret);  // 3, 4
  vector<vector<int>> input3 {{0, 1}};
  ret = sol.findMinHeightTrees(2, input3);
  out(ret);  // 0, 1
  vector<vector<int>> input4 {{0,1},{0,2},{0,3},{2,4},{0,5},{5,6},{6,7},{2,8},{7,9}};
  ret = sol.findMinHeightTrees(10, input4);
  out(ret);  // 5
  return 0;
}
