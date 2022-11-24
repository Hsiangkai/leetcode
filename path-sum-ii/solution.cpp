#include <vector>
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
  void traverse(TreeNode *node, int targetSum, int &sum, vector<int> &path, vector<vector<int>> &sol) {

    path.push_back(node->val);
    sum += node->val;

    // process leaf node.
    if (node->left == nullptr && node->right == nullptr) {
      if (targetSum == sum) {
	sol.push_back(path);
      }
    }

    if (node->left != nullptr)
      traverse(node->left, targetSum, sum, path, sol);
    if (node->right != nullptr)
      traverse(node->right, targetSum, sum, path, sol);

    path.pop_back();
    sum -= node->val;
  }

public:
  vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    if (root == nullptr)
      return vector<vector<int>>();

    int sum = 0;
    vector<int> path;
    vector<vector<int>> sol;
    traverse(root, targetSum, sum, path, sol);
    return sol;
  }
};

void printResult(vector<vector<int>> &ret) {
  for (auto v : ret) {
    cout << "[";
    for (auto w : v) {
      cout << w << " ";
    }
    cout << "]" << endl;
  }
}

int main() {
  Solution sol;
  vector<vector<int>> ret;
  ret = sol.pathSum(new TreeNode(1, new TreeNode(2), new TreeNode(3)), 5);
  printResult(ret);
  ret = sol.pathSum(new TreeNode(1, new TreeNode(2), nullptr), 0);
  printResult(ret);
  ret = sol.pathSum(new TreeNode(5, new TreeNode(4, new TreeNode(11, new TreeNode(7), new TreeNode(2)), nullptr),
	                            new TreeNode(8, new TreeNode(13), new TreeNode(4, new TreeNode(5), new TreeNode(1)))), 22);
  printResult(ret);
  return 0;
}
