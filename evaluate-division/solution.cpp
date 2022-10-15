#include <vector>
#include <utility>
#include <string>
#include <unordered_map>
#include <stack>
#include <iostream>

using namespace std;

class Solution {
  double find_path(string src, string dest, unordered_map<string, vector<pair<string, double>>> &graph, unordered_map<string, bool> &visited) {
    if (graph.find(src) == graph.end())
      return -1.0;

    if (src == dest)
      return 1.0;

    visited[src] = true;
    for (auto child : graph[src]) {
      if (child.first == dest)
	return child.second;
      else {
	if (visited.find(child.first) == visited.end()) {
          double answer = child.second * find_path(child.first, dest, graph, visited);
	  if (answer >= 0)
	    return answer;
        }
      }
    }

    return -1.0;
  }

public:
  vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
    unordered_map<string, vector<pair<string, double>>> graph;
    int n = equations.size();

    for (int i = 0; i < n; ++i) {
      string src = equations[i][0];
      string dest = equations[i][1];

      if (graph.find(src) == graph.end()) {
	graph[src] = { make_pair(dest, values[i]) };
      } else {
	graph[src].push_back(make_pair(dest, values[i]));
      }
      
      if (graph.find(dest) == graph.end()) {
	graph[dest] = { make_pair(src, 1.0 / values[i]) };
      } else {
	graph[dest].push_back(make_pair(src, 1.0 / values[i]));
      }
    }

    vector<double> answer;
    int m = queries.size();
    for (int i = 0; i < m; ++i) {
      string src = queries[i][0];
      string dest = queries[i][1];
      unordered_map<string, bool> visited;
      double val = find_path(src, dest, graph, visited);
      answer.push_back(val);
    }

    return answer;
  }
};

void out(const vector<double> &val) {
  for (auto v : val) {
    cout << v << " ";
  }
  cout << endl;
}

int main() {
  Solution sol;
  vector<vector<string>> equations1 {{"a","b"},{"b","c"}};
  vector<double> values1 {2.0, 3.0};
  vector<vector<string>> queries1 {{"a","c"},{"b","a"},{"a","e"},{"a","a"},{"x","x"}};
  vector<double> ans;
  ans = sol.calcEquation(equations1, values1, queries1);
  out(ans);
  return 0;
}
