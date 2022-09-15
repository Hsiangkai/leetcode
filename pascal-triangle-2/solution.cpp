#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
      vector<int> answer;

      if (rowIndex == 0) {
	answer.push_back(1);
	return answer;
      }
      if (rowIndex == 1) {
	answer.push_back(1);
	answer.push_back(1);
	return answer;
      }

      // initialize
      answer.push_back(1);
      answer.push_back(1);

      vector<int> buffer;
      for (int i = 2; i <= rowIndex; ++i) {
	buffer.clear();
	buffer.push_back(1);
	for (int j = 1; j < i; ++j) {
	  buffer.push_back(answer[j-1] + answer[j]);
	}
	buffer.push_back(1);
	answer.swap(buffer);
      }

      return answer;
    }
};

void output(vector<int> &answer) {
  for (auto val : answer) {
    cout << val;
    cout << " ";
  }
  cout << endl;
}

int main() {
  Solution sol;
  vector<int> answer = sol.getRow(0);
  output(answer);
  answer = sol.getRow(1);
  output(answer);
  answer = sol.getRow(2);
  output(answer);
  answer = sol.getRow(3);
  output(answer);
  answer = sol.getRow(4);
  output(answer);

  return 0;
}
