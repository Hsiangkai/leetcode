#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  int peakIndexInMountainArray(vector<int>& arr) {
    int n = arr.size();
    int begin = 0;
    int end = n - 1;
    int mid;

    while (1) {
      mid = (begin + end) / 2;
      if (arr[mid - 1] < arr[mid]) {
	if (arr[mid + 1] < arr[mid]) {
	  break;
	} else if (arr[mid + 1] > arr[mid]) {
	  begin = mid + 1;
	} else {
	  assert(0);
	}
      } else if (arr[mid - 1] > arr[mid]) {
	end = mid;
      } else {
	assert(0);
      }
    }

    return mid;
  }
};

int main() {
  Solution sol;
  int ret;
  vector<int> data1 {0, 1, 0};
  ret = sol.peakIndexInMountainArray(data1);
  cout << ret << endl;
  vector<int> data2 {0, 2, 1, 0};
  ret = sol.peakIndexInMountainArray(data2);
  cout << ret << endl;
  vector<int> data3 {0, 5, 10, 2};
  ret = sol.peakIndexInMountainArray(data3);
  cout << ret << endl;

  return 0;
}
