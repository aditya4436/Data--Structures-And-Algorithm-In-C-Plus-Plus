#include<bits/stdc++.h>
using namespace std;
// BRUTE-FORCE APPROACH
// Time Complexity:- O(n)
// Space Complexity:- O(1)
// string TwoSum(vector<int> &arr, int target)
// {
//     int n=arr.size();
//     for(int i=0; i<n; i++)
//     {
//         for(int j=i+1; j<n; j++)
//         {
//             if(arr[i]+arr[j]==target)
//             {
//                 return "YES";
//             }
//         }
//     }
//     return "NO";
// }

// BETTER THAN BRUTE-FORCE APPROACH
// Time Complexity:- O(n)
// Worst Case Time Complexity:- O(n^2), because I have used unordered_map.
// Space Complexity:- O(n)
// string TwoSum(vector<int> &arr, int target)
// {
//     int n=arr.size();
//     unordered_map<int, int> inMap;
//     for(int i=0; i<n ;i++)
//     {
//         int num=arr[i];
//         int need=target-num;
//         if(inMap.find(need)!=inMap.end())
//         {
//             return "YES";
//         }
//         inMap[num]=i;
//     }
//     return "NO";
// }

// OPTIMAL SOLUTION
// Time Complexity:- O(n)
// Space Complexity:- O(1)
string TwoSum(vector<int> &arr, int target)
{
    sort(arr.begin(), arr.end());
    int i=0;
    int j=arr.size()-1;
    while(i<j)
    {
        if(arr[i]+arr[j]>target)
        {
            j--;
        }
        else if(arr[i]+arr[j]<target)
        {
            i++;
        }
        else if(arr[i]+arr[j]==target)
        {
            return "YES";
        }
    }
    return "NO";
}
int main()
{
    vector<int> arr={2, 7, 11, 15};
    int target=9;
    cout<<TwoSum(arr, target);
    return 0;
}