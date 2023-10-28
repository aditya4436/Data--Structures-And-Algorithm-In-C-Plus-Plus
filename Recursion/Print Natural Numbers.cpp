#include<iostream>
using namespace std;
void Print_Array(int n)
{
    if(n==0)
    {
       return;
    }
    Print_Array(n-1);
    cout<<n<<"  ";
}
int main()
{
    int n=5;
    Print_Array(n);
    return 0;
}
