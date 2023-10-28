#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node *next, *prev;
};
struct Node *front=NULL;
struct Node *rear=NULL;
void AddNodes(int data)
{
    struct Node *newNode=new Node;
    newNode->data=data;
    newNode->next=NULL;
    newNode->prev=NULL;
    if(front==NULL)
    {
        front=rear=newNode;
        front->prev=NULL;
        rear->next=NULL;
    }
    else
    {
        rear->next=newNode;
        newNode->prev=rear;
        rear=newNode;
        newNode->next=NULL;
    }
}
void InsertFront1(int data)
{
    struct Node *newNode=new Node;
    newNode->data=data;
    newNode->next=NULL;
    newNode->prev=NULL;
    front->prev=newNode;
    newNode->next=front;
    front=newNode;
}
void InsertFront2(int data)
{
    struct Node *newNode=new Node;
    newNode->data=data;
    newNode->next=NULL;
    newNode->prev=NULL;
    rear->next=newNode;
    newNode->prev=rear;
    rear=newNode;
}
void DeleteFirst()
{
    if(front==NULL)
    {
        cout<<"Empty";
    }
    else
    {
        Node *temp=front;
        front=front->next;
        free(temp);
        temp=NULL;
    }
}
void DeleteLast()
{
    if(front==NULL&&rear==NULL)
    {
        cout<<"Empty";
    }
    else
    {
        Node *temp=rear;
        rear=rear->prev;
        /*temp->prev->next=NULL;
        free(temp);
        temp=NULL;*/
        rear->next=NULL;
    }
}
void Traverse()
{
    Node *temp=front;
    if(front==NULL)
    {
        cout<<"Empty";
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
int main()
{
    AddNodes(1);
    AddNodes(2);
    AddNodes(3);
    AddNodes(4);
    Traverse();
    cout<<endl;
    InsertFront1(6);
    InsertFront2(7);
    Traverse();
    cout<<endl;
    DeleteFirst();
    Traverse();
    cout<<endl;
    DeleteLast();
    Traverse();
    return 0;
}
