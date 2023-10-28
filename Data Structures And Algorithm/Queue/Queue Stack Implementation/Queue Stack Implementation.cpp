#include<iostream>
using namespace std;
#define N 5
int s1[N], s2[N];
int top1=-1, top2=-1;
int count=0;
void Push1_An_Element(int data)
{
    if(top1==N-1)
    {
        cout<<"Overflow!";
    }
    else
    {
        top1++;
        s1[top1]=data;
    }
}
void Push2_An_Element(int data)
{
    if(top2==N-1)
    {
        cout<<"Overflow!";
    }
    else
    {
        top2++;
        s2[top2]=data;
    }
}

int Pop1_An_Existing_Element()
{
    return s1[top1--];
}
int Pop2_An_Existing_Element()
{
    return s2[top2--];
}
void Dequeue_An_Existing_Element()
{
    int i, a, b;
    if(top1==-1 && top2==-1)
    {
        cout<<"Underflow!";
    }
    else
    {
        for(i=0;i<count;i++)
        {
            a=Pop1_An_Existing_Element();
            Push2_An_Element(a);
        }
        b=Pop2_An_Existing_Element();
        cout<<"Popped element is:\n"<<b<<endl;
        count--;
        for(i=0;i<count;i++)
        {
            a=Pop2_An_Existing_Element();
            Push1_An_Element(a);
        }
    }
}
void Display_Queue_Element()
{
    for(int i=0;i<=top1;i++)
    {
        cout<<s1[i]<<"  ";
    }
}
void Enqueue_An_Element(int x)
{
    Push1_An_Element(x);
    count++;
}
int main()
{
    Enqueue_An_Element(5);
    Enqueue_An_Element(4);
    Enqueue_An_Element(2);
    Dequeue_An_Existing_Element();
    Enqueue_An_Element(108);
    cout<<"Queue after popping and inserting the new element:\n";
    Display_Queue_Element();
    return 0;
}
