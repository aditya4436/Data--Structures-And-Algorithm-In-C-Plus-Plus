#include<iostream>
using namespace std;
int Lucas_Series(int n)
{
    if(n==0)
    {
        return 2;
    }
    else if(n==1)
    {
        return 1;
    }
    return Lucas_Series(n-1)+Lucas_Series(n-2);
}
int main()
{
    int number_of_lucas_series_required=10;
    cout<<number_of_lucas_series_required<<" Lucas series are as follow:\n";
    for(int i=0; i<number_of_lucas_series_required;i++)
    {
        cout<<Lucas_Series(i)<<"  ";
    }
    return 0;
}

