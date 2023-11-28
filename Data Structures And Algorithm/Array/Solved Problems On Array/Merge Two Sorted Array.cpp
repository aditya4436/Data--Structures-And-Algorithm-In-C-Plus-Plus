#include<bits/stdc++.h>
using namespace std;
// BRUTE FORCE APPROACH
// Time Complexity:- O(n+m)+O(n+m)
// Space Complexity:- O(n+m)
// void MergeSortedArray(vector<int> &arr1, vector<int> &arr2)
// {
//     int n=arr1.size(), m=arr2.size();
//     vector<int> ans;
//     int i=0, j=0;
//     while(i<n && j<m)
//     {
//         if(arr1[i]<arr2[j])
//         {
//             ans.push_back(arr1[i]);
//             i++;
//         }
//         else
//         {
//             ans.push_back(arr2[j]);
//             j++;
//         }
//     }
//     while(i<n && arr1[i]<arr2[j])
//     {
//         ans.push_back(arr1[i]);
//         i++;
//     }
//     while(j<m && arr2[j]<arr1[i])
//     {
//         ans.push_back(arr2[j]);
//         j++;
//     }
//     for(int i=0; i<n+m; i++)
//     {
//         if(i<n)
//         {
//             arr1[i]=ans[i];
//         }
//         else
//         {
//             arr2[i-n]=ans[i];
//         }
//     }
// }

// OPTIMIZED APPROACH-1
// Time Complexity:- O(min(n, m))+O(n log n)+O(n log n).
// Space Complexity:- O(1).
// void MergeSortedArray(vector<int> &arr1, vector<int> &arr2)
// {
//     int n=arr1.size(), m=arr2.size();
//     int i=n-1, j=0;
//     while(i>=0 && j<m)
//     {
//         if(arr1[i]>arr2[j])
//         {
//             swap(arr1[i], arr2[j]);
//             i--;
//             j++;
//         }
//         else
//         {
//             break;
//         }
//     }
//     sort(arr1.begin(), arr1.end());
//     sort(arr2.begin(), arr2.end());
// }

void swapIfGreater(vector<int> &arr1, vector<int> &arr2, int index1, int index2)
{
    if(arr1[index1]>arr2[index2])
    {
        swap(arr1[index1], arr2[index2]);
    }
}

// OPTIMIZED APPROACH
// Time Complexity:- O(log2(n+m))+O(n+m)
// Space Complexity:- O(1)
void MergeSortedArray(vector<int> &arr1, vector<int> &arr2)
{
    int n=arr1.size(), m=arr2.size();
    int len=n+m;
    int gap=(len/2)+(len%2);
    while(gap>0)
    {
        int left=0;
        int right=left+gap;
        while(right<len)
        {
            if(left<n && right>=n)
            {
                swapIfGreater(arr1, arr2, left, right-n);
            }
            else if(left>=n)
            {
                swapIfGreater(arr2, arr2, left-n, right-n);
            }
            else
            {
                swapIfGreater(arr1, arr1, left, right);
            }
            left++;
            right++;
        }
        if(gap==1)
        {
            break;
        }
        else
        {
            gap=(gap/2)+(gap%2);
        }
    }
}
int main()
{
    vector<int> arr1={1,3,5,7,9};
    vector<int> arr2={2,4,6,8,10};
    MergeSortedArray(arr1, arr2);
    for(int i=0; i<arr1.size(); i++)
    {
        cout<<arr1[i]<<"  ";
    }
    for(int i=0; i<arr2.size(); i++)
    {
        cout<<arr2[i]<<"  ";
    }
    return 0;
}