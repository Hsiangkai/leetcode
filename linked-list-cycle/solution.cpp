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
    bool hasCycle(ListNode *head) {
      if (head == nullptr)
	return false;

      ListNode *fast = head;
      ListNode *slow = head;
      while (1) {
	if (fast == nullptr || fast->next == nullptr)
	  return false;
	fast = fast->next->next;
	slow = slow->next;

	if (fast == slow)
	  return true;
      }

      return false;
    }
};

int main() {
  return 0;
}
