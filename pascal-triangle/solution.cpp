#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
      vector<vector<int>> answer;

      answer.push_back(vector<int>(1, 1));
      if (numRows == 1)
	return answer;

      answer.push_back(vector<int>(2, 1));
      if (numRows == 2)
	return answer;

      // triangle[i][j] = triangle[i-1][j-1] + triangle[i-1][j]
      for (int i = 3; i <= numRows; ++i) {
	vector<int> buffer;
	buffer.push_back(1);
	for (int j = 1; j < i - 1; ++j) {
	  buffer.push_back(answer[i-2][j-1] + answer[i-2][j]);
	}
	buffer.push_back(1);

	answer.push_back(buffer);
      }

      return answer;
    }
};

void output(vector<vector<int>> &answer) {
  for (auto row : answer) {
    for (auto column : row) {
      cout << column;
      cout << " ";
    }
    cout << endl;
  }
}

int main() {
  Solution sol;
  vector<vector<int>> answer = sol.generate(5);
  output(answer);

  return 0;
}
