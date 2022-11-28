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
public:
  vector<double> averageOfLevels(TreeNode* root) {
    vector<TreeNode *> works;
    works.push_back(root);
    vector<double> ret;

    while (!works.empty()) {
      int level_size = works.size();
      double level_sum = 0.0;
      for (int i = 0; i < level_size; ++i) {
	TreeNode *node = works[i];
	level_sum += node->val;
	if (node->left)
	  works.push_back(node->left);
	if (node->right)
	  works.push_back(node->right);
      }
      ret.push_back(level_sum / level_size);
      works.erase(works.begin(), works.begin() + level_size);
    }

    return ret;
  }
};

void print(vector<double> &ret) {
  for (auto elem : ret) {
    cout << elem << " ";
  }
  cout << endl;
}

int main() {
  Solution sol;
  vector<double> ret;
  // 3,9,20,null,null,15,7
  ret = sol.averageOfLevels(new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7))));
  print(ret);
  return 0;
}
