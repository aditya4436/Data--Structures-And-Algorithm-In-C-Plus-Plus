///A program to convert Prefix Expression to Postfix Expression
#include<iostream>
#include<stack>
using namespace std;
bool Check_If_Operator(char x)
{
    switch(x)
    {
    case '+':
    case '-':
    case '/':
    case '*':
    case '%':
    case '^':
        return true;
    }
    return false;
}
string Prefix_To_Postfix(string pre_exp)
{
    stack<string> s;
    int length;
    length=pre_exp.size();
    for(int i=length-1; i>=0; i--)
    {
        if(Check_If_Operator(pre_exp[i]))
        {
            string op1=s.top();
            s.pop();
            string op2=s.top();
            s.pop();
            string temp=op1+op2+pre_exp[i];
            s.push(temp);
        }
        else
        {
            s.push(string(1, pre_exp[i]));
        }
    }
    return s.top();
}
int main()
{
    string pre_exp="*-A/BC-/AKL";
    cout<<"Postfix:\n"<<Prefix_To_Postfix(pre_exp);
    return 0;
}
