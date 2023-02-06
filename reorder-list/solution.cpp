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
private:
  ListNode *reverseList(ListNode *head) {
    ListNode *prev = nullptr;
    ListNode *curr = head;
    ListNode *next = head->next;

    while (next != nullptr) {
      curr->next = prev;
      prev = curr;
      curr = next;
      next = next->next;
    }
    curr->next = prev;

    return curr;
  }

public:
  void reorderList(ListNode* head) {
    if (head->next == nullptr)
      return;

    ListNode *slow = head;
    ListNode *fast = head;
    ListNode *slow_prev = nullptr;

    while (fast != nullptr && fast->next != nullptr) {
      slow_prev = slow;
      slow = slow->next;
      fast = fast->next->next;
    }

    if (slow_prev != nullptr)
      slow_prev->next = nullptr;
    ListNode *reversed = reverseList(slow);

    ListNode *list1_cur = head;
    ListNode *list2_cur = reversed;
    ListNode *new_head = list1_cur;
    ListNode *curr = new_head;
    list1_cur = list1_cur->next;
    while (list1_cur != nullptr && list2_cur != nullptr) {
      curr->next = list2_cur;
      list2_cur = list2_cur->next;
      curr->next->next = list1_cur;
      list1_cur = list1_cur->next;
      curr = curr->next->next;
    }

    if (list1_cur != nullptr)
      curr->next = list1_cur;
    if (list2_cur != nullptr)
      curr->next = list2_cur;
  }
};

void printList(ListNode *head) {
  ListNode *curr = head;
  while (curr != nullptr) {
    cout << curr->val << " ";
    curr = curr->next;
  }
  cout << endl;
}

int main() {
  Solution sol;
  ListNode *head1 = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4))));
  sol.reorderList(head1);
  printList(head1);
  ListNode *head2 = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
  sol.reorderList(head2);
  printList(head2);
  ListNode *head3 = new ListNode(1);
  sol.reorderList(head3);
  printList(head3);
  return 0;
}
