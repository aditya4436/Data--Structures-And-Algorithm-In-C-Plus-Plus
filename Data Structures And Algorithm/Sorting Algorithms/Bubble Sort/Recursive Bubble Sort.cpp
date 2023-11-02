// Time Complexity:- O(N^2), 'N' is the number of element.
// Auxiliary Space Complexity:- O(1).
#include<iostream>
using namespace std;
void Recursive_Bubble_Sort(int arr[], int n)
{
    if(n==1)
    {
        return;
    }
    for(int i=0; i<n-1; i++)
    {
        if(arr[i]>arr[i+1])
        {
            swap(arr[i], arr[i+1]);
        }
    }
    Recursive_Bubble_Sort(arr, n-1);
}
void Print_Array(int arr[], int size)
{
    int i;
    for(i=0; i<size; i++)
    {
        cout<<arr[i]<<"  ";
    }
}
int main()
{
    int arr[]={13, 46, 24, 52, 20, 9};
    int size=sizeof(arr)/sizeof(arr[0]);
    Recursive_Bubble_Sort(arr, size);
    cout<<"Sorted array is:\n";
    Print_Array(arr, size);
    return 0;
}