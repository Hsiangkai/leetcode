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
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *l1_ptr = l1;
    ListNode *l2_ptr = l2;
    ListNode *head = nullptr;
    ListNode *curr_ptr;

    bool carry = false;
    while (l1_ptr != nullptr && l2_ptr != nullptr) {
      int sum = l1_ptr->val + l2_ptr->val;
      if (carry)
	sum += 1;

      if (sum >= 10) {
	carry = true;
	sum -= 10;
      } else {
	carry = false;
      }
      ListNode *new_one = new ListNode(sum);
      if (head == nullptr) {
	head = new_one;
	curr_ptr = new_one;
      } else {
	curr_ptr->next = new_one;
	curr_ptr = new_one;
      }

      l1_ptr = l1_ptr->next;
      l2_ptr = l2_ptr->next;
    }

    if (l2_ptr == nullptr) {
      while (l1_ptr != nullptr) {
	int sum = l1_ptr->val + (carry ? 1 : 0);
	if (sum >= 10) {
	  carry = true;
	  sum -= 10;
	} else {
	  carry = false;
	}
	ListNode *new_one = new ListNode(sum);
        if (head == nullptr) {
          head = new_one;
          curr_ptr = new_one;
        } else {
          curr_ptr->next = new_one;
          curr_ptr = new_one;
        }

	l1_ptr = l1_ptr->next;
      }
    }

    if (l1_ptr == nullptr) {
      while (l2_ptr != nullptr) {
	int sum = l2_ptr->val + (carry ? 1 : 0);
	if (sum >= 10) {
	  carry = true;
	  sum -= 10;
	} else {
	  carry = false;
	}
	ListNode *new_one = new ListNode(sum);
        if (head == nullptr) {
          head = new_one;
          curr_ptr = new_one;
        } else {
          curr_ptr->next = new_one;
          curr_ptr = new_one;
        }

	l2_ptr = l2_ptr->next;
      }
    }

    if (carry) {
      ListNode *new_one = new ListNode(1);
      curr_ptr->next = new_one;
    }

    return head;
  }
};

int main() {
  ListNode *ret;
  Solution sol;
  ListNode *num_1_1 = new ListNode(2, new ListNode(4, new ListNode(3)));
  ListNode *num_1_2 = new ListNode(5, new ListNode(6, new ListNode(4)));
  ret = sol.addTwoNumbers(num_1_1, num_1_2);
  ListNode *num_2_1 = new ListNode(0, nullptr);
  ListNode *num_2_2 = new ListNode(0, nullptr);
  ret = sol.addTwoNumbers(num_2_1, num_2_2);
  ListNode *num_3_1 = new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9)))))));
  ListNode *num_3_2 = new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9))));
  ret = sol.addTwoNumbers(num_3_1, num_3_2);
  return 0;
}
