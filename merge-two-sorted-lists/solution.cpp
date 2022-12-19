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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
      if (list1 == nullptr)
	return list2;
      if (list2 == nullptr)
	return list1;

      ListNode *fp = list1;
      ListNode *sp = list2;
      ListNode *head;
      if (fp->val <= sp->val) {
	head = fp;
	fp = fp->next;
      } else {
	head = sp;
	sp = sp->next;
      }

      ListNode *curr = head;
      while (fp && sp) {
	if (fp->val <= sp->val) {
	  curr->next = fp;
	  fp = fp->next;
	} else {
	  curr->next = sp;
	  sp = sp->next;
	}
	curr = curr->next;
      }

      if (fp) {
	curr->next = fp;
      } else if (sp) {
	curr->next = sp;
      }

      return head;
    }
};
