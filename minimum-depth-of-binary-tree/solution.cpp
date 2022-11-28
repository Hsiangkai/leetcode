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
private:
  void minDepthImpl(TreeNode *node, int depth, int &minimum) {
    if (node->left == nullptr && node->right == nullptr) {
      if (depth < minimum)
	minimum = depth;
      return;
    }

    if (node->left)
      minDepthImpl(node->left, depth + 1, minimum);
    if (node->right)
      minDepthImpl(node->right, depth + 1, minimum);
  }

public:
  int minDepth(TreeNode* root) {
    if (root == nullptr)
      return 0;

    int minimum = INT_MAX;
    minDepthImpl(root, 1, minimum);

    return minimum;
  }
};

int main() {
  Solution sol;
  int ret;
  ret = sol.minDepth(new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7))));
  cout << ret << endl;
  return 0;
}
