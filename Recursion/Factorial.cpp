#include<iostream>
using namespace std;
int Factorial_Of_A_Positive_Number(int n)
{
    if(n==0 || n==1)
    {
        return n;
    }
    return n*Factorial_Of_A_Positive_Number(n-1);
}
int main()
{
    int positive_number;
    cout<<"Enter the number :\n";
    cin>>positive_number;
    cout<<"The factorial of "<<positive_number <<"  is:\n"<<Factorial_Of_A_Positive_Number(positive_number);
    return 0;
}
