#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  int countBattleships(vector<vector<char>>& board) {
    int n = board[0].size();
    int count = 0;
    vector<bool> vertical_mark(n, false);
    for (auto line : board) {
      for (int i = 0; i < n; ++i) {
	char c = line[i];
	if (c == 'X') {
	  count++;
	  if (i != 0 && line[i-1] == 'X')
	    count--;
	  else if (vertical_mark[i] == true)
	    count--;

	  vertical_mark[i] = true;
	} else {
	  vertical_mark[i] = false;
	}
      }
    }

    return count;
  }
};

int main() {
  Solution sol;
  int ret;
  vector<vector<char>> input1 {{'X','.','.','X'},{'.','.','.','X'},{'.','.','.','X'}};
  ret = sol.countBattleships(input1);
  cout << ret << endl;
  vector<vector<char>> input2 {{'.'}};
  ret = sol.countBattleships(input2);
  cout << ret << endl;

  return 0;
}
