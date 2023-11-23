#include<bits/stdc++.h>
using namespace std;
// BRUTE-FORCE APPROACH-1
// Time Complexity:- O(n^3)
// Space Complexity:- O(1)
// int SubArraySum(vector<int> &arr, int s)
// {
//     int n=arr.size(), count=0;
//     for(int i=0; i<n; i++)
//     {
//         for(int j=i; j<n; j++)
//         {
//             int sum=0;
//             for(int k=i; k<=j; k++)
//             {
//                 sum+=arr[k];
//             }
//             if(sum==s)
//             {
//                 count++;
//             }
//         }
//     }
//     return count;
// }

// BRUTE-FORCE APPROACH-2
// Time Complexity:- O(n^2)
// Space Complexity:- O(1)
// int SubArraySum(vector<int> &arr, int s)
// {
//     int n=arr.size(), count=0;
//     for(int i=0; i<n; i++)
//     {
//         int sum=0;
//         for(int j=i; j<n; j++)
//         {
//             sum+=arr[j];
//             if(sum==s)
//             {
//                 count++;
//             }
//         }
//     }
//     return count;
// }

int SubArraySum(vector<int> &arr, int k)
{
    map<int, int> mpp;
    int count=0, presum=0;
    mpp[0]=1;
    for(int i=0; i<arr.size(); i++)
    {
        presum+=arr[i];
        int remove=presum-k;
        count+=mpp[remove];
        mpp[presum]+=1;
    }
    return count;
}
int main()
{
    vector<int> arr={10,2,-2,-20,10};
    int k=-10;
    cout<<SubArraySum(arr, k);
    return 0;
}