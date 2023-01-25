#include <vector>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;

class Solution {
private:
  int impl(int index, vector<int> &prices, bool canBuy, map<pair<int, bool>, int> &dp) {
    int n = prices.size();
    if (index >= n)
      return 0;

    pair<int, bool> key{index, canBuy};
    if (dp.find(key) != dp.end())
      return dp[key];

    int profit;
    if (canBuy) {
      profit = max(-prices[index] + impl(index + 1, prices, false, dp),
	           impl(index + 1, prices, true, dp));
    } else {
      profit =  max(prices[index] + impl(index + 2, prices, true, dp),
	            impl(index + 1, prices, false, dp));
    }

    dp[key] = profit;
    return profit;
  }

public:
  int maxProfit(vector<int>& prices) {
    map<pair<int, bool>, int> dp;
    return impl(0, prices, true, dp);
  }
};

int main() {
  Solution sol;
  int ret;
  vector<int> data1 {1, 2, 3, 0, 2};
  ret = sol.maxProfit(data1);
  cout << ret << endl;
  vector<int> data2 {1};
  ret = sol.maxProfit(data2);
  cout << ret << endl;
  return 0;
}
