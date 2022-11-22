#include <stack>
#include <vector>
#include <iostream>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

    if (root == nullptr)
      return vector<vector<int>> {};

    bool leftToRight = true;
    stack<TreeNode *> leftToRightStack;
    stack<TreeNode *> rightToLeftStack;
    stack<TreeNode *> *currentStack = &leftToRightStack;
    stack<TreeNode *> *nextStack = &rightToLeftStack;

    currentStack->push(root);

    vector<vector<int>> ret;
    while (currentStack->size()) {
      ret.push_back(vector<int>());
      while (!currentStack->empty()) {
	TreeNode *node = currentStack->top();
	currentStack->pop();
	ret.back().push_back(node->val);
	if (leftToRight) {
	  if (node->left)
	    nextStack->push(node->left);
	  if (node->right)
	    nextStack->push(node->right);
	} else {
	  if (node->right)
	    nextStack->push(node->right);
	  if (node->left)
	    nextStack->push(node->left);
	}
      }

      leftToRight = !leftToRight;
      currentStack = leftToRight ? &leftToRightStack : &rightToLeftStack;
      nextStack = leftToRight ? &rightToLeftStack : &leftToRightStack;
    }

    return ret;
  }
};

void printOut(vector<vector<int>> &data) {
  cout << "[";
  for (auto item : data) {
    cout << "[";
    for (auto val : item) {
      cout << val << ", ";
    }
    cout << "], ";
  }
  cout << "]" << endl;
}

int main() {
  Solution sol;
  vector<vector<int>> ret;
  ret = sol.zigzagLevelOrder(new TreeNode(3,
	                     new TreeNode(9),
			     new TreeNode(20, new TreeNode(15), new TreeNode(7))));
  printOut(ret);
  ret = sol.zigzagLevelOrder(nullptr);
  printOut(ret);

  return 0;
}
