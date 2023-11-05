// Time Complexity:- O(N logN)
// Auxiliary Space Complexity:- O(N), due to recursive call stack.
#include<iostream>
using namespace std;
void Heapify(int arr[], int n, int i)
{
    int largest=i;
    int l=2*i+1;
    int r=2*i+2;
    if(l<n && arr[l]>arr[largest])
    {
        largest=l;
    }
    if(r<n && arr[r]>arr[largest])
    {
        largest=r;
    }
    if(largest!=i)
    {
        swap(arr[i], arr[largest]);
        Heapify(arr, n, largest);
    }
}
void Heap_Sort(int arr[], int n)
{
    for(int i=n/2-1; i>=0; i--)
    {
        Heapify(arr, n, i);
    }
    for(int i=n-1; i>0; i--)
    {
        swap(arr[0], arr[i]);
        Heapify(arr, i, 0);
    }
}
void Print_Array(int arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<"  ";
    }
}
int main()
{
    int arr[]={13, 46, 24, 52, 20, 9};
    int size=sizeof(arr)/sizeof(arr[0]);
    Heap_Sort(arr, size);
    cout<<"\nSorted array is:\n";
    int i;
   Print_Array(arr, size);
    return 0;
}
