#include <vector>
#include <map>
#include <queue>
#include <iostream>

using namespace std;

class Solution {
public:
  vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> answer;
    map<int, vector<int>> graph;
    vector<int> pre_counts(numCourses, 0);

    for (auto &pre : prerequisites) {
      int dest = pre[0];
      int src = pre[1];
      if (graph.find(src) == graph.end()) {
	graph.emplace(src, vector<int>{dest});
      } else {
	graph[src].push_back(dest);
      }
      pre_counts[dest]++;
    }

    queue<int> work_queue;
    for (int i = 0; i < numCourses; ++i) {
      if (pre_counts[i] == 0)
	work_queue.push(i);
    }

    while (work_queue.size()) {
      int node = work_queue.front();
      work_queue.pop();
      answer.push_back(node);
      for (auto dest : graph[node]) {
	pre_counts[dest]--;
	if (pre_counts[dest] == 0)
	  work_queue.push(dest);
      }
    }
    if (answer.size() != numCourses)
      answer.clear();

    return answer;
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
  vector<vector<int>> input1 {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
  ret = sol.findOrder(4, input1);
  out(ret);
  vector<vector<int>> input2 {{1, 0}};
  ret = sol.findOrder(2, input2);
  out(ret);
  vector<vector<int>> input3 {};
  ret = sol.findOrder(1, input3);
  out(ret);
  return 0;
}
