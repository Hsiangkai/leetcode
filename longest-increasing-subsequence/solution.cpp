#include <vector>
#include <utility>
#include <iostream>

using namespace std;

class Solution {
public:
  int lengthOfLIS(vector<int>& nums) {
    vector<int> seq;

    for (auto & num : nums) {
      if (seq.empty() || num > seq.back()) {
	seq.push_back(num);
      } else {
	auto it = lower_bound(seq.begin(), seq.end(), num);
	*it = num;
      }
    }

    return seq.size();
  }
};

int main() {
  Solution sol;
  int ret;
  vector<int> data1 {10,9,2,5,3,7,101,18};
  ret = sol.lengthOfLIS(data1);
  cout << ret << endl;  // 4
  vector<int> data2 {0,1,0,3,2,3};
  ret = sol.lengthOfLIS(data2);
  cout << ret << endl;  // 4
  vector<int> data3 {7,7,7,7,7,7,7};
  ret = sol.lengthOfLIS(data3);
  cout << ret << endl;  // 1
  vector<int> data4 {1,3,6,7,9,4,10,5,6};
  ret = sol.lengthOfLIS(data4);
  cout << ret << endl;  // 6
  return 0;
}
