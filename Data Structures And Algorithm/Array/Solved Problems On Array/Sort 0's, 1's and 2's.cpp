#include<bits/stdc++.h>
using namespace std;
// Time Complexity:- O(2n)
// Space Complexity:- O(1)
// vector<int> SortZeroesOnesAndTwos(vector<int> &arr)
// {
//     int count0=0, count1=0, count2=0;
//     for(int i=0; i<arr.size(); i++)
//     {
//         if(arr[i]==0)
//         {
//             count0++;
//         }
//         if(arr[i]==1)
//         {
//             count1++;
//         }
//         if(arr[i]==2)
//         {
//             count2++;
//         }
//     }
//     for(int i=0; i<count0; i++)
//     {
//         arr[i]=0;
//     }
//     for(int i=count0; i<count0+count1; i++)
//     {
//         arr[i]=1;
//     }
//     for(int i=count0+count1; i<arr.size(); i++)
//     {
//         arr[i]=2;
//     }
//     return arr;
// }

// BRUTE-F0RCE APPROACH
// Time Complexity:- O(n*log n)
// Auxiliary Space Complexity:- O(N), we are using additional space while merging
//                              the elements of the vector.
// void Merge(vector<int> &arr, int low, int mid, int high)
// {
//     vector<int> temp;
//     int left=low;
//     int right=mid+1;
//     while(left<=mid && right<=high)
//     {
//         if(arr[left]<arr[right])
//         {
//             temp.push_back(arr[left]);
//             left++;
//         }
//         else
//         {
//             temp.push_back(arr[right]);
//             right++;
//         }
//     }
//     while(left<=mid)
//     {
//         temp.push_back(arr[left]);
//         left++;
//     }
//     while(right<=high)
//     {
//         temp.push_back(arr[right]);
//         right++;
//     }
//     for(int i=low; i<=high; i++)
//     {
//         arr[i]=temp[i-low];
//     }
// }
// void Merge_Sort(vector<int> &arr, int low, int high)
// {
//     // low=0;
//     // high=arr.size()-1;
//     if(low>=high)
//     {
//         return;
//     }
//     int mid=(low+high)/2;
//     Merge_Sort(arr, low, mid);
//     Merge_Sort(arr, mid+1, high);
//     Merge(arr, low, mid, high);
// }
// void Print_Array(vector<int> &arr, int n)
// {
//     for(int i=0; i<n; i++)
//     {
//         cout<<arr[i]<<"  ";
//     }
// }

// OPTIMIZED APPROACH
// Dutch National Algorithm
// Time Complexity:- O(n)
// Space Complexity:- O(1)
vector<int> SortZeroesOnesAndTwos(vector<int> &arr)
{
    int low=0, mid=0, high=arr.size()-1;
    while(mid<=high)
    {
        if(arr[mid]==0)
        {
            swap(arr[mid], arr[low]);
            low++;
            mid++;
        }
        else if(arr[mid]==1)
        {
            mid++;
        }
        else
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
    return arr;
}
int main()
{
    vector<int> arr={0, 2, 0, 1, 0, 0, 1, 1, 2, 2, 1};
    vector<int> array={SortZeroesOnesAndTwos(arr)};
    for(int i=0; i<arr.size(); i++)
    {
        cout<<arr[i]<<"  ";
    }
    // Merge_Sort(arr, 0, arr.size()-1);
    // Print_Array(arr, arr.size());
    return 0;
}