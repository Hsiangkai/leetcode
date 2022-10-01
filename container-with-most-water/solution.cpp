#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
      int left = 0;
      int right = height.size() - 1;
      int max_area = 0;

      while (left < right) {
	int height_l = height[left];
	int height_r = height[right];
	int area;
	if (height_l > height_r) {
	  area = (right - left) * height_r;
	  right--;
	} else {
	  area = (right - left) * height_l;
	  left++;
	}
	max_area = max(max_area, area);
      }

      return max_area;
    }
};

int main() {
  Solution sol;
  vector<int> input1{1,8,6,2,5,4,8,3,7};
  int ret;
  ret = sol.maxArea(input1);
  cout << ret << endl;
  vector<int> input2{1,1};
  ret = sol.maxArea(input2);
  cout << ret << endl;
  return 0;
}
