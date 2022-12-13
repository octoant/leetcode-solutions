// https://leetcode.com/problems/add-two-numbers/
#include <stack>

using namespace std;

/* Definition for singly-linked list. */
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    std::stack<int> stack;
    int temp, flag = 0;
    for (; l1 && l2; l1 = l1->next, l2 = l2->next) {
      temp = flag + l1->val + l2->val;
      flag = temp / 10;
      stack.push(temp % 10);
    }
    for (; l1; l1 = l1->next) {
      temp = flag + l1->val;
      flag = temp / 10;
      stack.push(temp % 10);
    }
    for (; l2; l2 = l2->next) {
      temp = flag + l2->val;
      flag = temp / 10;
      stack.push(temp % 10);
    }
    if (flag) {
      stack.push(flag);
    }
    ListNode *list = nullptr;
    while (!stack.empty()) {
      if (!list) {
        list = new ListNode(stack.top());
      } else {
        list = new ListNode(stack.top(), list);
      }
      stack.pop();
    }
    return list;
  }
};
