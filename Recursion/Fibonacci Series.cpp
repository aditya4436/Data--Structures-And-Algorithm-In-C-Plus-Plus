#include<iostream>
using namespace std;
int Fibonacci_Numbers(int n)
{
    if(n==0)
    {
        return 0;
    }
    else if(n==1)
    {
        return 1;
    }
    else
    {
        return Fibonacci_Numbers(n-1)+Fibonacci_Numbers(n-2);
    }
}
int main()
{
    int number_of_fibonacci_series_to_print=10;
    int i=0;
    cout<<number_of_fibonacci_series_to_print<<" Fibonacci series are as follow:\n";
    while(i<number_of_fibonacci_series_to_print)
    {
        cout<<Fibonacci_Numbers(i)<<"  ";
        i++;
    }
    return 0;
}

