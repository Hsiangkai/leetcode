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
  int maxPathSumImpl(TreeNode *node, int &maxSum) {
    if (node == nullptr)
      return 0;
    int leftPathSum = maxPathSumImpl(node->left, maxSum);
    int rightPathSum = maxPathSumImpl(node->right, maxSum);
    int sum = max({leftPathSum + rightPathSum + node->val,
	leftPathSum + node->val,
	rightPathSum + node->val,
	node->val});
    if (sum > maxSum)
      maxSum = sum;

    return max({leftPathSum + node->val, rightPathSum + node->val, node->val});
  }

public:
    int maxPathSum(TreeNode* root) {
      int maxSum = root->val;
      maxPathSumImpl(root, maxSum);
      return maxSum;
    }
};

int main() {
  Solution sol;
  int ret;
  ret = sol.maxPathSum(new TreeNode(1, new TreeNode(2), new TreeNode(3)));
  cout << ret << endl;  // 6
  ret = sol.maxPathSum(new TreeNode(-10, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7))));
  cout << ret << endl;  // 42
  ret = sol.maxPathSum(new TreeNode(-3));
  cout << ret << endl;  // -3
  ret = sol.maxPathSum(new TreeNode(2, new TreeNode(-1), nullptr));
  cout << ret << endl;  // 2
  ret = sol.maxPathSum(new TreeNode(1, new TreeNode(-2), new TreeNode(3)));
  cout << ret << endl;  // 4
  ret = sol.maxPathSum(new TreeNode(-1, new TreeNode(-2, new TreeNode(-6), nullptr), new TreeNode(10, new TreeNode(-3), new TreeNode(-6))));
  cout << ret << endl; // 10
}
