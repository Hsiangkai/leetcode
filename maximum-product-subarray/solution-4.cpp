#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
  int maxProduct(vector<int>& nums) {
    int maxi = 1;
    int mini = 1;
    int result = INT_MIN;

    for (auto &num : nums) {
      int temp = maxi;
      maxi = max({maxi * num, mini * num, num});
      mini = min({temp * num, mini * num, num});
      result = max({maxi, mini, result});
    }

    return result;
  }
};

int main() {
  Solution sol;
  int ret;
  vector<int> data1 {2,3,-2,4};
  ret = sol.maxProduct(data1);
  cout << ret << endl;
  vector<int> data2 {-2, 0, -1};
  ret = sol.maxProduct(data2);
  cout << ret << endl;
  return 0;
}
