#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
  vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> prefix;
    vector<int> postfix;
    int n = nums.size();
    int product = 1;
    for (int i = 0; i < n; ++i) {
      product *= nums[i];
      prefix.push_back(product);
    }
    product = 1;
    for (int i = n - 1; i >= 0; --i) {
      product *= nums[i];
      postfix.push_back(product);
    }
    reverse(postfix.begin(), postfix.end());

    vector<int> results;
    for (int i = 0; i < n; ++i) {
      product = 1;
      if (i - 1 >= 0)
	product *= prefix[i-1];
      if (i + 1 < n)
	product *= postfix[i+1];
      results.push_back(product);
    }

    return results;
  }
};

void print(vector<int> &data) {
  for (int d : data) {
    cout << d << " ";
  }
  cout << endl;
}

int main() {
  Solution sol;
  vector<int> ret;
  vector<int> data1 {1, 2, 3, 4};
  ret = sol.productExceptSelf(data1);
  print(ret);
  return 0;
}
