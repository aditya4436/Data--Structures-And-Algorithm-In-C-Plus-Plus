// Time Complexity:- O(N^2), 'N' is the number of element.
// Auxiliary Space Complexity:- O(1)
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
void Bubble_Sort(int arr[], int n)
{
    int i, j;
    bool swapped;
    for(i=0; i<n-1; i++)
    {
        swapped=false;
        for(j=0; j<n-i-1; j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j], arr[j+1]);
                swapped=true;
            }
        }
        if(swapped==false)
        {
            break;
        }
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
    Bubble_Sort(arr, size);
    cout<<"Sorted array is:\n";
    Print_Array(arr, size);
    return 0;
}