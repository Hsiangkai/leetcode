#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    bool isValidBSTImpl(TreeNode* root, long upper_bound, long lower_bound) {
      if (root->val >= upper_bound || root->val <= lower_bound)
	return false;

      if (root->left == nullptr && root->right == nullptr) {
	return true;
      }

      if (root->left && root->right) {
	return root->left->val < root->val && isValidBSTImpl(root->left, root->val, lower_bound) &&
	  root->right->val > root->val && isValidBSTImpl(root->right, upper_bound, root->val);
      } else if (root->left) {
	return root->left->val < root->val && isValidBSTImpl(root->left, root->val, lower_bound);
      } else if (root->right) {
	return root->right->val > root->val && isValidBSTImpl(root->right, upper_bound, root->val);
      }

      return false;
    }

public:
    bool isValidBST(TreeNode* root) {
      return isValidBSTImpl(root, LONG_MAX, LONG_MIN);
    }
};

int main() {
  Solution sol;
  bool ret;
  TreeNode root1(5, new TreeNode(4), new TreeNode(6, new TreeNode(3), new TreeNode(7)));
  ret = sol.isValidBST(&root1);
  cout << ret << endl;
  TreeNode root2(5, new TreeNode(1), new TreeNode(4, new TreeNode(3), new TreeNode(6)));
  ret = sol.isValidBST(&root2);
  cout << ret << endl;
  TreeNode root3(2, new TreeNode(1), new TreeNode(3));
  ret = sol.isValidBST(&root3);
  cout << ret << endl;
  TreeNode root4(2147483647);
  ret = sol.isValidBST(&root4);
  cout << ret << endl;
  return 0;
}
