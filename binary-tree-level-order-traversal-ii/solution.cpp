#include <iostream>
#include <vector>
#include <queue>

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
  vector<vector<int>> levelOrderBottom(TreeNode* root) {
    if (root == nullptr)
      return vector<vector<int>>{};

    vector<int> endpoints{0};
    vector<int> traverse;
    queue<TreeNode *> q;

    q.push(root);
    while (q.size()) {
      int n = q.size();
      endpoints.push_back(endpoints.back() + n);

      for (int i = 0; i < n; ++i) {
        TreeNode *node = q.front();
        q.pop();
        traverse.push_back(node->val);
        if (node->left)
          q.push(node->left);
        if (node->right)
          q.push(node->right);
      }
    }

    vector<vector<int>> ret;
    int n = endpoints.size();
    for (int i = n-1; i > 0; --i) {
      int start = endpoints[i-1];
      int end = endpoints[i];
      ret.push_back(vector<int>());
      for (int j = start; j < end; ++j) {
	ret.back().push_back(traverse[j]);
      }
    }

    return ret;
  }
};

void printOut(vector<vector<int>> &data) {
  cout << "[";
  for (auto item : data) {
    cout << "[";
    for (auto val : item) {
      cout << val << ", ";
    }
    cout << "], ";
  }
  cout << "]" << endl;
}

int main() {
  Solution sol;
  vector<vector<int>> ret;
  ret = sol.levelOrderBottom(new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7))));
  printOut(ret);
  return 0;
}
