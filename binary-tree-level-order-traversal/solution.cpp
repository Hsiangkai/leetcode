#include <iostream>
#include <vector>
#include <queue>
#include <utility>

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
  vector<vector<int>> levelOrder(TreeNode* root) {
    if (root == nullptr)
      return vector<vector<int>> {};

    queue<pair<TreeNode *, int>> q;
    q.push(make_pair(root, 0));
    vector<vector<int>> ret;

    while (q.size()) {
      pair<TreeNode *, int> item = q.front();
      TreeNode *node = item.first;
      int level = item.second;
      q.pop();
      if (level == ret.size())
	ret.push_back(vector<int>{});
      ret[level].push_back(node->val);
      if (node->left)
	q.push(make_pair(node->left, level + 1));
      if (node->right)
	q.push(make_pair(node->right, level + 1));
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
  ret = sol.levelOrder(new TreeNode(3, new TreeNode(9, nullptr, nullptr),
   	                               new TreeNode(20, new TreeNode(15), new TreeNode(7))));
  printOut(ret);
  return 0;
}
