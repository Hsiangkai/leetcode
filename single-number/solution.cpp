#include <vector>
#include <math.h>
#include <iostream>

using namespace std;

class Solution {
public:
  int singleNumber(vector<int>& nums) {
    int answer = 0;
    for (auto num : nums) {
      answer ^= num;
    }
    return answer;
  }
};

int main() {
  Solution sol;
  int ret;
  vector<int> data1 {2, 2, 1};
  ret = sol.singleNumber(data1);
  cout << ret << endl;
  vector<int> data2 {4, 1, 2, 1, 2};
  ret = sol.singleNumber(data2);
  cout << ret << endl;
  vector<int> data3 {1};
  ret = sol.singleNumber(data3);
  cout << ret << endl;
  vector<int> data4 {-1};
  ret = sol.singleNumber(data4);
  cout << ret << endl;
  return 0;
}
