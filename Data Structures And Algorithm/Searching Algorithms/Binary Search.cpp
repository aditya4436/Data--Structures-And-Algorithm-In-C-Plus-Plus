#include<iostream>
using namespace std;
int Binary_Search(int arr[], int low, int high, int target)
{
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(arr[mid]*arr[mid]==target)
        {
            return mid;
        }
        else if(arr[mid]<target)
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    return -1;
}
int main()
{
    int arr[]={1, 2, 5, 8, 12};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"The number is at index:\n"<<Binary_Search(arr, 0, n-1, 25);
    return 0;
}