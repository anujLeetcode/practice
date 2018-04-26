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
    ListNode* rotateRight(ListNode* head, int k) {
        struct ListNode* temp1 = head;
        struct ListNode* temp2 = head;
        int size = 0;
        
        if(k == 0 || !head) return head;
        
        while(temp2) {
            size++;
            temp2=temp2->next;
        }
        
        k = k%size;
        
        for(int i = 0; i < k && temp1 != NULL; i++) {
            temp1 = temp1->next;
        }
        
        if(!temp1) return head;

        temp2 = head;
        while(temp1->next) {
          temp1 = temp1->next;
          temp2 = temp2->next;
        }
        
        
        temp1->next = head;
        head = temp2->next;
        temp2->next = NULL;
        return head; 
    }
};
