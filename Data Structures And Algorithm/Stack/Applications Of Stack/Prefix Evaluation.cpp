///A program to evaluate Prefix Expression
#include<iostream>
#include<stack>
#include<math.h>
using namespace std;
int Prefix_Evaluation(string s)
{
    stack<int> st;
    for(int i=s.length()-1; i>=0;i--)
    {
        if(s[i]>='0' && s[i]<='9')
        {
            st.push(s[i]-'0');
        }
        else
        {
            int op1=st.top();
            st.pop();
            int op2=st.top();
            st.pop();

            switch(s[i])
            {
                case '+':
                    st.push(op1+op2);
                    break;

                case '-':
                    st.push(op1-op2);
                    break;

                case '*':
                    st.push(op1*op2);
                    break;

                case '/':
                    st.push(op1/op2);
                    break;

                case '^':
                    st.push(pow(op1, op2));
                    break;
            }
        }
    }
    return st.top();
}
int main()
{
    string str;
    cout<<"Enter the Prefix Expression to evaluate:\n";
    getline(cin, str);
    cout<<"Evaluated Prefix Expression is:\n";
    cout<<Prefix_Evaluation(str);
    return 0;
}
