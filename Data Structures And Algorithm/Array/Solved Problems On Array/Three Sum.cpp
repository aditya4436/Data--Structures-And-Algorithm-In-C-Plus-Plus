#include<bits/stdc++.h>
using namespace std;
// Time Complexity:- O(n^3)
// Space Complexity:- O(2 * no. of triplets), because we are using set
//                    data structure and a list to store the triple
// vector<vector<int>> ThreeSum(vector<int> &arr, int target)
// {
//     set<vector<int>>st;
//     for(int i=0; i<arr.size(); i++)
//     {
//         for(int j=i+1; j<arr.size(); j++)
//         {
//             for(int k=j+1; k<arr.size(); k++)
//             {
//                 if(arr[i]+arr[j]+arr[k]==target)
//                 {
//                     vector<int> temp={arr[i], arr[j], arr[k]};
//                     sort(temp.begin(), temp.end());
//                     st.insert(temp);
//                 }
//             }
//         }
//     }
//     vector<vector<int>> ans(st.begin(), st.end());
//     return ans;
// }

// 
// Time Complexity:- O(n^2 * log (no. of unique triplets)), because we are using 2 nested loops.
//                   And inserting the triplets into the set takes O(log (no. of unique triplets)).
//                   Here we have not considered the time complexity of sorting as we are just sorting
//                   3 elements everytime.
// Space Complexity:- O(n)+O(2* no. of unique triplets), as we are using a set data structure and a list
//                    to store the triplets and extra O(n) for storing the array elements in another set.
// vector<vector<int>> ThreeSum(vector<int> &arr, int target)
// {
//     set<vector<int>> st;
//     for(int i=0; i<arr.size(); i++)
//     {
//         set<int> hashset;
//         for(int j=i+1; j<arr.size(); j++)
//         {
//             int third=-(arr[i]+arr[j]);
//             if(hashset.find(third)!=hashset.end())
//             {
//                 vector<int> temp={arr[i], arr[j], third};
//                 sort(temp.begin(), temp.end());
//                 st.insert(temp);
//             }
//             hashset.insert(arr[j]);
//         }
//     }
//     vector<vector<int>> ans(st.begin(), st.end());
//     return ans;
// }

// Time Complexity:- O(n*log n) + O(n^2)
// Space Complexiyt:- O(no. of unique elements)
vector<vector<int>> ThreeSum(vector<int> &arr)
{
    int n=arr.size();
    int i=0, j=1;
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    for(int i=0; i<n; i++)
    {
        if(i>0 && arr[i]==arr[i-1])
        {
            continue;
        }
        int j=i+1;
        int k=n-1;
        while(j<k)
        {
            int sum=arr[i]+arr[j]+arr[k];
            if(sum>0)
            {
                k--;
            }
            else if(sum<0)
            {
                j++;
            }
            else
            {
                vector<int> temp={arr[i], arr[j], arr[k]};
                ans.push_back(temp);
                j++;
                k--;
                while(j<k && arr[j]==arr[j-1])
                {
                    j++;
                }
                while(j<k && arr[k]==arr[k+1])
                {
                    k--;
                }
            }
        }
    }
    return ans;
}
int main()
{
    vector<int> arr={-1,0,1,2,-1,-4};
    int target=0;
    vector<vector<int>> ans=ThreeSum(arr, target);
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