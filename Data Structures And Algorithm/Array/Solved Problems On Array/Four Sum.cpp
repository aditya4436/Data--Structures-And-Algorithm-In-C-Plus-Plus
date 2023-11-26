#include<bits/stdc++.h>
using namespace std;
// Time Complexity:- O(n^4)
// Space Complexity:- O(no. of quads)
// vector<vector<int>> FourSum(vector<int> &arr, int target)
// {
//     set<vector<int>> st;
//     int n=arr.size();
//     for(int i=0; i<n ;i++)
//     {
//         for(int j=i+1; j<n; j++)
//         {
//             for(int k=j+1; k<n; k++)
//             {
//                 for(int l=k+1; l<n; l++)
//                 {
//                     long long sum=arr[i]+arr[j];
//                     sum+=arr[k];
//                     sum+=arr[l];
//                     if(sum==target)
//                     {
//                         vector<int> temp={arr[i], arr[j], arr[k], arr[l]};
//                         sort(temp.begin(), temp.end());
//                         st.insert(temp);
//                     }
//                 }
//             }
//         }
//     }
//     vector<vector<int>> ans(st.begin(), st.end());
//     return ans;
// }

// BETTER THAN BRUTE FORCE
// Time Complexity:- O(n^3) * O(log (no. of elements in set.))
// Space Complexity:- O(n) + O(2 * no. quads)
// vector<vector<int>> FourSum(vector<int> &arr, int target)
// {
//     set<vector<int>> st;
//     int n=arr.size();
//     for(int i=0; i<n ;i++)
//     {
//         for(int j=i+1; j<n; j++)
//         {
//             set<long long> hashset;
//             for(int k=j+1; k<n; k++)
//             {
//                 // int sum=arr[i]+arr[j]+arr[k]
//                 long long fourth=target-(arr[i]+arr[j]+arr[k]);
//                 if(hashset.find(fourth)!=hashset.end())
//                 {
//                     vector<int> temp={arr[i], arr[j], arr[k], int(fourth)};
//                     sort(temp.begin(), temp.end());
//                     st.insert(temp);
//                 }
//                 hashset.insert(arr[k]);
//             }
//         }
//     }
//     vector<vector<int>> ans(st.begin(), st.end());
//     return ans;
// }

// OPTIMIZED APPROACH
// Time Complexity:- O(n^3).
// Space Complexity:- O(no. of quadruplets).
vector<vector<int>> FourSum(vector<int> &arr, int target)
{
    sort(arr.begin(), arr.end());
    int n=arr.size();
    vector<vector<int>> ans;
    for(int i=0; i<n; i++)
    {
        if(i>0 && arr[i]==arr[i-1])
        {
            continue;
        }
        for(int j=i+1; j<n; j++)
        {
            if(j!=i+1 && arr[j]==arr[j-1])
            {
                continue;
            }
            int k=j+1;
            int l=n-1;
            while(k<l)
            {
                long long sum=arr[i];
                sum+=arr[j];
                sum+=arr[k];
                sum+=arr[l];
                if(sum==target)
                {
                    vector<int> temp={arr[i], arr[j], arr[k], arr[l]};
                    ans.push_back(temp);
                    k++;
                    l--;
                    while(k<l && arr[k]==arr[k-1])
                    {
                        k++;
                    }
                    while(k<l && arr[l]==arr[l+1])
                    {
                        l--;
                    }
                }
                else if(sum<target)
                {
                    k++;
                }
                else
                {
                    l--;
                }
            }
        }
    }
    return ans;
}
int main()
{
    vector<int> arr={4,3,3,4,4,2,1,2,1,1};
    int target=9;
    vector<vector<int>> ans=FourSum(arr, target);
    for(auto it : ans)
    {
        cout<<"[";
        for(auto i : it)
        {
            cout<<i<<"  ";
        }
        cout<<"]";
    }
    return 0;
}