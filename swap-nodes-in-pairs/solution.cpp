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
  ListNode* swapPairs(ListNode* head) {
    if (head == nullptr)
      return nullptr;
    if (head->next == nullptr)
      return head;

    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *prev = dummy;
    ListNode *curr = head;
    ListNode *next = head->next;

    while (curr != nullptr && next != nullptr) {
      curr->next = next->next;
      next->next = curr;
      prev->next = next;
      prev = curr;
      curr = prev->next;
      if (curr)
	next = curr->next;
      else
	next = nullptr;
    }

    head = dummy->next;
    delete dummy;

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
  ListNode *head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4))));
  ret = sol.swapPairs(head);
  printList(ret);
  ListNode *head0 = nullptr;
  ret = sol.swapPairs(head0);
  printList(ret);
  ListNode *head1 = new ListNode(1);
  ret = sol.swapPairs(head1);
  printList(ret);
  ListNode *head_odd = new ListNode(1, new ListNode(2, new ListNode(3)));
  ret = sol.swapPairs(head_odd);
  printList(ret);
  return 0;
}
