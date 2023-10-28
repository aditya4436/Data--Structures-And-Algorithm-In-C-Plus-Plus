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
void Dequeue_An_Exisiting_Node()
{
    Node *temp=front;
    if(front==NULL && rear==NULL)
    {
        cout<<"Queue is empty!";
    }
    else
    {
        front=front->next;
        free(temp);
        temp=NULL;
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
void Count_The_Nodes_In_The_Queue()
{
    int count=0;
    Node *temp=front;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    cout<<"There are "<<count<<" nodes in the queue.";
}
void Peek_Of_The_Queue()
{
    cout<<"\nThe first node of the list is "<<front->data;
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
    cout<<"Queue Before Dequeuing:\n";
    Traverse_The_Queue();
    Peek_Of_The_Queue();
    Dequeue_An_Exisiting_Node();
    cout<<"\nQueue After Dequeuing:\n";
    Traverse_The_Queue();
    Peek_Of_The_Queue();
    cout<<endl;
    Count_The_Nodes_In_The_Queue();
    return 0;
}

