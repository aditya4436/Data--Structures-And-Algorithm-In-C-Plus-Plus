#include<iostream>
#include<algorithm>
using namespace std;
struct Node
{
    char data;
    Node *next;
};
struct Node *top=NULL;
char IsEmpty()
{
    return top==NULL;
}
void Push(char data)
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
char Peek()
{
    return top->data;
}
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
string InfixToPrefix(string s)
{
    int i, n;
    string result="";
    n=s.size();
    reverse(s.end(), s.begin());
    for(i=0;i<n;i++)
    {
        if(s[i]=='(')
        {
            s[i]=')';
        }
        else if(s[i]==')')
        {
            s[i]='(';
        }
    }
    for(i=n-1;i>=0;i--)
    {
        if(s[i]>='a'&&s[i]<='z'||s[i]>='A'&&s[i]<'Z')
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
    reverse(result.begin(), result.end());
    return result;
}
int main()
{
    cout<<InfixToPrefix("(a-b/c)*(a/k-l)");
    return 0;
}

