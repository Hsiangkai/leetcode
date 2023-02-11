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
  ListNode* reverseBetween(ListNode* head, int left, int right) {
    ListNode *first = head;
    ListNode *last = head;
    int n = right - left;
    for (int i = 0; i < n; ++i) {
      last = last->next;
    }

    ListNode *prev = nullptr;
    ListNode *next = nullptr;
    for (int i = 0; i < left - 1; ++i) {
      prev = first;
      first = first->next;
      last = last->next;
    }
    next = last->next;

    // reverse the list
    ListNode *prev_curr = next;
    ListNode *curr = first;
    ListNode *next_curr = curr->next;
    while (curr != next) {
      curr->next = prev_curr;
      prev_curr = curr;
      curr = next_curr;
      if (next_curr)
        next_curr = next_curr->next;
    }
    if (prev != nullptr)
      prev->next = prev_curr;
    else
      head = prev_curr;

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
  ret = sol.reverseBetween(head, 1, 5);
  printList(ret);
  return 0;
}
