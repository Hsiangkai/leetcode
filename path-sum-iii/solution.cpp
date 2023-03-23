#include <iostream>
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
    int traverse(TreeNode* node, vector<int> &path, int targetSum) {
      if (node == nullptr) {
	return 0;
      }

      int count = 0;
      path.push_back(node->val);
      if (node->left)
	count += traverse(node->left, path, targetSum);
      if (node->right)
	count += traverse(node->right, path, targetSum);

      // check partial sum
      long int sum = 0;
      for (int i = path.size() - 1; i >= 0; --i) {
	sum += path[i];
	if (sum == (long int)targetSum)
	  count++;
      }

      path.pop_back();

      return count;
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
      vector<int> path;
      int ret = traverse(root, path, targetSum);

      return ret;
    }
};

int main() {
  Solution sol;
  int ret;
  ret = sol.pathSum(new TreeNode(10, new TreeNode(5, new TreeNode(3, new TreeNode(3), new TreeNode(-2)), new TreeNode(2, nullptr, new TreeNode(1))), new TreeNode(-3, nullptr, new TreeNode(11))), 8);
  cout << ret << endl;
  return 0;
}
