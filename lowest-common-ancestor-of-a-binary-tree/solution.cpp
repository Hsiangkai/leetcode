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
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
  void traverse(TreeNode *node, TreeNode *p, TreeNode *q,
      vector<TreeNode *> &path1, vector<TreeNode *> &path2,
      bool &found_p, bool &found_q) {

    if (found_p && found_q)
      return;
    if (node == nullptr)
      return;

    if (!found_p)
      path1.push_back(node);
    if (!found_q)
      path2.push_back(node);

    if (node == p)
      found_p = true;
    if (node == q)
      found_q = true;

    if (node->left)
      traverse(node->left, p, q, path1, path2, found_p, found_q);
    if (node->right)
      traverse(node->right, p, q, path1, path2, found_p, found_q);
    
    if (!found_p)
      path1.pop_back();
    if (!found_q)
      path2.pop_back();
  }

public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    vector<TreeNode *> path1;
    vector<TreeNode *> path2;
    bool found_p = false;
    bool found_q = false;
    traverse(root, p, q, path1, path2, found_p, found_q);
    int n = path1.size();
    int m = path2.size();
    int i;
    for (i = 0; i < n && i < m; ++i) {
      if (path1[i] != path2[i])
	return path1[i - 1];
    }

    if (i == n || i == m) {
      return path1[i - 1];
    }

    return nullptr;
  }
};
