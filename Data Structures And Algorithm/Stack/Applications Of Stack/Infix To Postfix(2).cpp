#include<bits/stdc++.h>
using namespace std;
int Precedence(char c)
{
    if(c=='+' || c=='-')
    {
        return 1;
    }
    else if(c=='*' || c=='/')
    {
        return 2;
    }
    else if(c=='^')
    {
        return 3;
    }
    else
    {
        return -1;
    }
}
string Infix_To_Postfix(string s)
{
    string res;
    stack<char> st;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]>='A' && s[i]<='Z' || s[i]>='a' && s[i]<='z')
        {
            res+=s[i];
        }
        else if(s[i]=='(')
        {
            st.push(s[i]);
        }
        else if(s[i]==')')
        {
            while(!st.empty() && st.top()!='(')
            {
                res+=st.top();
                st.pop();
            }
            if(!st.empty())
            {
                st.pop();
            }
        }
        else
        {
            while(!st.empty() && Precedence(s[i])<=Precedence(st.top()))
            {
                res+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty())
    {
        res+=st.top();
        st.pop();
    }
    return res;
}
int main()
{
    string expression="((a+b)-c*(d/e))+f";
    cout<<Infix_To_Postfix(expression);
    return 0;
}

