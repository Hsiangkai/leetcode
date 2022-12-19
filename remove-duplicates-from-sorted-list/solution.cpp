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
    ListNode* deleteDuplicates(ListNode* head) {
      if (head == nullptr)
	return nullptr;

      ListNode *prev = head;
      ListNode *curr = head->next;
      int prev_val = prev->val;
      while (curr) {
	if (curr->val == prev_val) {
	  // remove current node
	  prev->next = curr->next;
	  curr = curr->next;
	} else {
	  prev = curr;
	  curr = curr->next;
	  prev_val = prev->val;
	}
      }

      return head;
    }
};

int main() {
  return 0;
}
