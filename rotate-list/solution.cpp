#include <iostream>

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

class Solution {
public:
  ListNode* rotateRight(ListNode* head, int k) {
    if (head == nullptr)
      return nullptr;

    ListNode *end = head;
    int n = 1;
    while (end->next != nullptr) {
      n++;
      end = end->next;
    }
    end->next = head;

    k = k % n;
    k = n - k;
    ListNode *curr = head;
    while (k > 1) {
      curr = curr->next;
      k--;
    }
    head = curr->next;
    curr->next = nullptr;

    return head;
  }
};

void printList(ListNode *head) {
  ListNode *curr = head;
  while (curr) {
    cout << curr->val << " ";
    curr = curr->next;
  }
  cout << endl;
}

int main() {
  Solution sol;
  ListNode *ret;
  ListNode *head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
  ret = sol.rotateRight(head, 0);
  printList(ret);

  ListNode *head2 = new ListNode(1);
  ret = sol.rotateRight(head2, 0);
  printList(ret);
  return 0;
}
