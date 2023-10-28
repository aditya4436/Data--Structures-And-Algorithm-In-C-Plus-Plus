#include<iostream>
#define MAX 4
using namespace std;
int queue[MAX];
int front=-1;
int rear=-1;
void Enqueue_An_Element(int data)
{
    if(rear==MAX-1)
    {
        cout<<"Overflow";
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
void Display_The_Queue()
{
    if(front==-1 &&rear==-1)
    {
        cout<<"Queue is empty!";
    }
    cout<<"The elements in the queue are:\n";
    for(int i=front; i<rear+1; i++)
    {
        cout<<queue[i]<<"  ";
    }
}
int main()
{
    Enqueue_An_Element(1);
    Enqueue_An_Element(2);
    Enqueue_An_Element(3);
    Enqueue_An_Element(4);
    Display_The_Queue();
    return 0;
}
