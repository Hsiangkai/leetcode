#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
      vector<string> nums_str;
      bool non_zero = false;
      for (auto i = 0; i < nums.size(); ++i) {
	nums_str.push_back(to_string(nums[i]));
	if (nums[i])
	  non_zero = true;
      }
      if (!non_zero)
	return "0";

      sort(nums_str.begin(), nums_str.end(), [](const string &a, const string &b) -> bool {
	string ab = a + b;
	string ba = b + a;
	int n = ab.length();
	for (auto i = 0; i < n; ++i) {
	  if (ab[i] > ba[i])
	    return true;
	  else if (ab[i] < ba[i])
	    return false;
	}
	return true;
	  });

      string ret;
      for (auto i = 0; i < nums_str.size(); ++i) {
	ret += nums_str[i];
      }

      return ret;
    }
};

int main() {
  Solution sol;
  string ret;
  vector<int> input1{10, 2};
  ret = sol.largestNumber(input1);
  cout << ret << endl;
  vector<int> input2{3,30,34,5,9};
  ret = sol.largestNumber(input2);
  cout << ret << endl;
  vector<int> input3{34323,3432};
  ret = sol.largestNumber(input3);   // "343234323"
  cout << ret << endl;
  vector<int> input4{0, 0};
  ret = sol.largestNumber(input4);   // "0"
  cout << ret << endl;
  return 0;
}
