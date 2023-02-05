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
  ListNode* sortList(ListNode* head) {
    if (head == nullptr)
      return nullptr;
    if (head->next == nullptr)
      return head;

    ListNode *slow_parent = nullptr;
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != nullptr && fast->next != nullptr) {
      slow_parent = slow;
      slow = slow->next;
      fast = fast->next->next;
    }
    ListNode *second_head = slow;
    slow_parent->next = nullptr;
    ListNode *first = sortList(head);
    ListNode *second = sortList(second_head);

    ListNode *merged = nullptr;
    ListNode *merged_head = nullptr;
    while (first != nullptr && second != nullptr) {
      if (first->val < second->val) {
	if (merged_head == nullptr) {
	  merged = first;
	  merged_head = merged;
	} else {
	  merged->next = first;
	  merged = merged->next;
	}
	first = first->next;
      } else {
	if (merged_head == nullptr) {
	  merged = second;
	  merged_head = merged;
	} else {
	  merged->next = second;
	  merged = merged->next;
	}
	second = second->next;
      }
    }

    if (first != nullptr) {
      if (merged_head == nullptr)
	merged_head = first;
      else
	merged->next = first;
    }

    if (second != nullptr) {
      if (merged_head == nullptr)
	merged_head = second;
      else
	merged->next = second;
    }

    return merged_head;
  }
};

int main() {
  Solution sol;
  ListNode *ret;
  ret = sol.sortList(new ListNode(4, new ListNode(2, new ListNode(1, new ListNode(3)))));
  return 0;
}
