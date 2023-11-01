// Time Complexity:- O(N^2), 'N' is the number of element.
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
void Insertion_Sort(int arr[], int n)
{
    int count=0;
    for(int i=0; i<n; i++)
    {
        int j=i;
        while(j>0 && arr[j-1]>arr[j])
        {
            swap(arr[j-1], arr[j]);
            j--;
            count++;
        }
    }
    cout<<"Loop is executed "<<count<<" times to sort an array.\n";
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
    int arr[]={64, 34, 25, 12, 22, 11, 90};
    int size=sizeof(arr)/sizeof(arr[0]);
    Insertion_Sort(arr, size);
    cout<<"Sorted array is:\n";
    Print_Array(arr, size);
    return 0;
}