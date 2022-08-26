/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int vale) {
        
        ListNode* temp=head;
        ListNode* a=temp;
        if(head==NULL){
            return head;
        }
        while(temp!=NULL && temp->next!=NULL){
            if(temp->next->val==vale){
                temp->next=temp->next->next;
                continue;
            }
            temp=temp->next;
        }
        if(a->val==vale){
            a=a->next;
        }
        return a;
    }
};
