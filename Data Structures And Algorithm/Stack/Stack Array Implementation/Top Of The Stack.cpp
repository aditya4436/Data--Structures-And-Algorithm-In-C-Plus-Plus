#include<iostream>
using namespace std;
#define MAX 4
int stack_arr[MAX], top=-1;
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
void Peek_Element()
{
    if(top==-1)
    {
        cout<<"Stack is underFlow!";
    }
    else
    {
        cout<<"The topmost value in a stack is:\n"<<stack_arr[top]<<endl;
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
    cout<<"Stack elements are:\n";
    Display_The_Stack_Element();
    cout<<endl;
    Peek_Element();
    return 0;
}

