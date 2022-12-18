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
  ListNode *middleOfList(ListNode *head) {
    if (head == nullptr)
      return nullptr;

    ListNode *slow = head;
    ListNode *fast = head;
    while (fast && fast->next) {
      fast = fast->next->next;
      slow = slow->next;
    }

    return slow;
  }

  ListNode *reverseList(ListNode *head) {
    if (head == nullptr)
      return nullptr;

    ListNode *prev = nullptr;
    ListNode *curr = head;
    ListNode *next = head->next;
    while (next) {
      curr->next = prev;
      prev = curr;
      curr = next;
      next = curr->next;
    }
    curr->next = prev;

    return curr;
  }

public:
  bool isPalindrome(ListNode* head) {
    // find the middle of the list.
    ListNode *middle = middleOfList(head);
    // reverse the list after middle.
    ListNode *reverse = reverseList(middle);
    // compare the elements of these two lists.
    ListNode *check = reverse;
    ListNode *curr = head;
    while (check) {
      if (check->val != curr->val)
	return false;
      curr = curr->next;
      check = check->next;
    }

    return true;
  }
};

int main() {
  Solution sol;
  bool ret;
  ret = sol.isPalindrome(new ListNode(1, new ListNode(1, new ListNode(2, new ListNode(1)))));
  cout << ret << endl;
  return 0;
}
