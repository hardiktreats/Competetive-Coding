class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL)
            return head; 
        int count=0;
        ListNode* temp=head;
        ListNode *todelete;
        while(temp!=NULL)
        {
            count++;
            temp=temp->next;
        }
        if(count==1)
        {
            head=NULL;
            return head;
        }
        if(count-n==0)
        {
            head=head->next;
            return head;
        }
        count=count-n-1;
        temp=head;
        while(count>0)
        {
            count--;
            temp=temp->next;
            
        }
        todelete=temp->next;
        temp->next=temp->next->next;
        todelete=NULL;
        delete todelete;
        return head;       
    }
};