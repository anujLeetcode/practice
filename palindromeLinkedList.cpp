/*
234. Palindrome Linked List
DescriptionHintsSubmissionsDiscussSolution
Pick One
Given a singly linked list, determine if it is a palindrome.

Example 1:

Input: 1->2
Output: false
Example 2:

Input: 1->2->2->1
Output: true
Follow up:
Could you do it in O(n) time and O(1) space?

*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//1 2 3 4 5 6 7
    
    
class Solution {
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
public:
    bool isPalindrome(ListNode* head) {
       if(!head) return true;
       ListNode* slow = head;
       ListNode* fast = head;
       while(fast->next && fast->next->next) {
           slow = slow->next;
           fast = fast->next->next;
       }
       if(slow == head) {
           if(head->next == NULL) return true;
           else {
               return (head->next->val == head->val);
           }
            
        }        
       ListNode* half = slow->next;
       slow->next = NULL;
       half = reverseList(half); 
       while(head && half) {
           if(head->val != half->val) return false;
           head = head->next;
           half = half->next;
       }
       return true;
    }
};
