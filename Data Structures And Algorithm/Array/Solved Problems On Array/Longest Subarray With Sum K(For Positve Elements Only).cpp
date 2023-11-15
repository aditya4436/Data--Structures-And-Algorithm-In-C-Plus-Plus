#include<bits/stdc++.h>
using namespace std;
// BRUTE-FORCE APPROACH
// Time Complexity: O(n^3)
// Space Complexity:- O(1)
// int LongestSubarrayWithSumK(vector<int> &arr, int k)
// {
//     int n=arr.size(), len=0;
//     for(int i=0; i<n; i++)
//     {
//         for(int j=i; j<n; j++)
//         {
//             int s=0;
//             for(int k=i; k<=j; k++)
//             {
//                 s+=arr[k];
//             }
//             if(s==k)
//             {
//                 len=max(len, j-i+1);
//             }
//         }
//     }
//     return len;
// }

// BRUTE-FORCE APPROACH-2
// Time Complexity:- O(n^2)
// Space Complexity:- O(1)
// int LongestSubarrayWithSumK(vector<int> &arr, int k)
// {
//     int n=arr.size(), len=0;
//     for(int i=0; i<n; i++)
//     {
//         int s=0;
//         for(int j=i; j<n; j++)
//         {
//             s+=arr[j];
//             if(s==k)
//             {
//                 len=max(len, j-i+1);
//             }
//         }
//     }
//     return len;
// }

// BETTER THAN BRUTE-FORCE APPROACH
// Time Complexity:- O(n*log n)
// SpaceComplexity:- O(n)
// int LongestSubarrayWithSumK(vector<int> &arr, int k)
// {
//     int n=arr.size();
//     int maxlen=0, sum=0;
//     map<int, int> preSumMap;
//     for(int i=0; i<n; i++)
//     {
//         sum+=arr[i];
//         if(sum==k)
//         {
//             maxlen=max(maxlen, i+1);
//         }
//         int rem=sum-k;
//         if(preSumMap.find(rem)!=preSumMap.end())
//         {
//             int len=i-preSumMap[rem];
//             maxlen=max(maxlen, len);
//         }
//         if(preSumMap.find(sum)==preSumMap.end())
//         {
//             preSumMap[sum]=i;
//         }
//     }
//     return maxlen;
// }

// OPTIMIZED SOLUTION
// Time Complexity:- O(2n), the 'i' pointer can move to 'j' pointer
//                   atmost. The inner loop does not for 'n' times
//                   rather it can run for 'n' times in total.
// Space Complexity:- O(1)
int LongestSubarrayWithSumK(vector<int> &arr, long long k)
{
    int n=arr.size();
    int i=0, j=0, maxlen=0;
    long long sum=arr[0];
    while(j<n)
    {
        while(i<=j && sum>k)
        {
            sum-=arr[i];
            i++;
        }
        if(sum==k)
        {
            maxlen=max(maxlen, j-i+1);
        }
        j++;
        if(j<n)
        {
            sum+=arr[j];
        }
    }
    return maxlen;
}
int main()
{
    vector<int> arr={10, 5, 2, 7, 1, 9};
    long long k=15;
    cout<<LongestSubarrayWithSumK(arr, k);
    return 0;
}