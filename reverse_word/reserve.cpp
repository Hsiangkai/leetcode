#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
  public:
    void reverseWords(string &s) {

      vector<string> stack;

      // Trim spaces.
      s.erase(0, s.find_first_not_of(" "));
      s.erase(s.find_last_not_of(" ") + 1);

      if (s.empty())
	return;

      size_t start = 0;
      size_t end = 0;
      while (end != s.length()) {
	start = s.find_first_not_of(" ", end);
	end = s.find_first_of(" ", start);
	if (end == string::npos)
	  end = s.length();
	stack.push_back(string(s.substr(start, end-start)));
      }

      s.clear();
      while (!stack.empty()) {
	auto item = stack.back();
	s.append(item);
	s.append(" ");
	stack.pop_back();
      }

      // Remove last ' '.
      s.erase(s.end() - 1);
    }
};

int main()
{
  Solution sol;
  string input("  the      sky  is   blue  ");

  sol.reverseWords(input);
  cout << input << endl;

  return 0;
}
