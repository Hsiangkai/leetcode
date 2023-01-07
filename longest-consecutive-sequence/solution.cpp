#include <vector>
#include <set>
#include <iostream>

using namespace std;

class Solution {
public:
  int longestConsecutive(vector<int>& nums) {
    set<int> table;
    for (int num : nums) {
      table.insert(num);
    }
    int max_length = 0;
    for (auto it = table.begin(); it != table.end(); ++it) {
      int num = *it;
      int length;
      if (table.find(num-1) == table.end()) {
	length = 1;
	while (table.find(num+1) != table.end()) {
	  num++;
	  length++;
	}
	
	if (length > max_length)
	  max_length = length;
      }
    }

    return max_length;
  }
};

int main() {
  Solution sol;
  int ret;
  vector<int> data1 {100,4,200,1,3,2};
  ret = sol.longestConsecutive(data1);
  cout << ret << endl;
  vector<int> data2 {0,3,7,2,5,8,4,6,0,1};
  ret = sol.longestConsecutive(data2);
  cout << ret << endl;
  return 0;
}
