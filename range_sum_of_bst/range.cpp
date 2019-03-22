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
  void visit(TreeNode* current, int L, int R, int& sum);
public:
  int rangeSumBST(TreeNode* root, int L, int R) {
    int sum = 0;
    visit(root, L, R, sum);

    return sum;
  }
};

void Solution::visit(TreeNode* current, int L, int R, int& sum)
{
  if (!current)
    return;

  if (current->val > L)
    visit(current->left, L, R, sum);

  static bool start_to_sum = false;
  bool last_one = false;
  if (current->val == L) { // start summation
    start_to_sum = true;
  } else if (current->val == R) { // end summation
    start_to_sum = false;
    last_one = true;
  }

  if (start_to_sum) {
    sum += current->val;
  } else if (last_one) {
    sum += current->val;
  }

  if (current->val < R)
    visit(current->right, L, R, sum);
}
