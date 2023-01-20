#include <vector>
#include <map>
#include <iostream>

using namespace std;

class Solution {
private:
  int impl(vector<int> &coins, int amount, map<int, int> &dict) {
    if (amount < 0)
      return -1;
    if (amount == 0)
      return 0;

    if (dict.find(amount) != dict.end())
      return dict[amount];

    int min_coin_n = INT_MAX;
    for (int i = coins.size() - 1; i >= 0; --i) {
      int ret = impl(coins, amount - coins[i], dict);
      if (ret == -1)
	continue;
      ret += 1;
      if (ret < min_coin_n)
        min_coin_n = ret;
    }
    if (min_coin_n == INT_MAX)
      min_coin_n = -1;

    dict[amount] = min_coin_n;
    return min_coin_n;
  }

public:
  int coinChange(vector<int>& coins, int amount) {
    map<int, int> dict;
    return impl(coins, amount, dict);
  }
};

int main() {
  Solution sol;
  int ret;
  vector<int> data1 {1, 2, 5};
  ret = sol.coinChange(data1, 11);
  cout << ret << endl;
  vector<int> data2 {2};
  ret = sol.coinChange(data2, 3);
  cout << ret << endl;
  vector<int> data3 {1};
  ret = sol.coinChange(data3, 0);
  cout << ret << endl;
  return 0;
}
