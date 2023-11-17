#include<bits/stdc++.h>
using namespace std;
// Time Complexity:- O(n*log n)
// Space Complexity:- O(1)
// int MajorityElement(vector<int> v)
// {
// 	int n=v.size();
// 	sort(v.begin(), v.end());
// 	return v[n/2];
// }

// BRUTE-FORCE APPROACH
// Time Complexity:- O(n^2)
// Space Complexity:- O(1)
// int MajorityElement(vector<int> v) 
// {
//     int n=v.size();
// 	for(int i=0; i<n; i++)
//     {
//         int count=0;
//         for(int j=0; j<n; j++)
//         {
//             if(v[j]==v[i])
//             {
//                 count++;
//             }
//         }
//         if(count>(n/2))
//         {
//             return v[i];
//         }
//     }
//     return -1;
// }

// Time Complexity:- O(2n+2m)
// Space Complexity:- O(1)
// int MajorityElement(vector<int> arr) 
// {
//     int n=arr.size();
//     int maxElement=arr[0];
//     for(int i=0; i<n; i++)
//     {
//         maxElement=max(maxElement, arr[i]);
//     }
//     vector<int> harr(maxElement+1, 0);
//     for(int i=0; i<n; i++)
//     {
//         harr[arr[i]]++;
//     }
//     int majorityElement=0;
//     for(int i=1; i<=maxElement; i++)
//     {
//         majorityElement=max(majorityElement, harr[i]);
//     }
//     for(int i=1; i<=maxElement; i++)
//     {
//         if(majorityElement==harr[i])
//         {
//             return i;
//         }
//     }
//     return -1;
// }

// BETTER THAN BRUTE FORCE
// Time Complexity:- O(n*log n)+O(n)
// Space Complexity:- O(n)
// int MajorityElement(vector<int> arr) 
// {
//     int n=arr.size();
//     map<int, int> inMap;
//     for(int i=0; i<n; i++)
//     {
//         inMap[arr[i]]++;
//     }
//     for(auto i : inMap)
//     {
//         if(i.second>(n/2))
//         {
//             return i.first;
//         }
//     }
//     return -1;
// }

// MOORE'S ALGORITHM OPTIMIZED APPROACH
// Time Complexity:- O(n)
// Space Complexity:- O(1)
int MajorityElement(vector<int> arr)
{
    int num=arr[0], count=0;
    for(int i=0; i<arr.size(); i++)
    {
        if(arr[i]==num)
        {
            count++;
        }
        else if(arr[i]!=num)
        {
            count--;
        }
        if(count==0)
        {
            num=arr[i];
            count++;
        }
    }
    int count2=0;
    for(int i=0; i<arr.size(); i++)
    {
        if(arr[i]==num)
        {
            count2++;
        }
        if(count2>arr.size()/2)
        {
            return num;
        }
    }
    return -1;
}
int main()
{
    vector<int> arr = {2, 2, 1, 1, 1, 1, 1, 2};
    cout<<MajorityElement(arr);
    return 0;
}