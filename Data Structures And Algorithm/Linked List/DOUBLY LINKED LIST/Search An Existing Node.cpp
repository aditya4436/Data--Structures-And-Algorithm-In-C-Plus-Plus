#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node *next, *prev;
};
struct Node *head=NULL;
struct Node *tail=NULL;
void Add_Nodes_To_The_List(int data)
{
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->prev=NULL;
    newNode->next=NULL;
    if(head==NULL)
    {
        head=tail=newNode;
        head->prev=NULL;
        tail->next=NULL;
    }
    else
    {
        tail->next=newNode;
        newNode->prev=tail;
        tail=newNode;
        tail->next=NULL;
    }
}
void Traverse_The_List()
{
    struct Node* temp=head;
    if(head==NULL)
    {
        cout<<"Underflow";
    }
    else
    {
        do
        {
            cout<<temp->data<<"  ";
            temp=temp->next;
        }
        while(temp!=NULL);
        {
            cout<<"NULL";
        }
    }
}
int Search_An_Existing_Node(int x)
{
    struct Node *temp=head;
    if(head==NULL)
    {
        cout<<"Empty";
    }
    else
    {
        int i=0, flag;
        while(temp!=NULL)
        {
            if(temp->data==x)
            {
                cout<<"The data is at position "<<i+1<<"\n";
                return 0;
            }
            else
            {
                flag=1;
            }
            i++;
            temp=temp->next;
        }
        if(flag==1)
        {
            cout<<"Data does not exists.\n";
            return 0;
        }
    }
    return 0;
}
int main()
{
    Add_Nodes_To_The_List(15);
    Add_Nodes_To_The_List(43);
    Add_Nodes_To_The_List(21);
    Add_Nodes_To_The_List(14);
    cout<<"The list is as follows:\n";
    Traverse_The_List();
    cout<<endl;
    Search_An_Existing_Node(15);
    return 0;
}

