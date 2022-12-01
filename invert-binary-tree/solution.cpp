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
    TreeNode* invertTree(TreeNode* root) {
      if (root == nullptr)
	return nullptr;

      root->left = invertTree(root->left);
      root->right = invertTree(root->right);
      swap(root->left, root->right);

      return root;
    }
};

int main() {

  Solution sol;
  TreeNode *ret;
  // Input: root = [4,2,7,1,3,6,9]
  ret = sol.invertTree(new TreeNode(4, new TreeNode(2, new TreeNode(1), new TreeNode(3)), new TreeNode(7, new TreeNode(6), new TreeNode(9))));

  return 0;
}
