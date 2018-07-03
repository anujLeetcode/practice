/*
141. Linked List Cycle
DescriptionHintsSubmissionsDiscussSolution
Pick One
Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
      if(!head) return false;
      ListNode* slow = head;
      ListNode* fast = NULL;
      if(head->next) {
          if(head->next->next) {
            fast = head->next->next;
          } else {
              return false;
          }  
      } else {
          return false;
      }
      while(fast) {
          if(slow) slow = slow->next;
          if(fast->next) {
              fast = fast->next->next;
          } else {
              break;
          }
          if(slow == fast) return true;
      }  
      return false;
    }
};
