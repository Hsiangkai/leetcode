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
  bool hasPathSumImpl(TreeNode *node, int sum, int targetSum) {
    if (node->left == nullptr && node->right == nullptr) {
      if (sum == targetSum)
	return true;
    }

    bool ret = false;
    if (node->left) {
      ret |= hasPathSumImpl(node->left, sum + node->left->val, targetSum);
    }
    if (node->right) {
      ret |= hasPathSumImpl(node->right, sum + node->right->val, targetSum);
    }

    return ret;
  }

public:
  bool hasPathSum(TreeNode* root, int targetSum) {
    if (root == nullptr)
      return false;

    return hasPathSumImpl(root, root->val, targetSum);
  }
};

int main() {
  Solution sol;
  bool ret;
  ret = sol.hasPathSum(new TreeNode(5, new TreeNode(4, new TreeNode(11, new TreeNode(7), new TreeNode(2)), nullptr), new TreeNode(8, new TreeNode(13), new TreeNode(4, nullptr, new TreeNode(1)))), 22);
  cout << ret << endl;
  ret = sol.hasPathSum(new TreeNode(1, new TreeNode(2), new TreeNode(3)), 5);
  cout << ret << endl;
  return 0;
}
