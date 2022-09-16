#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int max_profit = 0;
      int n = prices.size();
      int buy_price = prices[0];

      for (auto i = 1; i < n; ++i) {
	if (prices[i] < buy_price) {
	  buy_price = prices[i];
	} else if (prices[i] > buy_price) {
	  int profit = prices[i] - buy_price;
	  if (profit > max_profit)
	    max_profit = profit;
	}
      }

      return max_profit;
    }
};


int main() {
  Solution sol;
  vector<int> test {7, 6, 4, 3, 1};
  int ans = sol.maxProfit(test);
  cout << ans << endl;
  vector<int> test2 {7, 1, 5, 3, 6, 4};
  ans = sol.maxProfit(test2);
  cout << ans << endl;
  return 0;
}
