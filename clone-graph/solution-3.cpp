#include <vector>
#include <queue>
#include <map>
#include <iostream>

using namespace std;

/*
// Definition for a Node.
*/
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
  enum {
    UNVISITED = 0,
    PROCESSING,
    VISITED,
  };

  public:
    Node* cloneGraph(Node* node) {
      if (node == nullptr)
	return nullptr;

      map<int, Node *> new_nodes;
      vector<int> visited(101, UNVISITED);

      Node *head = new Node(node->val);
      new_nodes[node->val] = head;
      visited[node->val] = VISITED;

      queue<Node *> work;
      for (Node *neighbor : node->neighbors) {
	work.push(neighbor);
	visited[neighbor->val] = PROCESSING;
      }

      while (!work.empty()) {
	Node *curr = work.front();
	work.pop();
	visited[curr->val] = VISITED;

	Node *new_node = new Node(curr->val);
	new_nodes[curr->val] = new_node;

	for (Node *neighbor : curr->neighbors) {
	  auto it_n = new_nodes.find(neighbor->val);
	  if (it_n != new_nodes.end()) {
	    Node *found = it_n->second;
	    new_node->neighbors.push_back(found);
	    found->neighbors.push_back(new_node);
	  } else {
	    if (visited[neighbor->val] == UNVISITED) {
	      work.push(neighbor);
	      visited[neighbor->val] = PROCESSING;
	    }
	  }
	}
      }

      return head;
    }
};

void printGraph(Node *node) {
  queue<Node *> work;
  work.push(node);
  vector<bool> visited(5, false);

  while (!work.empty()) {
    Node *curr = work.front();
    work.pop();

    if (visited[curr->val] == false) {
      cout << curr->val << ": ";
      for (Node *neighbor : curr->neighbors) {
	cout << neighbor->val << " ";
	if (visited[neighbor->val] == false)
	  work.push(neighbor);
      }
      cout << endl;
      visited[curr->val] = true;
    }
  }
}

int main() {
  Solution sol;
  Node *ret;
  Node *node1 = new Node(1);
  Node *node2 = new Node(2);
  Node *node3 = new Node(3);
  Node *node4 = new Node(4);
  node1->neighbors.push_back(node2);
  node1->neighbors.push_back(node4);
  node2->neighbors.push_back(node1);
  node2->neighbors.push_back(node3);
  node3->neighbors.push_back(node2);
  node3->neighbors.push_back(node4);
  node4->neighbors.push_back(node1);
  node4->neighbors.push_back(node3);

  ret = sol.cloneGraph(node1);
  printGraph(ret);
  return 0;
}
