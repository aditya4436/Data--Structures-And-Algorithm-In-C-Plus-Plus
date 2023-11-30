// Time Complexity:- O(log N), where n is the number of elements in an array.
// Auxiliary Space Complexity:- O(1).
#include<iostream>
using namespace std;
// int RecursiveBinarySearch(vector<int> &arr, int low, int high, int target)
// {
//     if(low>high)
//     {
//         return -1;
//     }
//     int mid=(low+high)/2;
//     if(arr[mid]==target)
//     {
//         return mid;
//     }
//     else if(target>arr[mid])
//     {
//         return RecursiveBinarySearch(arr, mid+1, high, target);
//     }
//     return RecursiveBinarySearch(arr, low, mid-1, target);
// }
// int search(vector<int> &nums, int target)
// {
//     return RecursiveBinarySearch(nums, 0, nums.size()-1, target);
// }

// Time Complexity:- O(log N), where n is the number of elements in an array.
// Auxiliary Space Complexity:- O(1).
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
