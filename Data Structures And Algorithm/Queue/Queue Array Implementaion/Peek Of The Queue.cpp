#include<iostream>
#define MAX 4
using namespace std;
int rear=-1;
int front=-1;
int queue[MAX];
void Enqueue_An_Element()
{
    int data;
    cout<<"Enter the data:\n";
    cin>>data;
    if(rear==MAX-1)
    {
        cout<<"Queue Overflow";
    }
    else if(front==-1 && rear==-1)
    {
        front=rear=0;
        queue[rear]=data;
    }
    else
    {
        rear++;
        queue[rear]=data;
    }
}
void Display_An_Element()
{
    int i;
    if(front==-1 && rear==-1)
    {
        cout<<"Queue Underflow!";
    }
    else if(rear<MAX-1)
    {
        cout<<"Queue Overflow!\n";
    }
    for(i=front;i<=rear;i++)
    {
        cout<<queue[i]<<"  ";
    }
}
void Peek_Of_The_Queue()
{
    if(front==-1 && rear==-1)
    {
        cout<<"Queue is empty!";
    }
    cout<<"\nTop of the queue is:\n"<<queue[front];
}
void Count_The_Number_Of_Elements()
{
    int count=0;
    if(front!=-1 && rear!=-1)
    {
        for(int i=front;i<=rear;i++)
        {
            count++;
        }
    }
    cout<<"There are "<<count<<" elements in the queue.";
}
int main()
{
    Enqueue_An_Element();
    Enqueue_An_Element();
    Enqueue_An_Element();
    Enqueue_An_Element();
    Enqueue_An_Element();
    cout<<"\nThe elements in the queue are:\n";
    Display_An_Element();
    Peek_Of_The_Queue();
    cout<<endl;
    Count_The_Number_Of_Elements();
    return 0;
}
