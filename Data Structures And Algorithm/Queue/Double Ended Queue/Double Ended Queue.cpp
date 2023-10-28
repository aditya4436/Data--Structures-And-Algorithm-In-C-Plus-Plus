#include<iostream>
#define size 5
using namespace std;
int deque[size];
int front=-1, rear=-1;
bool Is_Full()
{
    if(front==0 && rear==size-1||front==rear+1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Is_Empty()
{
    if(front==-1 && rear==-1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void Insert_At_The_Front(int data)
{
    if(Is_Full())
    {
        cout<<"Overflow";
    }
    else if(Is_Empty())
    {
        front=rear=0;
        deque[front]=data;
    }
    else if(front==0)
    {
        front=size-1;
        deque[front]=data;
    }
    else
    {
        front=front-1;
        deque[front]=data;
    }
}
void Insert_At_The_Rear(int data)
{
    if(Is_Full())
    {
        cout<<"Overflow";
    }
    else if(Is_Empty())
    {
        front=rear=0;
        deque[rear]=data;
    }
    else if(rear==size-1)
    {
        rear=0;
        deque[rear]=data;
    }
    else
    {
        rear++;
        deque[rear]=data;
    }
}
void Display_The_Double_Ended_Queue()
{
    int i=front;
    cout<<"Elements in deque are:\n";
    while(i!=rear)
    {
        cout<<deque[i]<<"  ";
        i=(i+1)%size;
    }
    cout<<deque[i]<<"  ";
}
void Get_Front()
{
    if((front==-1) && (rear==-1))
    {
        cout<<"Deque is Empty!";
    }
    else
    {
        cout<<"\nThe element at the front is:\n"<<deque[front]<<"  ";
    }
}
void Get_Rear()
{
    if((front==-1) && (rear==-1))
    {
        cout<<"Deque is Empty!";
    }
     else
    {
        cout<<"\nThe  element the at rare is:\n"<<deque[rear]<<"  ";
    }
}
void Delete_Front()
{
    if((front==-1) && (rear==-1))
    {
        cout<<"Deque is Empty!";
    }
    else if(front==rear)
    {
        cout<<"\nThe element deleted from the front is :\n"<<deque[front];
        front=-1;
        rear=-1;
    }
    else if(front==(size-1))
    {
        cout<<"\nThe element deleted from the front is:\n"<<deque[front];
        front=0;
    }
    else
    {
        cout<<"\nThe element deleted from the front is:\n"<<deque[front];
        front++;
    }
}
void Delete_Rear()
{
    if(front==-1 && rear==-1)
    {
        cout<<"Deque is empty!";
    }
    else if(front==rear)
    {
        cout<<"\nThe element deleted from the rear is:\n"<<deque[rear];
        front=-1;
        rear=-1;
    }
    else if(rear==0)
    {
        cout<<"\nThe element deleted from the rear is:\n"<<deque[rear]<<endl;
        rear=size-1;
    }
    cout<<"\nThe element deleted from the rear is:\n"<<deque[rear]<<endl;
    rear--;
}
int main()
{
    Insert_At_The_Front(20);
    Insert_At_The_Front(10);
    Insert_At_The_Rear(30);
    Insert_At_The_Rear(50);
    Insert_At_The_Rear(80);
    Display_The_Double_Ended_Queue();
    Get_Front();
    Get_Rear();
    Delete_Front();
    Delete_Rear();
    Display_The_Double_Ended_Queue();
    return 0;
}
