#include<bits/stdc++.h>
using namespace std;
// BRUTE-FORCE APPROACH
// Time Complexity:- O(n)
// Space Complexity:- O(1)
// vector<int> TwoSum(vector<int> &arr, int target)
// {
//     int n=arr.size();
//     for(int i=0; i<n; i++)
//     {
//         for(int j=i+1; j<n; j++)
//         {
//             if(arr[i]+arr[j]==target)
//             {
//                 return{i, j};
//             }
//         }
//     }
//     return {-1, -1};
// }

// BETTER THAN BRUTE-FORCE APPROACH
// Time Complexity:- O(n)
// Worst Case Time Complexity:- O(n^2), because I have used unordered_map.
// Space Complexity:- O(n)
vector<int> TwoSum(vector<int> &arr, int target)
{
    int n=arr.size();
    unordered_map<int, int> inMap;
    for(int i=0; i<n ;i++)
    {
        int num=arr[i];
        int need=target-num;
        if(inMap.find(need)!=inMap.end())
        {
            return{inMap[need], i};
        }
        inMap[num]=i;
    }
    return {-1, -1};
}
int main()
{
    vector<int> arr={2, 7, 11, 15};
    int target=22;
    vector<int> array=TwoSum(arr, target);
    for(int i=0; i<2; i++)
    {
        cout<<array[i]<<"  ";
    }
    return 0;
}