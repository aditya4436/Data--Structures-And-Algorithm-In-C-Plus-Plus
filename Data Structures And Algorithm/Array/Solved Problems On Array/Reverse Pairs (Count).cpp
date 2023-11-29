#include<bits/stdc++.h>
using namespace std;
// BRUTE FORCE APPROACH
// Time Complexity:- O(n^2)
// Space Complexity:- O(1)
// int ReversePairs(vector<int> &arr, int n)
// {
//     int count=0;
//     for(int i=0; i<n; i++)
//     {
//         for(int j=i+1; j<n; j++)
//         {
//             if(arr[i]>2*arr[j])
//             {
//                 count++;
//             }
//         }
//     }
//     return count;
// }

// OPTIMIZED APPROACH
// Time Complexity:- 2n(log n)
// Space Complexity:- O(n) to merge. Here we are distorting the array.
//                    We can also do it by taking the copy of the array
//                    and do the same thing on the copied array.
void Merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;
    int left=low;
    int right=mid+1;
    while(left<=mid && right<=high)
    {
        if(arr[left]<arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left<=mid)
    {
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=high)
    {
        temp.push_back(arr[right]);
        right++;
    }
    for(int i=low; i<=high; i++)
    {
        arr[i]=temp[i-low];
    }
}
int CountPairs(vector<int> &arr, int low, int mid, int high)
{
    int count=0, right=mid+1;
    for(int i=low; i<=mid; i++)
    {
        while(right<=high && arr[i]>(2*arr[right]))
        {
            right++;
        }
        count+=(right-(mid+1));
    }
    return count;
}
int MergeSort(vector<int> &arr, int low, int high)
{
    int count=0;
    if(low>=high)
    {
        return count;
    }
    int mid=(low+high)/2;
    count+=MergeSort(arr, low, mid);
    count+=MergeSort(arr, mid+1, high);
    count+=CountPairs(arr, low, mid, high);
    Merge(arr, low, mid, high);
    return count;
}
int ReversePairs(vector<int> &arr, int n)
{
    return MergeSort(arr, 0, n-1);
}
int main()
{
    vector<int> arr={4,1,2,3,1};
    int n=arr.size();
    cout<<ReversePairs(arr, n);
    return 0;
}