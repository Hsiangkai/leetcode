#include <vector>
#include <iostream>
#include <queue>

using namespace std;

struct Data {
  Data(int x, int y, int sum) : x(x), y(y), sum(sum) {}
  int x;
  int y;
  int sum;
};

class Compare {
public:
  bool operator()(Data &lhs, Data &rhs) {
    return lhs.sum > rhs.sum;
  }
};

class Solution {
public:
  vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    priority_queue<Data, vector<Data>, Compare> pq;

    int n1 = nums1.size();
    int n2 = nums2.size();
    for (int j = 0; j < n2; ++j) {
      pq.push(Data(0, j, nums1[0] + nums2[j]));
    }

    vector<vector<int>> ret;
    while (!pq.empty() && k > 0) {
      const Data data = pq.top();
      pq.pop();
      ret.push_back(vector<int>{nums1[data.x], nums2[data.y]});
      if ((data.x + 1) < n1) {
	pq.push(Data(data.x + 1, data.y, nums1[data.x + 1] + nums2[data.y]));
      }

      k--;
    }

    return ret;
  }
};

void print(vector<vector<int>> &data) {
  for (auto &d : data) {
    cout << "[" << d[0] << ", " << d[1] << "]" << endl;
  }
  cout << endl;
}

int main() {
  Solution sol;
  vector<vector<int>> ret;
  vector<int> data1 {1, 7, 11};
  vector<int> data2 {2, 4, 6};
  ret = sol.kSmallestPairs(data1, data2, 3);
  print(ret);
  vector<int> data3 {1, 1, 2};
  vector<int> data4 {1, 2, 3};
  ret = sol.kSmallestPairs(data3, data4, 10);
  print(ret);
  vector<int> data5 {1, 2};
  vector<int> data6 {3};
  ret = sol.kSmallestPairs(data5, data6, 3);
  print(ret);
  vector<int> data7 {1, 2, 4};
  vector<int> data8 {-1, 1, 2};
  ret = sol.kSmallestPairs(data7, data8, 100);
  // [[1,-1],[2,-1],[1,1],[4,-1],[2,1],[1,2],[2,2],[4,1],[4,2]]
  print(ret);
  return 0;
}
