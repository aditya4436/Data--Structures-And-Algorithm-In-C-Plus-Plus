#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
struct Node *front=NULL;
struct Node *rear=NULL;
void Enqueue_A_Node_In_The_Queue()
{
    int data;
    cout<<"Enter the data:\n";
    cin>>data;
    struct Node *newNode=new Node;
    newNode->data=data;
    newNode->next=NULL;
    if(front==NULL && rear==NULL)
    {
        front=newNode;
        rear=newNode;
    }
    else
    {
        rear->next=newNode;
        rear=newNode;
    }
}
void Traverse_The_Queue()
{
    Node *current=front;
    if(front==NULL && rear==NULL)
    {
        cout<<"Queue is underflow!";
    }
    else
    {
        while(current!=NULL)
        {
            cout<<current->data<<"   ";
            current=current->next;
        }
    }
}
int main()
{
    int n, i;
    cout<<"Enter the number of nodes required int the queue:\n";
    cin>>n;
    for(i=0;i<n;i++)
    {
        Enqueue_A_Node_In_The_Queue();
    }
    Traverse_The_Queue();
    return 0;
}
