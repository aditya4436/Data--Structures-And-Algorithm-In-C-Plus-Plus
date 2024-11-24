t#include<iostream>
using namespace std;
int main()
{
    int arr[]={99, 81, 88, 44, 36};
    int i, n, pos, x;

    n=sizeof(arr)/sizeof(arr[0]);

    cout<<"Array is:\n";
    for(i=0;i <n; i++)
    {
        cout<<arr[i]<<"  ";
    }
    cout<<endl;

    cout<<"Enter a new number to update an array:\n";
    cin>>x;

    cout<<"Enter the position:\n";
    cin>>pos;

    arr[pos-1]=x;
    cout<<"Updated array is:\n";
    for(i=0; i<n; i++)
    {
        cout<<arr[i]<<"  ";
    }
    cout<<endl;
    return 0;
}
