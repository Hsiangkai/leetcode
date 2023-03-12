#include <string>
#include <unordered_map>
#include <queue>
#include <iostream>

using namespace std;

class Solution {
public:
  string frequencySort(string s) {
    unordered_map<char, int> counts;
    for (auto c : s) {
      counts[c]++;
    }

    priority_queue<pair<int, char>> pq;
    for (auto &count : counts) {
      pq.push(make_pair(count.second, count.first));
    }

    string ret_str;
    while (!pq.empty()) {
      auto val = pq.top();
      pq.pop();
      ret_str.append(val.first, val.second);
    }

    return ret_str;
  }
};

int main() {
  Solution sol;
  string ret;
  ret = sol.frequencySort("tree");
  cout << ret << endl;
  ret = sol.frequencySort("cccaaa");
  cout << ret << endl;
  ret = sol.frequencySort("Aabb");
  cout << ret << endl;
  return 0;
}
