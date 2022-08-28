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
    ListNode* middleNode(ListNode* head) {
        if(head==NULL){
            return head;
        }
        ListNode* temp=head;
        int c=0;
        while(temp!=NULL){
            c++;
            temp=temp->next;
        }
        temp=head;
        int b=ceil(c/2);
        while(b){
            temp=temp->next;
            b--;
        }
        return temp;
    }
};