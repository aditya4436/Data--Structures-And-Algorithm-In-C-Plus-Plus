#include<iostream>
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
int EvaluatePostfix(string exp)
{
    for(int i=0;i<exp.size();i++)
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
                AddNodes(val2+val1);
                break;

            case '-':
                AddNodes(val2-val1);
                break;

            case '*':
                AddNodes(val2*val1);
                break;

            case '/':
                AddNodes(val2/val1);
                break;

            case '^':
                AddNodes(val2^val1);
                break;

            }
        }
    }
    return Top();
}
int main()
{
    string exp="231*+9-";
    cout<<EvaluatePostfix(exp);
    return 0;
}
