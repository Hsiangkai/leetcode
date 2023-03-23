#include <iostream>
#include <queue>

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
  Node* connect(Node* root) {
    if (root == nullptr)
      return nullptr;

    queue<Node *> q;
    q.push(root);
    int n = 1;
    while (n) {
      for (int i = 0; i < n; ++i) {
	auto curr = q.front();
	q.pop();
	if (i != n-1)
	  curr->next = q.front();
	else
	  curr->next = nullptr;

	if (curr->left)
	  q.push(curr->left);
	if (curr->right)
	  q.push(curr->right);
      }
      n = q.size();
    }

    return root;
  }
};