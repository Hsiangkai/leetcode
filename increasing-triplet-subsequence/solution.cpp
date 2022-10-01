#include <vector>
#include <iostream>
#include <stack>
#include <queue>

using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
      stack<int> s;
      int n = nums.size();
      if (n <= 2)
	return false;

      s.push(nums[0]);
      for (int i = 1; i < n; ++i) {
        if (nums[i] > s.top()) {
          s.push(nums[i]);
          if (s.size() == 3)
            return true;
        } else if (nums[i] < s.top()) {
          if (s.size() == 1) {
            s.pop();
            s.push(nums[i]);
          } else if (s.size() == 2) {
            int top = s.top();
            s.pop();
            if (nums[i] > s.top()) {
              s.push(nums[i]);
            } else {
              s.push(top);
            }
          }
        }
      }

      stack<int> ns;
      ns.push(nums[n - 1]);
      for (int i = n - 2; i >= 0; --i) {
        if (nums[i] < ns.top()) {
          ns.push(nums[i]);
          if (ns.size() == 3)
            return true;
        } else if (nums[i] > ns.top()) {
          if (ns.size() == 1) {
            ns.pop();
            ns.push(nums[i]);
          } else if (ns.size() == 2) {
            int top = ns.top();
            ns.pop();
            if (nums[i] < ns.top()) {
              ns.push(nums[i]);
            } else {
              ns.push(top);
            }
          }
        }
      }

      return false;
    }
};

int main() {
  Solution sol;
  bool ret;
  vector<int> input1 {1, 2, 3, 4, 5};
  ret = sol.increasingTriplet(input1);
  cout << ret << endl;
  vector<int> input2 {5, 1, 2, 3, 4};
  ret = sol.increasingTriplet(input2);
  cout << ret << endl;
  vector<int> input3 {5, 4, 3, 2, 1};
  ret = sol.increasingTriplet(input3);
  cout << ret << endl;
  vector<int> input4 {2,1,5,0,4,6};
  ret = sol.increasingTriplet(input4);
  cout << ret << endl;
  vector<int> input5 {20,100,10,12,5,13};
  ret = sol.increasingTriplet(input5);
  cout << ret << endl;
  return 0;
}
