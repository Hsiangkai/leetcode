#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
      int n = gas.size();
      int oil = 0;
      int start = 0;
      int t = 0;
      while (t < n) {
	int index = start;
	while (1) {
	  oil += gas[index];
	  oil -= cost[index];
	  if (oil < 0)
	    break;
	  index = (index + 1) % n;
	  t++;
	  if (index == start)
	    return start;
	}
	start = index + 1;
	t++;
	oil = 0;
      }

      return -1;
    }
};

int main() {
  Solution sol;
  int ret;
  vector<int> gas1{1,2,3,4,5};
  vector<int> cost1{3,4,5,1,2};
  ret = sol.canCompleteCircuit(gas1, cost1);
  cout << ret << endl;
  vector<int> gas2{2, 3, 4};
  vector<int> cost2{3, 4, 3};
  ret = sol.canCompleteCircuit(gas2, cost2);
  cout << ret << endl;
  return 0;
}
