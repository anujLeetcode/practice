/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    
  struct compare {
    bool operator()(const ListNode* l, const ListNode* r) {
      return l->val > r->val;
    }
  };
    
public:
    priority_queue<ListNode *, vector<ListNode *>, compare> q;

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        if(lists.size() == 0) return NULL;
        
        for(auto l : lists) {
            if(l) {
              q.push(l); 
            }   
        }
        
        if(q.empty()) return NULL;
        
        ListNode* head = q.top();
        q.pop();
        
        
        ListNode* tail = head;
        if(tail->next) {
            q.push(tail->next);
        }
        
        while(!q.empty()) {      
          tail->next = q.top();
          q.pop();
          tail = tail->next;
          if(tail->next) q.push(tail->next);
        }
        
        return head;
        
        
    }
};
