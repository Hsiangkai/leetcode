#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct Data {
  Data(int x, int y, int value) : x(x), y(y), value(value) {}
  int x;
  int y;
  int value;
};

class Compare {
public:
  bool operator() (Data &lhs, Data &rhs) {
    return lhs.value > rhs.value;
  }
};

class Solution {
public:
  int kthSmallest(vector<vector<int>>& matrix, int k) {
    priority_queue<Data, std::vector<Data>, Compare> pq;

    int n = matrix.size();
    for (int i = 0; i < n; ++i) {
      pq.push(Data(i, 0, matrix[i][0]));
    }

    int value;
    while (k > 0) {
      Data elem = pq.top();
      value = elem.value;
      pq.pop();
      if (elem.y < n - 1) {
	pq.push(Data(elem.x, elem.y + 1, matrix[elem.x][elem.y + 1]));
      }
      k--;
    }

    return value;
  }
};

int main() {
  Solution sol;
  int ret;
  vector<vector<int>> data1 {{1, 5, 9}, {10, 11, 13}, {12, 13, 15}};
  ret = sol.kthSmallest(data1, 8);
  cout << ret << endl;
  return 0;
}
