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
         ListNode* partition(ListNode* head, int x) {
        queue<ListNode*>s;
        ListNode*prev=new ListNode(0),*p=head,*dummy=prev;
        while(p){
            if(p->val<x){
                prev->next=p;
                prev=p;
            }
            else{
                s.push(p);
            }
            p=p->next;
        }
        while(!s.empty()){
            cout<<s.front()->val<<s.size()<<endl;
            prev->next=s.front();
            prev=prev->next;
            s.pop();
        }
        prev->next=nullptr;
        return dummy->next;
    }
        
};