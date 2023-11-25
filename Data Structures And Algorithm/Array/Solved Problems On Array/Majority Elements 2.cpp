#include<bits/stdc++.h>
using namespace std;
// BRUTE FORCE APPROACH
// Time Complexity:- O(n^2)
// Space Complexity:- O(1), since we are using list of size 2 
//                    Since the space used is very small, therefore
//                    we can consider it constant.
// vector<int> MajorityElement(vector<int> &arr)
// {
//     vector<int> ans;
//     int n=arr.size();
//     int count=0;
//     for(int i=0; i<n; i++)
//     {
//         if(ans.size()==0 || ans[0]!=arr[i])
//         {
//             count=0;
//             for(int j=0; j<n; j++)
//             {
//                 if(arr[j]==arr[i])
//                 {
//                     count++;
//                 }
//             }
//             if(count>n/3)
//             {
//                 ans.push_back(arr[i]);
//             }
//         }
//         if(ans.size()==2)
//         {
//             break;
//         }
//     }
//     return ans;
// }

// USING HASH ARRAY
// Time Complexity:- O(2n+m)
// Space Complexity:- O(1)+O(m), since we are using list of size 2 
//                    Since the space used is very small, therefore
//                    we can consider it constant. We are using an
//                    hash array of O(m). Therefore overall space 
//                    complexity is O(m)+O(1). O(1) can be it can be
//                    ignored. Therefore time complexity becomes O(m)
// vector<int> MajorityElement(vector<int> &arr)
// {
//     int n=arr.size();
//     vector<int> ans;
//     int m=INT_MIN;
//     for(int i=0; i<n; i++)
//     {
//         m=max(m, arr[i]);
//     }
//     vector<int> harr(m, 0);
//     for(int i=0; i<n; i++)
//     {
//         harr[arr[i]]++;
//     }
//     for(int i=1; i<=m; i++)
//     {
//         if(harr[i]>n/3)
//         {
//             ans.push_back(i);
//         }
//     }
//     return ans;
// }

// USING HASH MAP
// Time Complexity:- O(2n*log n)
// Space Complexity:- O(n), since we are using list of size 2 
//                    Since the space used is very small, therefore
//                    we can consider it constant.
// vector<int> MajorityElement(vector<int> &arr)
// {
//     int n=arr.size();
//     vector<int> ans;
//     map<int, int> mpp;
//     for(int i=0; i<n; i++)
//     {
//         mpp[arr[i]]++;
//     }
//     for(auto i : mpp)
//     {
//        if(i.second>n/3)
//        {
//             ans.push_back(i.first);
//        }
//     }
//     return ans;
// }

// FURTHER OPTIMIZATION OF HASHMAP.
// Time Complexity:- O(n*logn)
// Space Complexity:- O(n), since we are using list of size 2 
//                    Since the space used is very small, therefore
//                    we can consider it constant.
// vector<int> MajorityElement(vector<int> &arr)
// {
//     int n=arr.size();
//     vector<int> ans;
//     map<int, int> mpp;
//     for(int i=0; i<n; i++)
//     {
//         mpp[arr[i]]++;
//         if(mpp[arr[i]]>n/3)
//         {
//             ans.push_back(arr[i]);
//         }
//     }
//     return ans;
// }

// OPTIMIZED APPROACH
// Time Complexity:- O(2n)
// Space Complexity:- O(1), since we are using list of size 2 
//                    Since the space used is very small, therefore
//                    we can consider it constant.
vector<int> MajorityElement(vector<int> &arr)
{
    int count1=0, count2=0, element1=INT_MIN, element2=INT_MIN;
    vector<int> ans;
    for(int i=0; i<arr.size(); i++)
    {
        if(count1==0 && element2!=arr[i])
        {
            count1=1;
            element1=arr[i];
        }
        else if(count2==0 && element1!=arr[i])
        {
            count2=1;
            element2=arr[i];
        }
        else if(element1==arr[i])
        {
            count1++;
        }
        else if(element2==arr[i])
        {
            count2++;
        }
        else
        {
            count1--;
            count2--;
        }
    }
    count1=0, count2=0;
    for(int i=0; i<arr.size(); i++)
    {
        if(element1==arr[i])
        {
            count1++;
        }
        if(element2==arr[i])
        {
            count2++;
        }
    }
    if(count1>(arr.size()/3))
    {
        ans.push_back(element1);
    }
    if(count2>(arr.size()/3))
    {
        ans.push_back(element2);
    }
    return ans;
}
int main()
{
    vector<int> arr={1,1,1,3,3,2,2,2};
    vector<int> ans=MajorityElement(arr);
    for(int i=0; i<ans.size(); i++)
    {
        cout<<ans[i]<<"  ";
    }
    return 0;
}