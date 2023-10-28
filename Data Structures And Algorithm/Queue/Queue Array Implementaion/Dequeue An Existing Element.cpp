#include<iostream>
#define MAX 100
using namespace std;
int rear=-1;
int front=-1;
int queue[MAX];
void Dequeue_An_Element()
{
    if(front==-1 && rear==-1)
    {
        cout<<"Queue is empty!";
    }
    else if(front==rear)
    {
        front=rear=-1;
    }
    else
    {
        front++;
    }
}
void Display_An_Element()
{
    int i;
    if(front==-1 && rear==-1)
    {
        cout<<"Queue is empty!";
    }
    else
    {
        for(i=front;i<=rear;i++)
        {
            cout<<queue[i]<<"  ";
        }
    }
}
void Enqueue_An_Element(int data)
{
    cout<<"Enter the data you want to store in the queue:\n";
    cin>>data;
    if(rear==MAX-1)
    {
        cout<<"Queue Overflow!";
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
int main()
{
    int number_of_elements_required_in_queue, i;
    cout<<"Enter the number of elements required in the queue:\n";
    cin>>number_of_elements_required_in_queue;
    for(i=0;i<number_of_elements_required_in_queue;i++)
    {
         Enqueue_An_Element(number_of_elements_required_in_queue);
    }
    cout<<"\nElements before dequeuing am element:\n";
    Display_An_Element();
    Dequeue_An_Element();
    cout<<"\nElements in the queue are:\n";
    Display_An_Element();
}
