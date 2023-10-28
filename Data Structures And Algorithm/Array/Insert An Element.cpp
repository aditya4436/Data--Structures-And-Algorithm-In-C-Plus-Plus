#include<iostream>
using namespace std;
int main()
{
    int arr[5], i, pos, x, n;
    cout<<"Enter the size  of an array:\n";
    cin>>n;

    cout<<"Enter the elements of array:\n";
    for(i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    cout<<"Array elements are:\n";
    for(i=0; i<n; i++)
    {
        cout<<arr[i]<<"  ";
    }
    cout<<endl;

    cout<<"Enter the new element to be inserted:\n";
    cin>>x;

    cout<<"Enter the position where you wish to insert an element:\n";
    cin>>pos;

    i=n;
    while(i>=pos)
    {
        arr[i]=arr[i-1];
        i--;
    }
    arr[pos-1]=x;

    cout<<"Array after inserting new element at: "<<pos<<" is:\n";
    for(i=0; i<n+1; i++)
    {
        cout<<arr[i]<<"  ";
    }

    return 0;
}
