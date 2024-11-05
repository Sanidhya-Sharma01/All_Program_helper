// Reverse a Linked List in groups of given size
#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node* next;

    node(int x){
        data = x;
        next = NULL;
    }
};
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

    struct node
    {
        int data;
        struct node* next;

        node(int x){
            data = x;
            next = NULL;
        }

    }*head;

class Solution
{
    public:
    struct node *reverse (struct node *head, int k)
    { 
        if(head==NULL || head->next==NULL)
        return head;
        node* curr=head;
        node* prev=NULL;
        node* newhead;
        int l=0;
        while(l<k && curr!=NULL)
        {
            newhead=curr->next;
            curr->next=prev;
            prev=curr;
            curr=newhead;
            l++;
        }
        if(curr!=NULL)
        {
            head->next=reverse(curr,k);
        }
        return prev;
    }
};
int main(void)
{
    int t;
    cin>>t;

    while(t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin >> n;

        for(int i=0 ; i<n ; i++)
        {
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }

        int k;
        cin>>k;

        Solution ob;
        head = ob.reverse(head, k);
        printList(head);
    }

    return(0);
}