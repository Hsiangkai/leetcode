#include <vector>
#include <unordered_map>
#include <utility>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
  int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    // create adjacent graph
    // source node ID -> index of times
    unordered_map<int, vector<int>> graph;
    for (int i = 0; i < times.size(); ++i) {
      int src = times[i][0];
      graph[src].push_back(i);
    }
    // (node ID, shortest path weight)
    auto comp = [](const pair<int, int> &lhs, const pair<int, int> &rhs) {
      return lhs.second < rhs.second;
    };
    vector<int> known_weight(n + 1, INT_MAX);
    vector<bool> visited(n + 1, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> q(comp);
    known_weight[k] = 0;
    visited[k] = true;
    int src = k;
    int ret = 0;
    for (int i = 1; i < n; ++i) {
      if (graph[src].size()) {
        for (int time_index : graph[src]) {
          int dest = times[time_index][1];
          int weight = times[time_index][2];
          // cout << src << " " << dest << " " << weight << endl;
          if (visited[dest])
            continue;
          if (known_weight[dest] > known_weight[src] + weight) {
            known_weight[dest] = known_weight[src] + weight;
          }
        }
      }
      // find the next node
      int min_weight = INT_MAX;
      int next_src = src;
      for (int j = 1; j <= n; ++j) {
        if (visited[j] == false) {
          if (known_weight[j] < min_weight) {
            min_weight = known_weight[j];
            next_src = j;
          }
        }
      }
      src = next_src;
      visited[src] = true;
      ret = known_weight[src];
    }

    for (int i = 1; i <= n; ++i) {
      if (visited[i] == false)
	return -1;
    }

    return ret;
  }
};

int main() {
  Solution sol;
  int ret;
  vector<vector<int>> input1 {{2,1,1},{2,3,1},{3,4,1}};
  ret = sol.networkDelayTime(input1, 4, 2);
  cout << ret << endl;  // 2
  vector<vector<int>> input2 {{1,2,1}};
  ret = sol.networkDelayTime(input2, 2, 1);
  cout << ret << endl;  // 1
  vector<vector<int>> input3 {{1,2,1}};
  ret = sol.networkDelayTime(input3, 2, 2);
  cout << ret << endl;  // -1
  vector<vector<int>> input4 {{1,2,1},{2,3,2},{1,3,2}};
  ret = sol.networkDelayTime(input4, 3, 1);
  cout << ret << endl;  // 2
  vector<vector<int>> input5 {{1,2,1},{2,3,2},{1,3,4}};
  ret = sol.networkDelayTime(input5, 3, 1);
  cout << ret << endl;  // 3

  return 0;
}

