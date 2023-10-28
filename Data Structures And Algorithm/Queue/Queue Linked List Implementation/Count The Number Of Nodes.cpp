#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
struct Node *front=NULL;
struct Node *rear=NULL;
void Enqueue_A_Node_In_The_Queue(int data)
{
    struct Node *newNode=new Node;
    newNode->data=data;
    newNode->next=NULL;
    if(front==NULL)
    {
        front=rear=newNode;
    }
    else
    {
        rear->next=newNode;
        rear=newNode;
    }
}
void Count_The_Nodes_In_The_Queue()
{
    struct Node *temp=front;
    int count=0;
    while(temp!=NULL)
    {
        temp=temp->next;
        count++;
    }
    cout<<"\nThere are "<<count<<" nodes in the queue.";
}
void Traverse_The_Queue()
{
    struct Node *current=front;
    if(front==NULL)
    {
        cout<<"Queue underflow";
    }
    else
    {
        cout<<"The nodes in the queue are:\n";
        while(current!=NULL)
        {
            cout<<current->data<<"  ";
            current=current->next;
        }
    }
}
int main()
{
    Enqueue_A_Node_In_The_Queue(1);
    Enqueue_A_Node_In_The_Queue(2);
    Enqueue_A_Node_In_The_Queue(3);
    Enqueue_A_Node_In_The_Queue(4);
    Enqueue_A_Node_In_The_Queue(108);
    Traverse_The_Queue();
    Count_The_Nodes_In_The_Queue();
    return 0;
}
