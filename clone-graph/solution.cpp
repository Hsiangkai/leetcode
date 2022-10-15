#include <vector>
#include <queue>
#include <map>

using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
      Node *root = nullptr;
      queue<Node *> q;
      queue<Node *> copy_q;
      vector<bool> visited;
      map<int, Node *> dict;
      if (node != nullptr) {
	root = new Node(node->val);
	dict[node->val] = root;
        q.push(node);
        copy_q.push(root);
	visited.resize(node->val + 1, false);
	visited[node->val] = true;
      }
      // BFS
      while (q.size()) {
	Node *tmp = q.front();
	q.pop();
	Node *parent = copy_q.front();
	copy_q.pop();
	// create a new node according to the popped node.
	for (Node *n : tmp->neighbors) {
	  Node *new_node;
	  if (n->val < visited.size() && visited[n->val] == true) {
	    new_node = dict[n->val];
	  } else {
	    new_node = new Node(n->val);
	    dict[n->val] = new_node;
	    q.push(n);
	    copy_q.push(new_node);
	    if (n->val >= visited.size())
	      visited.resize(n->val + 1, false);
	    visited[n->val] = true;
	  }
	  parent->neighbors.push_back(new_node);
	}
      }

      return root; }
};

int main() {
  Node *node1 = new Node(1);
  Node *node2 = new Node(2);
  Node *node3 = new Node(3);
  Node *node4 = new Node(4);
  node1->neighbors = vector<Node *> {node2, node4};
  node2->neighbors = vector<Node *> {node1, node3};
  node3->neighbors = vector<Node *> {node2, node4};
  node4->neighbors = vector<Node *> {node1, node3};

  Solution sol;
  Node *ans = sol.cloneGraph(node1);
  return 0;
}
