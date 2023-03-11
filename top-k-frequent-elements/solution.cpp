#include <vector>
#include <queue>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    // records of pair (number, count)
    unordered_map<int, int> counts;
    int n = nums.size();
    // O(n) in average
    for (int i = 0; i < n; ++i) {
      if (counts.find(nums[i]) != counts.end())
	counts[nums[i]]++;
      else
	counts[nums[i]] = 1;
    }
    auto comp = [&](int i, int j) {
      return counts[i] < counts[j];
    };
    priority_queue<int, vector<int>, decltype(comp)> pq(comp);
    vector<int> results;
    // O(# of counts x log(n))
    for (auto & count : counts) {
      pq.push(count.first);
    }

    // O(k x log(n))
    while (k) {
      auto index = pq.top();
      pq.pop();
      results.push_back(index);
      k--;
    }

    return results;
  }
};

void print(vector<int> &data) {
  for (auto &d : data) {
    cout << d << " ";
  }
  cout << endl;
}

int main() {
  Solution sol;
  vector<int> ret;
  vector<int> data1 {3, 3, 3, 2, 2, 1};
  ret = sol.topKFrequent(data1, 2);
  print(ret);
  vector<int> data2 {1};
  ret = sol.topKFrequent(data1, 1);
  print(ret);
  return 0;
}
