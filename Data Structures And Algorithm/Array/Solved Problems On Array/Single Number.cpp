#include<bits/stdc++.h>
using namespace std;
// BRUTE-FORCE APPROACH
// Time Complexity:- O(n^2)
// Space Complexity:- O(1)
// int GetSingleNumber(vector<int> &arr, int n)
// {
//     int num, count;
//     for(int i=0; i<n; i++)
//     {
//         num=arr[i], count=0;
//         for(int j=0; j<n; j++)
//         {
//             if(arr[i]==arr[j])
//             {
//                 count++;
//             }
//         }
//         if(count==1)
//         {
//             return num;
//         }
//     }
//     return -1;
// }

// BETTER THAN BRUTE-FORCE APPROACH
// Time Complexity:- O(2n+m+1)
// Sapce Complexity:- O(m+1)
// int GetSingleNumber(vector<int> &arr, int n)
// {
//     int m=arr[0], num;
//     for(int i=0; i<n; i++)
//     {
//         m=max(m, arr[i]);
//     }
//     vector<int> harr(m+1, 0);
//     for(int i=0; i<n; i++)
//     {
//         harr[arr[i]]++;
//     }
//     for(int i=1; i<=m+1; i++)
//     {
//         if(harr[i]==1)
//         {
//             return i;
//         }
//     }
//     return -1;
// }

// BETTER APPROACH 2
// Time Complexity:- O(n*log m), 'n' is the size of array and
//                   'm' is the size of map.
// Space Complexity:- O(m), 'm' is the size of map i.e., m=(n/2)+1/
// int GetSingleNumber(vector<int> &arr, int n)
// {
//     map<int, int> m;
//     for(int i=0; i<n; i++)
//     {
//         m[arr[i]]++;
//     }
//     for(auto i : m)
//     {
//         if(i.second==1)
//         {
//             return i.first;
//         }
//     }
//     return -1;
// }

// OPTIMIZED SOLUTION
// Time Complexity:- O(n)
// Space Complexity:- O(1)
int GetSingleNumber(vector<int> &arr, int n)
{
    int num=0;
    for(int i=0; i<n; i++)
    {
        num=num^arr[i];
    }
    return num;
}
int main()
{
    vector<int> arr={1, 1, 7, 5, 7};
    int n=arr.size();
    cout<<GetSingleNumber(arr, n);
    return 0;
}