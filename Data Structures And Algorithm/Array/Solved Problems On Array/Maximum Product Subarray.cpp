#include<bits/stdc++.h>
using namespace std;
// BRUTE FORCE APPROACH
// Time Complexity:- O(n^3)
// Space Complexity:- O(1)
// int MaximumProductSubarray(vector<int> &arr, int n)
// {
//     int maximum=INT_MIN;
//     for(int i=0; i<n; i++)
//     {
//         for(int j=i; j<n; j++)
//         {
//             int ans=1;
//             for(int k=i; k<=j; k++)
//             {
//                 ans*=arr[k];
//             }
//             maximum=max(ans, maximum);
//         }
//     }
//     return maximum;
// }

// BRUTE FORCE APPROACH
// Time Complexity:- O(n^2)
// Space Complexity:- O(1)
// int MaximumProductSubarray(vector<int> &arr, int n)
// {
//     int maximum=INT_MIN;
//     for(int i=0; i<n; i++)
//     {
//         int ans=1;
//         for(int j=i; j<n; j++)
//         {
//             ans*=arr[j];
//             maximum=max(ans, maximum);
//         }
//     }
//     return maximum;
// }

// OPTIMAL APPROACH
// Time Complexity:- O(n)
// Space Complexity:- O(1)
int MaximumProductSubarray(vector<int> &arr, int n)
{
    int prefix=1, suffix=1, maximum=INT_MIN;
    for(int i=0; i<n; i++)
    {
        prefix*=arr[i];
        suffix=arr[n-i-1];
        maximum=max(maximum, max(prefix, suffix));
        if(prefix==0)
        {
            prefix=1;
        }
        if(suffix==0)
        {
            suffix=1;
        }
    }
    return maximum;
}
int main()
{
    vector<int> arr={2,3,-2,4};
    int n=arr.size();
    cout<<MaximumProductSubarray(arr, n);
    return 0;
}