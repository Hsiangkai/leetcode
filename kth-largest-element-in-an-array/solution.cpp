#include <vector>
#include <unordered_map>
#include <queue>
#include <iostream>

using namespace std;

class Solution {
public:
  int findKthLargest(vector<int>& nums, int k) {
    int ret;
    unordered_map<int, int> counts;
    for (auto num : nums) {
      counts[num]++;
    }

    priority_queue<pair<int, int>> pq;
    for (auto count : counts) {
      pq.push(make_pair(count.first, count.second));
    }

    while (k) {
      auto val = pq.top();
      pq.pop();
      if (val.second >= k)
	return val.first;
      k -= val.second;
    }

    return -1;
  }
};

int main() {
  Solution sol;
  int ret;
  vector<int> data1 {3,2,1,5,6,4};
  ret = sol.findKthLargest(data1, 2);
  cout << ret << endl;
  vector<int> data2 {3,2,3,1,2,4,5,5,6};
  ret = sol.findKthLargest(data2, 4);
  cout << ret << endl;
  return 0;
}
