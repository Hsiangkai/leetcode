#include <vector>

using namespace std;

class Solution {
public:
  char nextGreatestLetter(vector<char>& letters, char target) {
    for (auto c : letters) {
      if (c - target > 0)
	return c;
    }

    return letters[0];
  }
};
