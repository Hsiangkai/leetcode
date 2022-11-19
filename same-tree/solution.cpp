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
  bool isSameTree(TreeNode* p, TreeNode* q) {
    if (p == nullptr && q == nullptr)
      return true;
    else if (p == nullptr)
      return false;
    else if (q == nullptr)
      return false;

    if (p->val == q->val &&
	isSameTree(p->left, q->left) &&
	isSameTree(p->right, q->right))
      return true;
    return false;
  }
};

int main() {
  Solution sol;
  bool ret;
  ret = sol.isSameTree(new TreeNode(1, new TreeNode(2), new TreeNode(3)),
                       new TreeNode(1, new TreeNode(2), new TreeNode(3)));
  cout << ret << endl;
  ret = sol.isSameTree(new TreeNode(1, new TreeNode(2), nullptr),
                       new TreeNode(1, nullptr, new TreeNode(2)));
  cout << ret << endl;
  ret = sol.isSameTree(new TreeNode(1, new TreeNode(2), new TreeNode(1)),
                       new TreeNode(1, new TreeNode(1), new TreeNode(2)));
  cout << ret << endl;
  return 0;
}
