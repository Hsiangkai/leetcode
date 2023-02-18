#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> ret;
    int n = intervals.size();
    if (n == 0) {
      ret.push_back(newInterval);
      return ret;
    }

    int i = 0;
    bool inserted = false;
    while (i < n) {
      vector<int> &current = intervals[i];
      if (newInterval[0] >= current[0]) {
	if (newInterval[0] > current[1]) {
	  ret.push_back(current);
	  i++;
	} else if (newInterval[1] <= current[1]) {
	  inserted = true;
	  break; // ignore the newInterval
	} else if (newInterval[1] > current[1]) {
	  newInterval[0] = current[0];
	  i++;
	}
      } else {
	if (newInterval[1] < current[0]) {
	  ret.push_back(newInterval);
	  inserted = true;
	  break;
	} else if (newInterval[1] <= current[1]) {
	  newInterval[1] = current[1];
	  i++;
	} else if (newInterval[1] > current[1]) {
	  i++;
	}
      }
    }

    if (inserted == false)
      ret.push_back(newInterval);

    for (; i < n; ++i) {
      ret.push_back(intervals[i]);
    }

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
  vector<vector<int>> data1 {{1, 3},{6, 9}};
  vector<int> new_interval1 {2, 5};
  ret = sol.insert(data1, new_interval1);
  print(ret);

  vector<vector<int>> data2 {{1, 5}};
  vector<int> new_interval2 {2, 7};
  ret = sol.insert(data2, new_interval2);
  print(ret);

  return 0;
}
