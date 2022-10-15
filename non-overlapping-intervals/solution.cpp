#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    int end = intervals[0][1];
    int count = 0;
    for (int i = 1; i < intervals.size(); ++i) {
      if (intervals[i][0] >= end) {
	// insert
	end = intervals[i][1];
      } else {
	if (intervals[i][1] < end)
	  end = intervals[i][1];
	count++;
      }
    }
    return count;
  }
};

int main() {
  Solution sol;
  vector<vector<int>> test1 {
      {1, 2},
      {2, 3},
      {3, 4},
      {1, 3}};
  int ans;
  ans = sol.eraseOverlapIntervals(test1);
  cout << ans << endl;
  vector<vector<int>> test2 {
      {1, 2},
      {1, 2},
      {1, 2}};
  ans = sol.eraseOverlapIntervals(test2);
  cout << ans << endl;
  vector<vector<int>> test3 {
      {1, 2},
      {2, 3}};
  ans = sol.eraseOverlapIntervals(test3);
  cout << ans << endl;

  return 0;
}
