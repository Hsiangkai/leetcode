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
  TreeNode *traverseWithUpper(TreeNode *root, long upper) {
    if (root == nullptr)
      return nullptr;

    TreeNode *leftRet = nullptr;
    TreeNode *rightRet = nullptr;

    if (root->left)
      leftRet = traverseWithUpper(root->left, upper);
    if (root->right)
      rightRet = traverseWithUpper(root->right, upper);

    TreeNode *max = root;
    if (leftRet != nullptr && leftRet->val > max->val)
      max = leftRet;
    if (rightRet != nullptr && rightRet->val > max->val)
      max = rightRet;

    if (max->val > upper)
      return max;

    return nullptr;
  }

  TreeNode *traverseWithLower(TreeNode *root, long lower) {
    if (root == nullptr)
      return nullptr;

    TreeNode *leftRet = nullptr;
    TreeNode *rightRet = nullptr;

    if (root->left)
      leftRet = traverseWithLower(root->left, lower);
    if (root->right)
      rightRet = traverseWithLower(root->right, lower);

    TreeNode *min = root;
    if (leftRet != nullptr && leftRet->val < min->val)
      min = leftRet;
    if (rightRet != nullptr && rightRet->val < min->val)
      min = rightRet;
    
    if (min->val < lower)
      return min;

    return nullptr;
  }

  void traverse(TreeNode* root) {
    if (root == nullptr)
      return;

    TreeNode *leftToUpdate = traverseWithUpper(root->left, root->val);
    TreeNode *rightToUpdate = traverseWithLower(root->right, root->val);
    if (leftToUpdate != nullptr && rightToUpdate != nullptr) {
      int tmp = leftToUpdate->val;
      leftToUpdate->val = rightToUpdate->val;
      rightToUpdate->val = tmp;
      return;
    } else if (leftToUpdate != nullptr) {
      int tmp = root->val;
      root->val = leftToUpdate->val;
      leftToUpdate->val = tmp;
      return;
    } else if (rightToUpdate != nullptr) {
      int tmp = root->val;
      root->val = rightToUpdate->val;
      rightToUpdate->val = tmp;
      return;
    }

    if (root->left) {
      traverse(root->left);
    }
    if (root->right) {
      traverse(root->right);
    }
  }

public:
  void recoverTree(TreeNode* root) {
    traverse(root);
  }

  void printout(TreeNode* root) {
    if (root == nullptr)
      return;

    if (root->left) {
      printout(root->left);
    }
    cout << root->val << " ";
    if (root->right) {
      printout(root->right);
    }
  }
};

int main() {
  Solution sol;
  TreeNode *root1 = new TreeNode(1, new TreeNode(3, nullptr, new TreeNode(2)), nullptr);
  sol.recoverTree(root1);
  sol.printout(root1);
  cout << endl;
  TreeNode *root2 = new TreeNode(3, new TreeNode(1), new TreeNode(4, new TreeNode(2), nullptr));
  sol.recoverTree(root2);
  sol.printout(root2);
  cout << endl;
  TreeNode *root3 = new TreeNode(2, new TreeNode(3), new TreeNode(1));
  sol.recoverTree(root3);
  sol.printout(root3);
  cout << endl;
  TreeNode *root4 = new TreeNode(3, nullptr, new TreeNode(2, nullptr, new TreeNode(1)));
  sol.recoverTree(root4);
  sol.printout(root4);
  cout << endl;
  return 0;
}
