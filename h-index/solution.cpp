#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
  int hIndex(vector<int>& citations) {
    sort(citations.begin(), citations.end(), greater<int>());
    int n = citations.size();
    int h;
    for (h = n; h >= 1; --h) {
      if (citations[h-1] >= h) {
	if (h == n)
	  return n;
	else if (citations[h] <= h)
	  break;
      }
    }

    return h;
  }
};

int main() {
  Solution sol;
  int ret;
  vector<int> input1 {3,0,6,1,5};
  ret = sol.hIndex(input1);
  cout << ret << endl;
  vector<int> input2 {1, 3, 1};
  ret = sol.hIndex(input2);
  cout << ret << endl;
  return 0;
}
