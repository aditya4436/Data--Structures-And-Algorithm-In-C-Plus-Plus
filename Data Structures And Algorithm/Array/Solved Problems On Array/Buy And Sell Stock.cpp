#include<bits/stdc++.h>
using namespace std;
// Time Complexity:- O(n^2)
// Space Complexity:- O(1)
// int MaximumProfit(vector<int> &arr)
// {
//     int profit=0, maxprofit=INT_MIN;
//     for(int i=0; i<arr.size(); i++)
//     {
//         for(int j=i+1; j<arr.size(); j++)
//         {
//             profit=arr[j]-arr[i];
//             maxprofit=max(profit, maxprofit);
//         }
//     }
//     return maxprofit;
// }

// OPTIMIZED APPROACH
// Time Complexity:- O(n)
// Space Complexity:- O(1)
int MaximumProfit(vector<int> &arr)
{
    int minimum=arr[0], maxprofit=0;
    for(int i=1; i<arr.size(); i++)
    {
        int cost=arr[i]-minimum;
        maxprofit=max(maxprofit, cost);
        minimum=min(arr[i], minimum);
    }
    return  maxprofit;
}
int main()
{
    vector<int> arr={100, 180, 260, 310, 40, 535, 695};
    cout<<MaximumProfit(arr);
    return 0;
}