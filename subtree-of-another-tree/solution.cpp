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
  bool isSameTree(TreeNode* a, TreeNode* b) {
    if (a == nullptr && b == nullptr)
      return true;
    if (a == nullptr)
      return false;
    if (b == nullptr)
      return false;

    if (a->val != b->val)
      return false;

    return isSameTree(a->left, b->left) && isSameTree(a->right, b->right);
  }

public:
  bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if (root == nullptr && subRoot == nullptr)
      return true;
    if (root == nullptr)
      return false;
    if (subRoot == nullptr)
      return true;

    if (root->val == subRoot->val) {
      if (isSameTree(root, subRoot))
	return true;
    }
    if (isSubtree(root->left, subRoot))
      return true;
    if (isSubtree(root->right, subRoot))
      return true;

    return false;
  }
};

int main() {
  Solution sol;
  bool ret;
  ret = sol.isSubtree(new TreeNode(1, new TreeNode(1), nullptr), new TreeNode(1));
  cout << ret << endl;
  return 0;
}
