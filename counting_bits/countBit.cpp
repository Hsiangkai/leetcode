#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> countBits(int num) {
    vector<int> bits;

    // init
    bits.push_back(0);
    bits.push_back(1);

    if (num == 0) {
      bits.pop_back();
      return bits;
    } else if (num == 1) {
      return bits;
    }

    int low = 2;
    int high = 4;
    for (int i = 2; i <= num; i++) {
      if (i >= low && i <= high-1) {
	bits.push_back(bits[i-low]+1);
      } else {
	low = low << 1;
	high = high << 1;
	i--;
      }
    }

    return bits;
  }
};

int main()
{
  Solution sol;
  vector<int> s = sol.countBits(8);
  for (auto i : s) {
    cout << i << " ";
  }
  cout << endl;
  return 0;
}
