#include <iostream>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
  ListNode *detectCycle(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;

    do {
      if (fast == nullptr || fast->next == nullptr)
	return nullptr;

      fast = fast->next->next;
      slow = slow->next;
    } while (fast != slow);

    slow = head;
    while (slow != fast) {
      slow = slow->next;
      fast = fast->next;
    }

    return slow;
  }
};

int main() {
  return 0;
}
