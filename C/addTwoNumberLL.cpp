// Add two numbers represented by linked lists
// { Driver Code Starts
// driver

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


 // } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    Node* rev(Node* head)
    {
        if(head==NULL || head->next==NULL)
        return head;
        Node* prev=NULL;
        Node* curr=head;
        Node* newhead;
        while(curr!=NULL)
        {
            newhead=curr->next;
            curr->next=prev;
            prev=curr;
            curr=newhead;
        }
        return prev;
    }
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        if(first==NULL)
        return second;
        if(second==NULL)
        return first;
        Node* head=new Node(0);
        Node* temp=head;
        int c=0;
        Node* newhead1=rev(first);
        Node* newhead2=rev(second);
        while(newhead1!=NULL || newhead2!=NULL || c==1)
        {
            int sum=0;
            if(newhead1!=NULL)
            {
                sum+=newhead1->data;
                newhead1=newhead1->next;
            }
            if(newhead2!=NULL)
            {
                sum+=newhead2->data;
                newhead2=newhead2->next;
            }
            sum+=c;
            c=sum/10;
            Node* node= new Node(sum%10);
            temp->next=node;
            temp=temp->next;
        }
        return rev(head->next);
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}
  // } Driver Code Ends