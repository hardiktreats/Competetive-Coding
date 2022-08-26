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
    int length(ListNode* temp){
        int n=0;
        while(temp!=NULL ){
            n++;
            temp=temp->next;
        }
        return n;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tempa;
        ListNode* tempb;
        int n=length(headA);
        int m=length(headB);
        int d=0;
        if(n>m){
            d=n-m;
            tempa=headA;
            tempb=headB;
        }
        else{
            d=m-n;
            tempa=headB;
            tempb=headA;
        }
        while(d){
            tempa=tempa->next;
            if(tempa==NULL){
                return NULL;
            }
            d--;
        }
        while(tempa!=NULL && tempb!=NULL){
            if(tempa==tempb){
                return tempa;
            }
            tempa=tempa->next;
            tempb=tempb->next;
        }
        return NULL;
    }
};