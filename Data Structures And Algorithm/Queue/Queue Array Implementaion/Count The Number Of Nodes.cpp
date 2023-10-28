#include<iostream>
#define MAX 100
using namespace std;
int front=-1;
int rear=-1;
int queue[MAX];
void Enqueue_An_Element()
{
    int data;
    cout<<"Enter the data:\n";
    cin>>data;
    if(front=-1 && rear==-1)
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
void Count_The_Number_Of_Elements()
{
    int count=0, i;
    if(front!=-1 && rear!=-1)
    {
        for(i=front;i<=rear;i++)
        {
            count++;
        }
    }
    cout<<"There are "<<count<<" number of elements in the queue.";
}
void Display_The_Queue()
{
    if(front==-1 && rear==-1)
    {
        cout<<"Queue is empty!";
    }
    cout<<"The elements in the queue are:\n";
    for(int i=front;i<=rear;i++)
    {
        cout<<queue[i]<<"  ";
    }
}
int main()
{
    int number_of_data_required_in_queue, i;
    cout<<"Enter the number of elements required in the queue:\n";
    cin>>number_of_data_required_in_queue;
    for(i=0;i<number_of_data_required_in_queue;i++)
    {
        Enqueue_An_Element();
    }
    Display_The_Queue();
    cout<<endl;
    Count_The_Number_Of_Elements();
    return 0;
}
