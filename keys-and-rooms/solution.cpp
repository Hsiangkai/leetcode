#include <vector>
#include <queue>
#include <iostream>

using namespace std;

class Solution {
public:
  bool canVisitAllRooms(vector<vector<int>>& rooms) {
    queue<int> q;
    int n = rooms.size();
    vector<int> visited(n, false);

    q.push(0);
    while (q.size()) {
      int node = q.front();
      q.pop();
      visited[node] = true;
      for (auto dest : rooms[node]) {
	if (!visited[dest]) {
	  q.push(dest);
	}
      }
    }

    for (int i = 0; i < n; ++i) {
      if (visited[i] == false)
	return false;
    }
    return true;
  }
};

int main() {
  Solution sol;
  bool ret;
  vector<vector<int>> input1 {{1,3},{3,0,1},{2},{0}};
  ret = sol.canVisitAllRooms(input1);
  cout << ret << endl;
  vector<vector<int>> input2 {{1},{2},{3},{}};
  ret = sol.canVisitAllRooms(input2);
  cout << ret << endl;
  return 0;
}
