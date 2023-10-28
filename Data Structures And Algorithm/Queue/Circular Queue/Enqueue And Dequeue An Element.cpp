#include<iostream>
#define MAX 5
using namespace std;
int front=-1;
int rear=-1;
int queue[MAX];
void Enqueue_The_Element_In_The_Circular_Queue(int data)
{
    if(front==-1 && rear==-1)
    {
        front=rear=0;
        queue[rear]=data;
    }
    else if((rear+1)%MAX==front)
    {
        cout<<"Queue Overflow.\n";
    }
    else
    {
        rear=(rear+1)%MAX;
        queue[rear]=data;
    }
}

void Dequeue_The_Element_In_The_Circular_Queue()
{
    if(front==-1 && rear==-1)
    {
        cout<<"Queue Underflow";
    }
    else if(front==rear)
    {
        cout<<"The deleted element is:\n"<<queue[front]<<endl;
        front=rear=-1;
    }
    else
    {
        cout<<"The deleted element is:\n"<<queue[front]<<endl;
        front=(front+1)%MAX;
    }
}
void Display_The_Circular_Queue()
{
    int i=front;
    if(front==-1 && rear==-1)
    {
        cout<<"Queue Underflow!";
    }
    else
    {
        cout<<"Queue is:\n";
        while(i!=rear)
        {
            cout<<queue[i]<<"  ";
            i=(i+1)%MAX;
        }
        cout<<queue[rear];
    }
}
void Peek_Of_The_Queue()
{
    cout<<"\nThe first element of the queue:\n"<<queue[front]<<endl;
}
int main()
{
    Enqueue_The_Element_In_The_Circular_Queue(1);
    Enqueue_The_Element_In_The_Circular_Queue(2);
    Enqueue_The_Element_In_The_Circular_Queue(3);
    Enqueue_The_Element_In_The_Circular_Queue(4);
    Display_The_Circular_Queue();
    Peek_Of_The_Queue();
    Dequeue_The_Element_In_The_Circular_Queue();;
    Dequeue_The_Element_In_The_Circular_Queue();
    Display_The_Circular_Queue();
    cout<<endl;
    Enqueue_The_Element_In_The_Circular_Queue(108);
    Display_The_Circular_Queue();
    Peek_Of_The_Queue();
    return 0;
}
