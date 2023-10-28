#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;
struct Node
{
    string data;
    Node *next;
};
struct Node *top=NULL;
string Push(string data)
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
    return "0";
}
void Pop()
{
    Node *temp=top;
    if(top==NULL)
    {
        cout<<"Underflow";
    }
    else
    {
        top=top->next;
        free(temp);
        temp=NULL;
    }
}
string Peek()
{
    return top->data;
}
string PostfixToPrefix(string s)
{
    string expression;
    int i, n;
    n=s.size();
    for(i=0;i<n;i++)
    {
        if(s[i]>='a'&&s[i]<='z'||s[i]>='A'&&s[i]<='Z')
        {
            string op(1, s[i]);
            Push(op);
        }
        else
        {
            string op1=Peek();
            Pop();
            string op2=Peek();
            Pop();
            expression=s[i]+op2+op1;
            Push(expression);
        }
    }
    return Peek();
}
int main()
{
    cout<<PostfixToPrefix("ABC/-AK/L-*");
    return 0;
}

