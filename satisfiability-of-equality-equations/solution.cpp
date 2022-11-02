#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
  void my_union(int a, int b, vector<int> &parent) {
    parent[my_find(a, parent)] = my_find(b, parent);
  }

  int my_find(int a, vector<int> &parent) {
    if (parent[a] != a)
      return my_find(parent[a], parent);
    else
      return a;
  }
public:
  bool equationsPossible(vector<string>& equations) {
    vector<bool> visited(26, false);
    vector<int> parent(26, -1);

    for (auto equation : equations) {
      int lhs = equation[0] - 'a';
      int rhs = equation[3] - 'a';
      bool equal = equation[1] == '=';

      // trivial case
      if (lhs == rhs && equal == false)
	return false;

      if (!equal)
	continue;

      if (!visited[lhs]) {
	visited[lhs] = true;
	parent[lhs] = lhs;
      }
      if (!visited[rhs]) {
	visited[rhs] = true;
	parent[rhs] = rhs;
      }
      if (lhs != rhs)
        my_union(lhs, rhs, parent);
    }

    for (auto equation : equations) {
      int lhs = equation[0] - 'a';
      int rhs = equation[3] - 'a';
      bool equal = equation[1] == '=';

      if (equal)
	continue;

      if (!visited[lhs]) {
	visited[lhs] = true;
	parent[lhs] = lhs;
      }
      if (!visited[rhs]) {
	visited[rhs] = true;
	parent[rhs] = rhs;
      }

      if (my_find(lhs, parent) == my_find(rhs, parent))
	return false;
    }

    return true;
  }
};

int main() {
  Solution sol;
  bool ret;
  vector<string> input1 {"a==b","b!=a"};
  ret = sol.equationsPossible(input1);
  cout << ret << endl;  // false
  vector<string> input2 {"a==b","b==a"};
  ret = sol.equationsPossible(input2);
  cout << ret << endl;  // true
  vector<string> input3 {"a==b","b==c","c==a"};
  ret = sol.equationsPossible(input3);
  cout << ret << endl;  // true
  vector<string> input4 {"a==b","b==c","c!=a"};
  ret = sol.equationsPossible(input4);
  cout << ret << endl;  // false
  vector<string> input5 {"c==c","f!=a","f==b","b==c"};
  ret = sol.equationsPossible(input5);
  cout << ret << endl;  // true
  vector<string> input6 {"e==d","e==a","f!=d","b!=c","a==b"};
  ret = sol.equationsPossible(input6);
  cout << ret << endl;  // true
  vector<string> input7 {"a==b","b!=c","c==a"};
  ret = sol.equationsPossible(input7);
  cout << ret << endl;  // false
  return 0;
}
