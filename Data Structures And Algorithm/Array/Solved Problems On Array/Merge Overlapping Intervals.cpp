#include<bits/stdc++.h>
using namespace std;
// BRUTE FORCE APPROACH
// Time Complexity:- O(n log n) O(2n)
// Space Complexity:- O(n), as we are using an 'ans' to store
//                    the merged intervals. Except for the 'ans'
//                    array we are not using any extra space.
// vector<vector<int>> MergeAllOverlappingIntervals(vector<vector<int>> &arr)
// {
//     vector<vector<int>> ans;
//     int n=arr.size();
//     sort(arr.begin(), arr.end());
//     for(int i=0; i<n; i++)
//     {
//         int start=arr[i][0];
//         int last=arr[i][1];
//         if(!ans.empty() && last<=ans.back()[1])
//         {
//             continue;
//         }
//         for(int j=i+1; j<n; j++)
//         {
//             if(arr[j][0]<=last)
//             {
//                 last=max(last, arr[j][1]);
//             }
//             else
//             {
//                 break;
//             }
//         }
//         ans.push_back({start, last});
//     }
//     return ans;
// }

// OPTIMIZED APPROACH
// Time Complexity:- O(n log n) + O(n)
// Space Complexity:- O(n), to store the 'ans'.
vector<vector<int>> MergeAllOverlappingIntervals(vector<vector<int>> &arr)
{
    vector<vector<int>> ans;
    int n=arr.size();
    for(int i=0; i<n; i++)
    {
        int start=arr[i][0];
        int end=arr[i][1];
        if(ans.empty() || arr[i][0]>ans.back()[1])
        {
            ans.push_back(arr[i]);
        }
        else
        {
            ans.back()[1]=max(arr[i][1], ans.back()[1]);
        }
    }
    return ans;
}
int main()
{
    vector<vector<int>> arr={{1,3}, {2,6}, {8,9}, {9,11}, {8,10}, {2,4}, {15,18}, {16,17}};
    vector<vector<int>> ans=MergeAllOverlappingIntervals(arr);
    for(auto it : ans)
    {
        cout<<"["<<it[0]<<",  "<<it[1]<<"],";
    }
    return 0;
}