#include<iostream>
#include<algorithm>
using namespace std;
int Reverse_An_Array(int arr[], int n)
{
    if(n==0||n==1)
    {
        return n;
    }
    cout<<arr[n-1]<<"  ";
    return (Reverse_An_Array(arr, n-1));
}
int main()
{
    int n, arr[5];
    n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<5;i++)
    {
        cout<<"Enter the array element:\n";
        cin>>arr[i];
    }
    cout<<"Reversed Array is:\n"<<Reverse_An_Array(arr, n);
    return 0;
}
