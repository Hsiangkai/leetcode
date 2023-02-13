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
  ListNode* oddEvenList(ListNode* head) {
    if (head == nullptr)
      return nullptr;

    ListNode *odd = head;
    ListNode *even = head->next;
    ListNode *odd_curr = odd;
    ListNode *even_curr = even;

    while (odd_curr && even_curr) {
      odd_curr->next = even_curr->next;
      if (even_curr->next) {
	odd_curr = even_curr->next;
      } else {
	odd_curr->next = even;
	break;
      }
      even_curr->next = odd_curr->next;
      even_curr = odd_curr->next;
    }
    odd_curr->next = even;

    return odd;
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
  ret = sol.oddEvenList(head);
  printList(ret);
  ret = sol.oddEvenList(nullptr);
  printList(ret);
  ret = sol.oddEvenList(new ListNode(1));
  printList(ret);
  ret = sol.oddEvenList(new ListNode(1, new ListNode(2)));
  printList(ret);
  return 0;
}
