#include<iostream>
using namespace std;
#define MAX 4
int stack_arr[MAX], top=-1;
int Pop_An_Existing_Element()
{
    int value;
    if(top==-1)
    {
        cout<<"Stack is underflow!";
    }
    else
    {
        value=stack_arr[top];
        top--;
    }
    return value;
}
void Push_An_Element()
{
    int data;
    cout<<"Enter the data you want push in a stack:\n";
    cin>>data;
    if(top==MAX-1)
    {
        cout<<"Stack overflow!";
    }
    else
    {
        top=top+1;
        stack_arr[top]=data;
    }
}
void Display_The_Stack_Element()
{
    int i;
    for(i=top;i>=0;i--)
    {
        cout<<stack_arr[i]<<"  ";
    }
}
int main()
{
    int n, i;
    int data;
    cout<<"Enter the number of element required in a stack:\n";
    cin>>n;
    for(i=0;i<n;i++)
    {
        Push_An_Element();
    }
    cout<<"Stack element before performing pop operation:\n";
    Display_The_Stack_Element();
    cout<<"\nStack elements after after popping up a value:\n";
    Pop_An_Existing_Element();
    Display_The_Stack_Element();
    data=Pop_An_Existing_Element();
    cout<<"\nPopped value is:\n"<<data<<"\n";
    return 0;
}
