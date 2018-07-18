/*
206. Reverse Linked List
DescriptionHintsSubmissionsDiscussSolution
Pick One
Reverse a singly linked list.

Example:

Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL
Follow up:

A linked list can be reversed either iteratively or recursively. Could you implement both?
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
    ListNode* reverseList(ListNode* head) {
       if(!head || head->next == NULL) return head;
       ListNode* prev = NULL;
       ListNode* curr = head;
       ListNode* foll = NULL;
        
       while(curr) {
          foll = curr->next;
          curr->next = prev;
          prev = curr;
          curr = foll;
       }
       return prev; 
    }
};
