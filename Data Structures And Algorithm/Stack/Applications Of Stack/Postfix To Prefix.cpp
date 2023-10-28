///A program to convert Postfix Expression to Prefix Expression
#include<iostream>
#include<stack>
using namespace std;
bool Is_Operand(char c)
{
    if(c>='a' && c<='z' || c>='A' && c<='Z')
    {
        return true;
    }
    else
    {
        return false;
    }
}
string Postfix_To_Prefix(string postfix)
{
    stack<string> s;
    for(int i=0;i<postfix.length(); i++)
    {
        if(Is_Operand(postfix[i]))
        {
            string op(1, postfix[i]);
            s.push(op);
        }
        else
        {
            string op1=s.top();
            s.pop();
            string op2=s.top();
            s.pop();
            string expression=postfix[i]+op2+op1;
            s.push(expression);
        }
    }
    return s.top();
}
int main()
{
    string Postfix_Expression, Prefix_Expression;
    cout<<"Enter a postfix expression:\n";
    cin>>Postfix_Expression;
    cout<<"Postfix Expression:\n"<<Postfix_Expression<<"\n";
    Prefix_Expression=Postfix_To_Prefix(Postfix_Expression);
    cout<<"Prefix expression:\n"<<Prefix_Expression<<endl;
    return 0;
}
