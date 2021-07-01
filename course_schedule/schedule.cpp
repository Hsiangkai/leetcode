#include <iostream>
#include <vector>

using namespace std;

class Solution {
  enum state {
    UNINIT,
    UNTOUCHED,
    PROCESSING,
    DONE,
  };
  struct node {
    int _id;
    vector<int> _successors;
    enum state _state;
    node(int id, enum state s) : _id(id), _state(s) {}
  };
  vector<node> graph;

private:
  void init(int numCourses, vector<vector<int>>& prerequisites) {
    for (int i = 0; i < numCourses; i++)
      graph.push_back(node(i, UNINIT));
    // Construct graph.
    for (auto &dep : prerequisites) {
      graph[dep[0]]._state = UNTOUCHED;
      graph[dep[1]]._state = UNTOUCHED;
      graph[dep[0]]._successors.push_back(dep[1]);
    }
  }

  bool processing() {
    for (auto &n : graph) {
      if (n._state == UNINIT)
        continue;
      if (n._state == DONE)
        continue;
      if (!visit(n))
        return false;
    }
    return true;
  }

  bool visit(node &n) {
    if (n._state == DONE)
      return true;
    // Encounter a circle.
    if (n._state == PROCESSING)
      return false;
    n._state = PROCESSING;
    for (int s : n._successors)
      if (!visit(graph[s]))
        return false;

    n._state = DONE;
    return true;
  }
public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    init(numCourses, prerequisites);
    if (processing())
      return true;
    return false;
  }
};

int main() {
  Solution S;
  vector<vector<int>> Q = {{0, 1}, {1, 0}};

  if (S.canFinish(2, Q))
    cout << "true" << endl;
  else
    cout << "false" << endl;

  return 0;
}
