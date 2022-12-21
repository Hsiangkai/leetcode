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
  int maxPath(TreeNode *node, int &diameter) {
    if (node == nullptr)
      return 0;

    int leftPath = maxPath(node->left, diameter);
    int rightPath = maxPath(node->right, diameter);

    if (leftPath + rightPath > diameter) {
      diameter = leftPath + rightPath;
    }

    return max(leftPath, rightPath) + 1;
  }

public:
    int diameterOfBinaryTree(TreeNode* root) {
      if (root == nullptr)
	return 0;

      int diameter = INT_MIN;
      maxPath(root, diameter);
      return diameter;
    }
};

int main() {
  return 0;
}
