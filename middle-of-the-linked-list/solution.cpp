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
    ListNode* middleNode(ListNode* head) {
      if (head == nullptr)
	return nullptr;
      if (head->next == nullptr)
	return head;

      ListNode *fast = head;
      ListNode *slow = head;

      while (fast && fast->next) {
	fast = fast->next->next;
	slow = slow->next;
      }

      return slow;
    }
};

int main() {
  return 0;
}
