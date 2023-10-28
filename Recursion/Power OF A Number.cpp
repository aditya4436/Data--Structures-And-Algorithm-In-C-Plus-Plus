#include<iostream>
using namespace std;
int Power_Of_Number(int x, int n)
{
    if(x==0)
    {
        return 0;
    }
    else if(n==0)
    {
        return 1;
    }
    else
    {
        return x*Power_Of_Number(x, n-1);
    }
}
int main()
{
    cout<<"The result is:\n"<<Power_Of_Number(5, 4);
    return 0;
}
