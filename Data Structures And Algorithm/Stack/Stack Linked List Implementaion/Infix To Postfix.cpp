#include<iostream>
#include<stack>
using namespace std;
struct Node
{
    char data;
    Node *next;
};
struct Node* top=NULL;
int Precedence(char c)
{
    if(c=='^')
        return 3;
    else if(c=='*'||c=='/')
        return 2;
    else if(c=='+'||c=='-')
        return 1;
    else
        return -1;
}
char IsEmpty()
{
    return top==NULL;
}
void Push(char data)
{
    struct Node *newNode=new Node;
    newNode->data=data;
    newNode->next=NULL;
    if(IsEmpty())
    {
        top=newNode;
    }
    else
    {
        newNode->next=top;;
        top=newNode;
    }
    //return top->data;
}
void Pop()
{
    Node *temp=top;
    if(IsEmpty())
    {
        cout<<"Empty";
    }
    top=top->next;
    free(temp);
    temp=NULL;
}
char Peek()
{
    return top->data;
}
void Traverse()
{
    Node *temp=top;
    if(IsEmpty())
    {
        cout<<"Empty";
    }
    else
    {
        do
        {
            cout<<temp->data<<"  ";
            temp=temp->next;
        }
        while(temp!=NULL);
        {
            cout<<"NULL";
        }
    }
}
string InfixToPostfix(string s)
{
    int i, n;
    stack<char> st;
    n=s.size();
    string result;
    for(i=0;i<n;i++)
    {
        if(s[i]>='a'&&s[i]<='z'||s[i]>='A'&&s[i]<='Z')
        {
            result+=s[i];
        }
        else if(s[i]=='(')
        {
            Push(s[i]);
        }
        else if(s[i]==')')
        {
            while(!IsEmpty()&&Peek()!='(')
            {
                result+=Peek();
                Pop();
            }
            if(!IsEmpty())
            {
                Pop();
            }
        }
        else
        {
            while(!IsEmpty()&&Precedence(Peek())>=Precedence(s[i]))
            {
                result+=Peek();
                Pop();
            }
            Push(s[i]);
        }
    }
    while(!IsEmpty())
    {
        result+=Peek();
        Pop();
    }
    return result;
}
int main()
{
    cout<<InfixToPostfix("(a-b/c)*(a/k-l)");
    cout<<endl;
    return 0;
}
