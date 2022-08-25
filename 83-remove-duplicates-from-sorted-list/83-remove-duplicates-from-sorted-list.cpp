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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL){
            return 0;
        }
        ListNode* temp=head;
        do{
            if(temp->next==NULL){
                break;
            }
            if(temp->next->val==temp->val){
                temp->next=temp->next->next;
            }
            else{
                temp=temp->next;
            }
            
        }while(1);
        return head;
    }
};