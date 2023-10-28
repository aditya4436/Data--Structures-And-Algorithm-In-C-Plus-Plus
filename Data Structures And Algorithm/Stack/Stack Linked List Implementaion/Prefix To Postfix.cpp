#include<iostream>
using namespace std;
struct Node
{
    string data;
    Node *next;
};
struct Node *top=NULL;
void Push(string data)
{
    struct Node *newNode=new Node;
    newNode->data=data;
    newNode->next=NULL;
    if(top==NULL)
    {
        top=newNode;
    }
    else
    {
        newNode->next=top;
        top=newNode;
    }
}
void Pop()
{
    struct Node *temp=top;
    if(top==NULL)
    {
        cout<<"Underflow";
    }
    top=top->next;
    free(temp);
    temp=NULL;
}
string Peek()
{
    return top->data;
}
string PrefixToPostfix(string s)
{
    int n, i;
    string expression;
    n=s.size();
    for(i=n-1;i>=0;i--)
    {
        if((s[i]=='^'||s[i]=='*'||s[i]=='/'||s[i]=='+'||s[i]=='-'))
        {
            string op1=Peek();
            Pop();
            string op2=Peek();
            Pop();
            expression=op1+op2+s[i];
            Push(expression);
        }
        else
        {
            Push(string (1, s[i]));
        }
    }
    return Peek();
}
int main()
{
    cout<<PrefixToPostfix("*+ab-cd");
    return 0;
}
