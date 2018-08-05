#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
  public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
      vector<int>::iterator it = upper_bound(arr.begin(), arr.end(), x);
      if (it != arr.begin())
	--it;

      int left_gap, right_gap;
      int closest_n = 1;
      vector<int>::iterator left = it;
      vector<int>::iterator right = it;
      while (closest_n < k) {
	if (left == arr.begin())
	  break;
	if(right == arr.end()-1)
	  break;

	int diff = (x - *(left-1)) - (*(right+1) - x);
	if (diff <= 0)
	  --left;
	else
	  ++right;

	++closest_n;
      }

      if (left == arr.begin())
	right += (k - closest_n);
      else if (right == arr.end() - 1)
	left -= (k - closest_n);

      vector<int> closest(left, right+1);
      return closest;
    }
};

int main()
{
  int arr[] = {0, 0, 0, 1, 3, 5, 6, 7, 8, 8};
  vector<int> query(arr, arr+10);
  Solution sol;
  vector<int> ans = sol.findClosestElements(query, 2, 2);
  for (auto i : ans)
    cout << i << " ";
  cout << endl;
}
