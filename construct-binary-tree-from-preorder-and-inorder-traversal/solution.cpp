#include <vector>

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
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    if (preorder.size() == 0)
      return nullptr;
    if (preorder.size() == 1)
      return new TreeNode(preorder[0]);

    auto it = find(inorder.begin(), inorder.end(), preorder[0]);
    int left_n = it - inorder.begin();
    int right_n = inorder.end() - it - 1;

    vector<int> preorder_left(preorder.begin() + 1, preorder.begin() + 1 + left_n);
    vector<int> preorder_right(preorder.begin() + 1 + left_n, preorder.end());
    vector<int> inorder_left(inorder.begin(), inorder.begin() + left_n);
    vector<int> inorder_right(inorder.begin() + left_n + 1, inorder.end());
    return new TreeNode(preorder[0],
	buildTree(preorder_left, inorder_left),
	buildTree(preorder_right, inorder_right));
  }
};
