#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    int len = flowerbed.size();
    int count = 0;
    int zeros = 1;
    for (int i = 0; i < len; ++i) {
      if (flowerbed[i] == 1) {
	zeros = 0;
      } else if (flowerbed[i] == 0) {
	zeros++;
	if (zeros == 3) {
	  count++;
	  zeros = 1;
	}
      }
    }
    if (zeros == 2)
      count++;

    if (count >= n)
      return true;
    
    return false;
  }
};

int main() {
  Solution sol;
  bool ret;
  vector<int> input1 {1, 0, 0, 0, 1};
  ret = sol.canPlaceFlowers(input1, 1);
  cout << ret << endl;
  ret = sol.canPlaceFlowers(input1, 2);
  cout << ret << endl;

  return 0;
}
