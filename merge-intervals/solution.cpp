#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> ret;
    sort(intervals.begin(), intervals.end());
    vector<int> current = intervals[0];
    for (auto i = 1; i < intervals.size(); ++i) {
      vector<int> &next = intervals[i];
      if (next[0] > current[1]) {
	ret.push_back(current);
	current = next;
      } else {
	if (next[1] > current[1]) {
	  current[1] = next[1];
	}
      }
    }
    ret.push_back(current);

    return ret;
  }
};

void print(vector<vector<int>> &data) {
  for (auto &interval : data) {
    cout << "{" << interval[0] << ", " << interval[1] << "}" << ", ";
  }
  cout << endl;
}

int main() {
  Solution sol;
  vector<vector<int>> ret;
  vector<vector<int>> data1 {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
  ret = sol.merge(data1);
  print(ret);
  return 0;
}
