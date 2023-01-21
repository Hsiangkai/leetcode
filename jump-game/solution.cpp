#include <vector>
#include <queue>
#include <iostream>

using namespace std;

class Solution {
public:
  bool canJump(vector<int>& nums) {
    int n = nums.size();
    vector<bool> reachable(n, false);
    reachable[0] = true;
    queue<int> work_queue;
    work_queue.push(0);
    while (!work_queue.empty()) {
      int idx = work_queue.front();
      int num = nums[idx];
      work_queue.pop();
      for (int i = 1; i <= num; ++i) {
	if (idx + i >= n)
	  continue;
	if (reachable[idx + i] == false) {
	  reachable[idx + i] = true;
	  work_queue.push(idx + i);
	}
      }
    }

    return reachable[n - 1];
  }
};

int main() {
  Solution sol;
  bool ret;
  vector<int> data1 {2,3,1,1,4};
  ret = sol.canJump(data1);
  cout << ret << endl;
  vector<int> data2 {3,2,1,0,4};
  ret = sol.canJump(data2);
  cout << ret << endl;
  return 0;
}
