// Time Complexity:- O(N^2), in this alogrithm the gap is reduced by half
//                   in each iteration.
// Auxiliary Space Complexity:- O(1)
#include<iostream>
using namespace std;
void Shell_Sort(int arr[], int n)
{
    for(int gap=n/2; gap>=1; gap/=2)
    {
        for(int i=gap; i<n; i++)
        {
            for(int j=i-gap; j>=0; j-=gap)
            {
                if(arr[j+gap]>arr[j])
                {
                    break;
                }
                else
                {
                    swap(arr[j+gap], arr[j]);
                }
            }
        }
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
    int arr[]={12, 34, 54, 2, 3}, i;
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"Array after sorting:\n";
    Shell_Sort(arr, n);
    Print_Array(arr, n);
    return 0;
}