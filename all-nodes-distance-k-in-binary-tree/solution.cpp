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
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
  vector<int> distanceKChildren(TreeNode* node, int k) {
    vector<TreeNode *> work;
    work.push_back(node);
    int distance = 0;
    while (distance < k) {
      int size = work.size();
      for (int i = 0; i < size; i++) {
	TreeNode *n = work[i];
	if (n->left)
	  work.push_back(n->left);
	if (n->right)
	  work.push_back(n->right);
      }
      work.erase(work.begin(), work.begin() + size);
      distance++;
    }

    vector<int> ret;
    for (auto n : work) {
      ret.push_back(n->val);
    }

    return ret;
  }

  int findTarget(TreeNode *node, TreeNode *target, int k, vector<int> &result) {
    if (node == nullptr)
      return -1;

    if (node->val == target->val) {
      vector<int> tmp = distanceKChildren(node, k);
      result.insert(result.end(), tmp.begin(), tmp.end());
      return 0;
    }

    int val = findTarget(node->left, target, k, result);
    if (val != -1) {
      if ((k - val) == 1) {
	result.push_back(node->val);
      } else if ((k - val) >= 2) {
	if (node->right) {
	  vector<int> tmp = distanceKChildren(node->right, k - val - 2);
          result.insert(result.end(), tmp.begin(), tmp.end());
	}
      }
      return val + 1;
    }

    val = findTarget(node->right, target, k, result);
    if (val != -1) {
      if ((k - val) == 1) {
	result.push_back(node->val);
      } else if ((k - val) >= 2) {
	if (node->left) {
	  vector<int> tmp = distanceKChildren(node->left, k - val - 2);
          result.insert(result.end(), tmp.begin(), tmp.end());
	}
      }
      return val + 1;
    }

    return -1;
  }

public:
  vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    vector<int> result;
    findTarget(root, target, k, result);
    return result;
  }
};

void print(vector<int> &data) {
  for (auto d : data) {
    cout << d << ", ";
  }
  cout << endl;
}

int main() {
  Solution sol;
  vector<int> ret;
  ret = sol.distanceK(new TreeNode(3, new TreeNode(5, new TreeNode(6), new TreeNode(2, new TreeNode(7), new TreeNode(4))), new TreeNode(1, new TreeNode(0), new TreeNode(8))), new TreeNode(5), 2);
  print(ret);

  ret = sol.distanceK(new TreeNode(1), new TreeNode(1), 3);
  print(ret);

  ret = sol.distanceK(new TreeNode(0, nullptr, new TreeNode(1, nullptr, new TreeNode(2, nullptr, new TreeNode(3)))), new TreeNode(1), 2);
  print(ret);

  return 0;
}
