#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  int totalFruit(vector<int>& fruits) {
    int n = fruits.size();
    vector<int> buckets(n, 0);
    int max_len = 0;
    int left = 0;
    int kind = 0;
    int fruit_0 = -1;
    int fruit_1 = -1;
    int i;
    for (i = 0; i < n; ++i) {
      if (kind == 0) {
	fruit_0 = fruits[i];
	kind++;
      } else if (kind == 1) {
	if (fruits[i] != fruit_0) {
	  fruit_1 = fruits[i];
	  kind++;
	}
      } else if (kind == 2) {
	if (fruits[i] != fruit_0 && fruits[i] != fruit_1) {
	  kind++;
	}
      }
      buckets[fruits[i]]++;

      max_len = max(max_len, i - left);
      while (kind > 2) {
	buckets[fruits[left]]--;
	if (buckets[fruits[left]] == 0) {
	  if (fruit_0 == fruits[left])
	    fruit_0 = fruits[i];
	  else
	    fruit_1 = fruits[i];
	  kind--;
	}
	left++;
      }
    }
    max_len = max(max_len, i - left);

    return max_len;
  }
};

int main() {
  Solution sol;
  int ret;
  vector<int> data1 {1, 2, 1};
  ret = sol.totalFruit(data1);
  cout << ret << endl;  // 3
  vector<int> data2 {0, 1, 2, 2};
  ret = sol.totalFruit(data2);
  cout << ret << endl;  // 3
  vector<int> data3 {1, 2, 3, 2, 2};
  ret = sol.totalFruit(data3);
  cout << ret << endl;  // 4
  vector<int> data4 {3,3,3,1,2,1,1,2,3,3,4};
  ret = sol.totalFruit(data4);
  cout << ret << endl;  // 5
  return 0;
}
