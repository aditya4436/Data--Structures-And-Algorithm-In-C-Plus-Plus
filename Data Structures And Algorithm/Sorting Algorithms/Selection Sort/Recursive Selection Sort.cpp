// Time Complexity:- O(N), where N is the size of an array.
#include<iostream>
using namespace std;
int Minimum_Index(int arr[], int i, int j)
{
    if(i==j)
    {
        return i;
    }
    int k=Minimum_Index(arr, i+1, j);
    return (arr[i]<arr[k])? i : k;
}
void Selection_Sort(int arr[], int n, int index=0)
{
    if(index==n)
    {
        return;
    }
    int k=Minimum_Index(arr, index, n-1);
    if(index!=k)
    {
        swap(arr[index], arr[k]);
    }
    Selection_Sort(arr, n, index+1);
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
    Selection_Sort(arr, size, 0);
    cout<<"Sorted array is:\n";
    Print_Array(arr, size);
    return 0;
}