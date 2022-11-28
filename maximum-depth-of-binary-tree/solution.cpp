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
    int maxDepth(TreeNode* root) {
      if (root == nullptr)
	return 0;

      return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

int main() {
  Solution sol;
  int ret;
  ret = sol.maxDepth(new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7))));
  cout << ret << endl;
  return 0;
}
