#include<iostream>
#include<vector>
using namespace std;
void ReverseString(string str, int n)
{
    if(n>=0)
    {
        cout<<str[n-1]<<"  ";
        ReverseString(str, n-1);
    }
}
int main()
{
    int n;
    string str="aditya";
    n=str.size();
    ReverseString(str, n);
    return 0;
}
