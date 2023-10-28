#include<iostream>
#include<algorithm>
using namespace std;
string Reverse_The_String(string str)
{
    if(str.size()==0 ||str.size()==1 )
    {
        return str;
    }
    else
    {
        return Reverse_The_String (str.substr(1))+str[0];
    }
}
int main()
{
    cout<<Reverse_The_String("Aditya");
    return 0;
}
