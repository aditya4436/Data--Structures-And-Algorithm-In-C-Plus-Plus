#include<iostream>
using namespace std;
int Partitioning_Of_Array(int arr[], int low, int high)
{
    int pivot=arr[low];
    int i=low;
    int j=high;
    while(i<j)
    {
        while(arr[i]<=pivot && i<high)
        {
            i++;
        }
        while(arr[j]>pivot && j>low)
        {
            j--;
        }
        if(i<j)
        {
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[low], arr[j]);
    return j;
}
void Quick_Sort(int arr[], int low, int high)
{
    if(low<high)
    {
        int pIndex=Partitioning_Of_Array(arr, low, high);
        Quick_Sort(arr, low, pIndex-1);
        Quick_Sort(arr, pIndex+1, high);
    }
}
int main()
{
    int arr[]={13, 46, 24, 52, 20, 9};
    int size=sizeof(arr)/sizeof(arr[0]);
    Quick_Sort(arr, 0, size-1);
    cout<<"\nSorted array is:\n";
    int i;
    for(i=0; i<size; i++)
    {
        cout<<arr[i]<<"  ";
    }
    return 0;
}