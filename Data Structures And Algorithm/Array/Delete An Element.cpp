///A program to delete an array element
#include<iostream>
using namespace std;
int main()
{
    int arr[5], n, i, pos;
    cout<<"Enter the size of an array:\n";
    cin>>n;

    cout<<"Enter the array elements:\n";
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

    cout<<"Enter the position of an element you want to delete:\n";
    cin>>pos;

    i=pos-1;
    while(i<n)
    {
        arr[i]=arr[i+1];
        i++;
    }

    cout<<"Array after deleting an element from "<<pos<<" is:\n";
    for(i=0; i<n-1; i++)
    {
        cout<<arr[i]<<"  ";
    }
    return 0;
}
