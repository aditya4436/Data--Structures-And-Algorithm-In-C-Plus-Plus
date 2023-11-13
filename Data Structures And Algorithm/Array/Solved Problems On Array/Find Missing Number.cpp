#include<bits/stdc++.h>
using namespace std;
// BRUTE FORCE APPROACH
// Time Complexity:- O(n^2)
// Space Complexity:- O(1);
// int MissingNumber(vector<int> &arr, int n)
// {
//     for(int i=1; i<=n; i++)
//     {
//         int flag=0;
//         for(int j=0; j<n; j++)
//         {
//             if(arr[j]==i)
//             {
//                 flag=1;
//                 break;
//             }
//         }
//         if(flag==0)
//         {
//             return i;
//         }
//     }
//     return -1;
// }

// BETTER THAN BRUTE FORCE APPROACH
// Time Complexity:- O(2n)
// Space Complexity:- O(n)
// int MissingNumber(vector<int> &arr, int n)
// {
//     vector<int> harr(n+1, 0);
//     for(int i=0; i<n; i++)
//     {
//         harr[arr[i]]=1;
//     }
//     for(int i=1; i<n+1; i++)
//     {
//         if(harr[i]==0)
//         {
//             return i;
//         }
//     }
//     return -1;
// }

// OPTIMIZED APPROACH
// Time Complexity:- O(n)
// Space Complexity:- O(1)
int MissingNumber(vector<int> &arr, int n)
{
    // int sum2=0;
    // int sum1=(n*(n+1))/2;
    // for(int i=0; i<n-1; i++)
    // {
    //     sum2+=arr[i];
    // }
    // return (sum1-sum2);
    int xor1=0, xor2=0;
    for(int i=0; i<n-1; i++)
    {
        xor2=xor2^arr[i];
        xor1=xor1^(i+1);
    }
    xor1=xor1^n;
    return (xor1^xor2);
}
int main()
{
    vector<int> arr={1, 2, 3, 4, 5, 6, 8};
    int n=arr.size();
    cout<<MissingNumber(arr, n);
    return 0;
}