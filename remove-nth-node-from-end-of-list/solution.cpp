#include <iostream>

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
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode *slow = head;
    ListNode *fast = head;
    for (int i = 0; i < n; ++i) {
      fast = fast->next;
    }

    if (fast == nullptr)
      return head->next;

    while (fast->next != nullptr) {
      slow = slow->next;
      fast = fast->next;
    }
    
    // remove nth element
    slow->next = slow->next->next;

    return head;
  }
};

int main() {
  Solution sol;
  ListNode *ret;
  ret = sol.removeNthFromEnd(new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5))))), 2);
  ret = sol.removeNthFromEnd(new ListNode(1), 1);
  return 0;
}
