// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



 // } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    public:
    Node *compute(Node *head){
    if(head->next==NULL) return head;
       Node *p, *q=NULL, *r=head;
       while(r){
           p=q;
           q=r;
           r=r->next;
           q->next=p;
       }
       Node *last, *s;
       int maxx=INT_MIN;
       bool y=true;
       while(q){
           if(q->data>=maxx){
               if(y==true){
                   s=q;
                   last=q;
                   y=false;
               }
               else{
                   last->next=q;
                   last=q;
               }
               maxx=q->data;
           }
           q=q->next;
       }
       last->next=NULL;
       Node *a, *b=NULL, *c=s;
       while(c){
           a=b;
           b=c;
           c=c->next;
           b->next=a;
       }
       return b;
   }
};
   


// { Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}
  // } Driver Code Ends