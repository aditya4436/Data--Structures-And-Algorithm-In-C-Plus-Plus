#include<iostream>
using namespace std;
int main()
{
    int arr[5], i, n, x;

    cout<<"Enter the size of an array:\n";
    cin>>n;

    cout<<"Enter the elements of an array:\n";
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

    cout<<"Enter the number you want to search:\n";
    cin>>x;

    i=0;
    while(i<n)
    {
        if(arr[i]==x)
        {
            cout<<"Entered number is at position:\n"<<i+1<<endl;
            return 0;
        }
        i++;
    }
    cout<<"Entered number does not exist...";
    return 0;
}
