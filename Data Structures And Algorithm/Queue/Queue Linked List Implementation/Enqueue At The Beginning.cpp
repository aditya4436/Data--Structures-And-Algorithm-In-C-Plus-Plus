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
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
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
void Enqueue_At_The_Beginning(int new_data)
{
    struct Node *newNode=new Node;
    newNode->data=new_data;
    newNode->next=NULL;
    newNode->next=front;
    front=newNode;
}
void Traverse_The_Queue()
{
    Node *temp=front;
    while(temp!=NULL)
    {
        cout<<temp->data<<"  ";
        temp=temp->next;
    }
}
int main()
{
    Enqueue_A_Node_In_The_Queue(1);
    Enqueue_A_Node_In_The_Queue(2);
    Enqueue_A_Node_In_The_Queue(3);
    Enqueue_A_Node_In_The_Queue(4);
    cout<<"The data in the queue are:\n";
    Traverse_The_Queue();
    Enqueue_At_The_Beginning(108);
    cout<<"\nQueue after inserting a new data at the beginning:\n";
    Traverse_The_Queue();
    return 0;
}
