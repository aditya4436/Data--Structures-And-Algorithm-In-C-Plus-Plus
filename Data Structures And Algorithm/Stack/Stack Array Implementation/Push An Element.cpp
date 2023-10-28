#include<iostream>
using namespace std;
#define MAX 5
int stack_arr[MAX], top=-1;
void Push_An_Element(int data)
{
    if(top==MAX-1)
    {
        cout<<"Stack is overflow!";
    }
    else
    {
        top++;
        stack_arr[top]=data;
    }
}
void Display_The_Stack_Element()
{
    int i;
    if(top==MAX-1)
    {
        cout<<"Stack is overflow!";
    }
    else
    {
        for(i=top;i>=0;i--)
        {
            cout<<stack_arr[i]<<"  ";
        }
    }
}
int main()
{
    Push_An_Element(1);
    Push_An_Element(2);
    Push_An_Element(3);
    Push_An_Element(4);
    //Push_An_Element(5);
    Display_The_Stack_Element();
    return 0;

}
