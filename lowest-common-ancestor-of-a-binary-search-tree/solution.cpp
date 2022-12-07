#include <iostream>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

      TreeNode *current = root;

      int pval = p->val;
      int qval = q->val;
      while (current != nullptr) {
	int cval = current->val;

	if (cval == pval)
	  return current;
	if (cval == qval)
	  return current;

	if (pval > cval && qval > cval) {
	  current = current->right;
	} else if (pval < cval && qval < cval) {
	  current = current->left;
	} else {
	  return current;
	}
      }

      return current;
    }
};

int main() {
  Solution sol;
  TreeNode *ret;
  ret = sol.lowestCommonAncestor(new TreeNode(5, new TreeNode(3, new TreeNode(2, new TreeNode(1), nullptr), new TreeNode(4)), new TreeNode(6)), new TreeNode(1), new TreeNode(4));

  cout << ret->val << endl;

  return 0;
}
