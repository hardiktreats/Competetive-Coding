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
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL){
            return head;
        }
        if(head->next==NULL ){
                return NULL;
        }
        ListNode* temp=head;
        ListNode* slow=head;
        ListNode* fast=head;
        
            
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(fast==NULL || fast->next==NULL){
                return NULL;
            }
            if(fast==slow){       
                fast=head;
                while(fast!=slow){
                    fast=fast->next;
                    slow=slow->next;
                }
                break;
            }
            
        }
        return slow;
    }
};