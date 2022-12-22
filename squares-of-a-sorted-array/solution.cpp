#include <vector>
#include <stack>
#include <iostream>

using namespace std;

class Solution {
public:
  vector<int> sortedSquares(vector<int>& nums) {
    int n = nums.size();
    vector<int> results;
    stack<int> store;
    int i;
    for (i = 0; i < n; ++i) {
      int square = nums[i] * nums[i];
      if (nums[i] < 0) {
	store.push(square);
      } else {
	break;
      }
    }

    for (; i < n; ++i) {
      int square = nums[i] * nums[i];
      while (store.size()) {
	int top = store.top();
	if (square > top) {
	  store.pop();
	  results.push_back(top);
	} else {
	  break;
	}
      }
      results.push_back(square);
    }

    while (store.size()) {
      int top = store.top();
      store.pop();
      results.push_back(top);
    }

    return results;
  }
};

void print(vector<int> &data) {
  for (auto d : data) {
    cout << d << " ";
  }
  cout << endl;
}

int main() {
  Solution sol;
  vector<int> ret;
  vector<int> data1 {-4,-1,0,3,10};
  ret = sol.sortedSquares(data1);
  print(ret);
  vector<int> data2 {-7,-3,2,3,11};
  ret = sol.sortedSquares(data2);
  print(ret);
  vector<int> data3 {-1};
  ret = sol.sortedSquares(data3);
  print(ret);
  return 0;
}
