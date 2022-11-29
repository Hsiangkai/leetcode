#include <iostream>

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
  TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
    if (root1 == nullptr && root2 == nullptr)
      return nullptr;

    TreeNode *new_root;
    if (root1 != nullptr && root2 != nullptr) {
      new_root = new TreeNode(root1->val + root2->val);
      new_root->left = mergeTrees(root1->left, root2->left);
      new_root->right = mergeTrees(root1->right, root2->right);
    } else if (root1) {
      new_root = root1;
    } else if (root2) {
      new_root = root2;
    }

    return new_root;
  }
};

int main() {
  return 0;
}
