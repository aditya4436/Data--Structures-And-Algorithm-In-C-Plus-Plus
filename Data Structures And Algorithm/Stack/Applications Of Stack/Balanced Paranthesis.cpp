///A program to check if the parenthesis are balanced not
#include<iostream>
#include<stack>
using namespace std;
bool Is_Valid(string s)
{
    int n=s.size();
    stack<char> st;
    bool ans=true;
    for(int i=0; i<n; i++)
    {
        if(s[i]=='{' || s[i]=='(' ||s[i]=='[')
        {
            st.push(s[i]);
        }
        else if(s[i]==')')
        {
            if(!st.empty() && st.top()=='(')
            {
                st.pop();
            }
            else
            {
                ans=false;
                break;
            }
        }
        else if(s[i]==']')
        {
            if(!st.empty() && st.top()=='[')
            {
                st.pop();
            }
            else
            {
                ans=false;
                break;
            }
        }
        else if(s[i]=='}')
        {
            if(!st.empty() && st.top()=='{')
            {
                st.pop();
            }
            else
            {
                ans=false;
                break;
            }
        }
    }
    if(!st.empty())
    {
        return false;
    }
    else
    {
        return ans;
    }
}
int main()
{
    string s="{([])}";

    if(Is_Valid(s))
    {
        cout<<"Valid string.";
    }
    else
    {
        cout<<"Invalid string.";
    }
    return 0;
}

