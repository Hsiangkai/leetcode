#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
  int findMinDifference(vector<string>& timePoints) {
    vector<int> minutes;
    for (auto t : timePoints) {
      int hour = stoi(t);
      int minute = stoi(t.substr(3, 2));
      minutes.push_back(hour * 60 + minute);
    }

    sort(minutes.begin(), minutes.end());
    minutes.push_back(minutes[0] + 1440);

    int smallest_diff = 1440;
    int n = minutes.size();
    for (int i = 1; i < n; ++i) {
      if (minutes[i] - minutes[i-1] < smallest_diff)
	smallest_diff = minutes[i] - minutes[i-1];
    }

    return smallest_diff;
  }
};

int main() {
  Solution sol;
  int ret;
  vector<string> input1 {"23:59","00:00"};
  ret = sol.findMinDifference(input1);
  cout << ret << endl;
  vector<string> input2 {"00:00","23:59","00:00"};
  ret = sol.findMinDifference(input2);
  cout << ret << endl;
  vector<string> input3 {"05:31","22:08","00:35"};
  ret = sol.findMinDifference(input3);
  cout << ret << endl;
  return 0;
}
