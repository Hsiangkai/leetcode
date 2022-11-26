#include <vector>
#include <unordered_map>

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
  TreeNode *build(vector<int>& inorder, int in_start, int in_end,
      vector<int>& postorder, int post_start, int post_end,
      unordered_map<int, int> &val2Idx) {
    if (in_start >= in_end)
      return nullptr;
    int root_val = postorder[post_end - 1];
    int root_idx = val2Idx[root_val];
    TreeNode *ret = new TreeNode(root_val);
    ret->left = build(inorder, in_start, root_idx,
	postorder, post_start, post_start + (root_idx - in_start), val2Idx);
    ret->right = build(inorder, root_idx + 1, in_end,
	postorder, post_start + (root_idx - in_start), post_end - 1, val2Idx);

    return ret;
  }
public:
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    // construct value -> index mapping
    unordered_map<int, int> val2Idx;
    int n = inorder.size();
    for (int i = 0; i < n; ++i) {
      val2Idx[inorder[i]] = i;
    }

    return build(inorder, 0, n, postorder, 0, n, val2Idx);
  }
};
