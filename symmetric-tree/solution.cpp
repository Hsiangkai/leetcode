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
  bool isSymmetricTree(TreeNode *p, TreeNode *q) {
    if (p == nullptr && q == nullptr)
      return true;
    else if (p == nullptr)
      return false;
    else if (q == nullptr)
      return false;

    if (p->val == q->val)
      return isSymmetricTree(p->left, q->right) && isSymmetricTree(p->right, q->left);
    else
      return false;
  }

public:
  bool isSymmetric(TreeNode* root) {
    if (root == nullptr)
      return true;

    return isSymmetricTree(root->left, root->right);
  }
};

int main() {
  Solution sol;
  bool ret;
  ret = sol.isSymmetric(new TreeNode(1, new TreeNode(2, new TreeNode(3), new TreeNode(4)),
	                                new TreeNode(2, new TreeNode(4), new TreeNode(3))));
  cout << ret << endl;
  ret = sol.isSymmetric(new TreeNode(1, new TreeNode(2, nullptr, new TreeNode(3)),
	                                new TreeNode(2, nullptr, new TreeNode(3))));
  cout << ret << endl;
  return 0;
}
