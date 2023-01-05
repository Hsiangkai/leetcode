#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
  enum Dir {
    LEFT,
    RIGHT,
    TOP,
    DOWN,
  };
private:
  bool go(vector<vector<char>>& board, vector<vector<bool>> &visited, int x, int y, string &word, int pos, int from) {
    if (x < 0 || x >= board[0].size())
      return false;
    if (y < 0 || y >= board.size())
      return false;

    if (visited[y][x])
      return false;

    if (word[pos] != board[y][x])
      return false;

    if (pos == word.size() - 1)
      return true;

    visited[y][x] = true;
    if (from == LEFT) {
      if (go(board, visited, x + 1, y, word, pos + 1, LEFT))
	return true;
      if (go(board, visited, x, y + 1, word, pos + 1, TOP))
	return true;
      if (go(board, visited, x, y - 1, word, pos + 1, DOWN))
	return true;
    } else if (from == RIGHT) {
      if (go(board, visited, x - 1, y, word, pos + 1, RIGHT))
	return true;
      if (go(board, visited, x, y + 1, word, pos + 1, TOP))
	return true;
      if (go(board, visited, x, y - 1, word, pos + 1, DOWN))
	return true;
    } else if (from == TOP) {
      if (go(board, visited, x + 1, y, word, pos + 1, LEFT))
	return true;
      if (go(board, visited, x - 1, y, word, pos + 1, RIGHT))
	return true;
      if (go(board, visited, x, y + 1, word, pos + 1, TOP))
	return true;
    } else if (from == DOWN) {
      if (go(board, visited, x + 1, y, word, pos + 1, LEFT))
	return true;
      if (go(board, visited, x - 1, y, word, pos + 1, RIGHT))
	return true;
      if (go(board, visited, x, y - 1, word, pos + 1, DOWN))
	return true;
    }
    visited[y][x] = false;

    return false;
  }

  void clearVisited(vector<vector<bool>> &visited) {
    for (auto row : visited) {
      row.assign(row.size(), false);
    }
  }

public:
  bool exist(vector<vector<char>>& board, string word) {
    vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
    for (int i = 0; i < board.size(); ++i) {
      for (int j = 0; j < board[0].size(); ++j) {
	clearVisited(visited);
	if (go(board, visited, j, i, word, 0, LEFT))
	  return true;
	clearVisited(visited);
	if (go(board, visited, j, i, word, 0, RIGHT))
	  return true;
	clearVisited(visited);
	if (go(board, visited, j, i, word, 0, TOP))
	  return true;
	clearVisited(visited);
	if (go(board, visited, j, i, word, 0, DOWN))
	  return true;
      }
    }
    return false;
  }
};

int main() {
  Solution sol;
  bool ret;
  vector<vector<char>> data1 {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
  ret = sol.exist(data1, "ABCCED");
  cout << ret << endl;
  vector<vector<char>> data2 {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
  ret = sol.exist(data2, "SEE");
  cout << ret << endl;
  vector<vector<char>> data3 {{'a','a','a','a'},{'a','a','a','a'},{'a','a','a','a'}};
  ret = sol.exist(data3, "aaaaaaaaaaaaa");
  cout << ret << endl;
  return 0;
}
