// Time Complexity:- O(N^2), 'N' is the number of element.
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
void Selection_Sort(int arr[], int n)
{
    int i, j;
    for(i=0; i<n-1; i++)
    {
        int min=i;
        for(int j=i; j<n; j++)
       { 
            if(arr[j]<arr[min])
            {
                min=j;
            }
        }
        swap(arr[i], arr[min]);
    }
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
    Selection_Sort(arr, size);
    cout<<"Sorted array is:\n";
    Print_Array(arr, size);
    return 0;
}