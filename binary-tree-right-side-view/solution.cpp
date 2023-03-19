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
  void traverse(TreeNode *root, int level, vector<int> &view) {
    if (root == nullptr)
      return;

    if (level + 1 > view.size())
      view.push_back(root->val);
    else
      view[level] = root->val;
    if (root->left)
      traverse(root->left, level + 1, view);
    if (root->right)
      traverse(root->right, level + 1, view);
  }

public:
  vector<int> rightSideView(TreeNode* root) {
    vector<int> view;
    traverse(root, 0, view);
    return view;
  }
};

void print(vector<int> &data) {
  for (auto d : data) {
    cout << d << " ";
  }
  cout << endl;
}

int main() {
  Solution sol;
  vector<int> ret;
  ret = sol.rightSideView(new TreeNode(1, nullptr, new TreeNode(3)));
  print(ret);
  return 0;
}
