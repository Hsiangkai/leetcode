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
  bool search(TreeNode* root, int k, int &n, int &val) {

    if (root == nullptr) {
      n = 0;
      return false;
    }

    int count = 0;
    if (root->left) {
      int left_n;
      bool found = search(root->left, k, left_n, val);
      if (found)
	return true;
      count += left_n;
    }
    count++;
    if (k == count) {
      val = root->val;
      return true;
    }
    if (root->right) {
      int right_n;
      bool found = search(root->right, k - count, right_n, val);
      if (found)
	return true;
      count += right_n;
    }

    n = count;
    return false;
  }

public:
    int kthSmallest(TreeNode* root, int k) {
      int n;
      int val;
      search(root, k, n, val);

      return val;
    }
};

int main() {
  Solution sol;
  int val;
  val = sol.kthSmallest(new TreeNode(5, new TreeNode(3, new TreeNode(2, new TreeNode(1), nullptr), new TreeNode(4)), new TreeNode(6)), 3);
  cout << val << endl;

  return 0;
}
