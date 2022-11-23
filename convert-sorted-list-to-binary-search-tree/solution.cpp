#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
  TreeNode *convert(vector<int> &data, int start, int end, bool isLeft) {
    int n = end - start;

    if (n == 0)
      return nullptr;

    if (n == 1)
      return new TreeNode(data[start]);

    if (n == 2) {
      if (isLeft)
	return new TreeNode(data[start+1], new TreeNode(data[start]), nullptr);
      else
	return new TreeNode(data[start], nullptr, new TreeNode(data[start+1]));
    }

    if (n == 3)
      return new TreeNode(data[start+1], new TreeNode(data[start]), new TreeNode(data[start+2]));

    int mid = start + n / 2;
    return new TreeNode(data[mid], convert(data, start, mid, true), convert(data, mid+1, end, false));
  }

public:
  TreeNode* sortedListToBST(ListNode* head) {
    if (head == nullptr)
      return nullptr;

    // convert linked list to vector
    vector<int> data;
    ListNode *current = head;
    while (current != nullptr) {
      data.push_back(current->val);
      current = current->next;
    }

    return convert(data, 0, data.size(), false);
  }
};

int main() {
  Solution sol;
  TreeNode *ret;
  // ret = sol.sortedListToBST(new ListNode(-10, new ListNode(-3, new ListNode(0, new ListNode(5, new ListNode(9))))));
  ret = sol.sortedListToBST(new ListNode(0, new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5, new ListNode(6, new ListNode(7, new ListNode(8))))))))));
  return 0;
}
