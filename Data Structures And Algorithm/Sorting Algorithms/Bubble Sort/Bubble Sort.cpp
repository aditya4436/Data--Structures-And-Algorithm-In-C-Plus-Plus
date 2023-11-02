// Time Complexity:- O(N^2), 'N' is the number of element.
// Best Time Complexity:- O(N), after optimization
// Auxiliary Space Complexity:- O(1)
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
void Bubble_Sort(int arr[], int n)
{
    int i, j, count=0;
    bool swapped;
    for(i=n-1; i>=0; i--)
    {
        swapped=false;
        for(j=0; j<i; j++)
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
        count++;
    }
    cout<<"Loop executed "<<count<<" times to sort an array.";
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
    Bubble_Sort(arr, size);
    cout<<"\nSorted array is:\n";
    Print_Array(arr, size);
    return 0;
}