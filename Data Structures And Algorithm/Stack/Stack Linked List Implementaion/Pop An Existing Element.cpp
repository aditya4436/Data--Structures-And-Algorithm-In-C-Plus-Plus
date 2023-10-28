#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
struct Node *top=NULL;
void Push_Nodes_In_The_Stack()
{
    int data_of_the_stack;
    cout<<"Enter the data of the stack:\n";
    cin>>data_of_the_stack;
    struct Node *newNode= new Node;
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
void Pop_An_Existing_Element()
{
    struct Node *current=top;
    if(top==NULL)
    {
        cout<<"Stack is empty!";
    }
    else
    {
        top=top->next;
        free(current);
        current=NULL;
    }
}
void Traverse_The_Stack()
{
    Node *current=top;
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
        cout<<endl;
    }
}
int main()
{
    int number_of_nodes_required_in_a_stack, i;
    cout<<"Enter the number of nodes required in a stack:\n";
    cin>>number_of_nodes_required_in_a_stack;
    for(i=0;i<number_of_nodes_required_in_a_stack;i++)
    {
        Push_Nodes_In_The_Stack();
    }
    cout<<"Stack before popping:\n";
    Traverse_The_Stack();
    Pop_An_Existing_Element();
    cout<<"Stack after popping:\n";
    Traverse_The_Stack();
    return 0;
}

