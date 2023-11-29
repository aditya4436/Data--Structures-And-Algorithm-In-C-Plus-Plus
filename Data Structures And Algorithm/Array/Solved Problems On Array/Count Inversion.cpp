#include<bits/stdc++.h>
#include<vector>
using namespace std;
// BRUTE FORCE APPROACH
// Time Complexity:- O(n^2)
// Space Complexity:- O(1)
// int CountInversion(vector<int> &arr, int n)
// {
//     int count=0;
//     for(int i=0; i<n; i++)
//     {
//         for(int j=i+1; j<n; j++)
//         {
//             if(arr[i]>arr[j])
//             {
//                 count++;
//             }
//         }
//     }
//     return count;
// }

// OPTIMAL APPROACH
// Time Complexity:- O(N LogN), N is the size of the vetor.
// Auxiliary Space Complexity:- O(N), we are using additional space while merging
//                              the elements of the vector.
int Merge(vector<int> arr, int low, int mid, int high)
{
    vector<int> temp;
    int left=low, count=0;
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
            count+=(mid-left+1);
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
    count+=Merge(arr, low, mid, high);
    return count;
}
int CountInversion(vector<int> &arr, int n)
{
    return MergeSort(arr, 0, n-1);
}
int main()
{
    vector<int> arr={5, 4, 3, 2, 1};
    int n=arr.size();
    cout<<CountInversion(arr, n);
    return 0;
}
