#include<iostream>
using namespace std;
int Sum_Of_Array(int arr[], int n)
{
    if(n==0)
    {
        return 0;
    }
    else
    {
        return(arr[n-1]+Sum_Of_Array(arr, n-1));
    }
}
int main()
{
    int arr[]={1, 2, 3, 4};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"Sum of Array:\n";
    cout<<Sum_Of_Array(arr, n);
    return 0;
}
