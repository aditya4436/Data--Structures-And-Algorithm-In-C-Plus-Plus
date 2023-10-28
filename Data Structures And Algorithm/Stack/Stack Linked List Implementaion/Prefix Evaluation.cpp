#include<iostream>
#include<math.h>
using namespace std;
struct Stack
{
    int data;
    Stack *next;
};
struct Stack* top=NULL;
void AddNodes(int data)
{
    struct Stack* newNode=new Stack;
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
    struct Stack *temp=top;
    if(top==NULL)
    {
        cout<<"Empty";
    }
    else
    {
        top=top->next;
        free(temp);
        temp=NULL;
    }
}
int Top()
{
    return top->data;
}
int isEmpty()
{
    return -1;
}
int EvaluatePrefix(string exp)
{
    for(int i=exp.size()-1;i>=0;i--)
    {
        if(isdigit(exp[i]))
        {
            AddNodes(exp[i]-'0');
        }
        else
        {
            int val1=Top();
            Pop();
            int val2=Top();
            Pop();

            switch(exp[i])
            {
            case '+':
                AddNodes(val1+val2);
                break;

            case '-':
                AddNodes(val1-val2);
                break;

            case '*':
                AddNodes(val1*val2);
                break;

            case '/':
                AddNodes(val1/val2);
                break;

            case '^':
                AddNodes(pow(val1, val2));
                break;

            }
        }
    }
    return Top();
}
int main()
{
    string exp="+-*235/^234";
    cout<<EvaluatePrefix(exp);
    return 0;
}
