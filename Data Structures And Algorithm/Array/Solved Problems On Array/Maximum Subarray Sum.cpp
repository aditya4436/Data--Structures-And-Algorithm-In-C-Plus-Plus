#include<bits/stdc++.h>
using namespace std;
// BRUTE-FORCE APPROACH-1
// Time complexity:- O(n^3)
// Space Complexity:- O(1)
// int MaximumSubarraySum(vector<int> &arr)
// {
//     int sum, maximum=INT_MIN;
//     for(int i=0; i<arr.size(); i++)
//     {
//         for(int j=i; j<arr.size(); j++)
//         {
//             sum=0;
//             for(int k=i; k<=j; k++)
//             {
//                 sum+=arr[k];
//                 maximum=max(maximum, sum);
//             }
//         }
//     }
//     return maximum;
// }

// BRUTE FORCE APPROACH-2
// Time Complexity:- O(n^2)
// Spacec Complexity:- O(1)
// int MaximumSubarraySum(vector<int> &arr)
// {
//     int sum, maximum=INT_MIN;
//     for(int i=0; i<arr.size(); i++)
//     {
//         sum=0;
//         for(int j=i; j<arr.size(); j++)
//         {
//             sum+=arr[j];
//             maximum=max(maximum, sum);
//         }
//     }
//     return maximum;
// }

// OPTIMAL APPROACH
// Time Complexity:- O(n)
// Space Complexity:- O(1)
int MaximumSubarraySum(vector<int> &arr)
{
    int sum=0, maximum=INT_MIN;
    for(int i=0; i<arr.size(); i++)
    {
        sum+=arr[i];
        maximum=max(sum, maximum);
        if(sum<0)
        {
            sum=0;
        }
        else if(sum>maximum)
        {
            maximum=sum;
        }
    }
    return maximum;
}
int main()
{
    vector<int> arr={5, 4, -1, 7, 8};
    cout<<MaximumSubarraySum(arr);
    return 0;
}