#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
struct Node *top=NULL;
void Push_A_Node_In_Stack()
{
    int data_of_the_stack;
    cout<<"Enter the new element to insert in the stack:\n";
    cin>>data_of_the_stack;
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data_of_the_stack;
    newNode->next=NULL;
    if(top==NULL)
    {
        newNode->data=data_of_the_stack;
        newNode->next=NULL;
        top=newNode;
    }
    else
    {
        newNode->data=data_of_the_stack;
        newNode->next=top;
        top=newNode;
    }
}
void Display_The_Stack()
{
    struct Node *current=top;
    if(top==NULL)
    {
        cout<<"Stack Underflow!\n";
    }
    else
    {
        while(current!=NULL)
        {
            cout<<current->data<<"  ";
            current=current->next;
        }
        cout<<"NULL";
    }
}
void Peek_Of_The_Stack()
{
    if(top==NULL)
    {
        cout<<"Stack Underflow!";
    }
    else
    {
        cout<<top->data;
    }
}
void Pop_An_Existing_Element()
{
    struct Node *temp=top;
    if(top==NULL)
    {
        cout<<"Underflow!";
    }
    else
    {
        top=top->next;
        free(temp);
        temp=NULL;
    }
}
int main()
{
    Push_A_Node_In_Stack();
    Push_A_Node_In_Stack();
    Push_A_Node_In_Stack();
    Push_A_Node_In_Stack();
    Push_A_Node_In_Stack();
    Push_A_Node_In_Stack();
    cout<<"The nodes in the stack before performing any operation:\n";
    Display_The_Stack();
    cout<<"\nThe first node of the stack before performing any operations:\n";
    Peek_Of_The_Stack();
    Pop_An_Existing_Element();
    cout<<"\nThe nodes in the stack after popping the top node:\n";
    Display_The_Stack();
    cout<<"\nThe first node after popping the top node:\n";
    Peek_Of_The_Stack();
    return 0;
}
