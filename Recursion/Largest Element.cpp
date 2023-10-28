#include<iostream>
using namespace std;
int Largest_Element(int arr[], int n)
{
    if(n==1)
    {
        return arr[0];
    }
    else
    {
        return max(Largest_Element(arr, n-1), arr[n-1]);
    }
}
int main()
{
    int n, arr[]={200, 32, 40, 23};
    n=sizeof(arr)/sizeof(arr[0]);
    cout<<Largest_Element(arr, n);
    return 0;
}
