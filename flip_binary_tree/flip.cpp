#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
  bool traverse_left(TreeNode *current, TreeNode *parent, vector<int>& voyage, int& index, vector<int>& flips);
  bool traverse_right(TreeNode *current, TreeNode *parent, vector<int>& voyage, int& index, vector<int>& flips);

public:
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
      vector<int> flip_nodes;
      if (root->val != voyage[0]) {
	flip_nodes.push_back(-1);
	return flip_nodes;
      }
      int index = 1;
      if (!traverse_left(root->left, root, voyage, index, flip_nodes)) {
	flip_nodes.clear();
	flip_nodes.push_back(-1);
	return flip_nodes;
      }
      if (!traverse_right(root->right, root, voyage, index, flip_nodes)) {
	flip_nodes.clear();
	flip_nodes.push_back(-1);
	return flip_nodes;
      }

      return flip_nodes;
    }
};

bool Solution::traverse_left(TreeNode *current, TreeNode *parent, vector<int>& voyage, int& index, vector<int>& flips)
{
  if (current == NULL)
    return true;

  // visit root
  if (current->val != voyage[index]) {  // need to flip
    // flip
    TreeNode *tmp = parent->left;
    parent->left = parent->right;
    parent->right = tmp;
    // update current
    current = parent->left;
    if (current == NULL || current->val != voyage[index])
      return false;

    flips.push_back(parent->val);
  }
  index++;

  // visit left tree
  if (!traverse_left(current->left, current, voyage, index, flips))
    return false;
  // visit right tree
  if (!traverse_right(current->right, current, voyage, index, flips))
    return false;

  return true;
}

bool Solution::traverse_right(TreeNode *current, TreeNode *parent, vector<int>& voyage, int& index, vector<int>& flips)
{
  if (current == NULL)
    return true;

  if (current->val != voyage[index]) {
    return false;
  }
  index++;

  if (!traverse_left(current->left, current, voyage, index, flips))
    return false;

  if (!traverse_right(current->right, current, voyage, index, flips))
    return false;

  return true;
}

int main()
{
  TreeNode root(1);
  vector<int> voyage = {1, 3, 2};
  //vector<int> voyage = {2, 1};
  root.left = new TreeNode(2);
  root.right = new TreeNode(3);

  Solution sol;
  vector<int> flips = sol.flipMatchVoyage(&root, voyage);
  cout << flips[0] << endl;

  return 0;
}
