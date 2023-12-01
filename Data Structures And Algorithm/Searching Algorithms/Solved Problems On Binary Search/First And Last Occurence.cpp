#include<bits/stdc++.h>
using namespace std;
// BRUTE FORCE APPROACH
// Time Complexity:- O(n)
// Space Complexity:- O(1)
// vector<int> FirstAndLastOcuurence(vector<int> &arr, int x)
// {
//     int first=-1, last=-1;
//     for (int i=0; i<arr.size(); i++)
//     {
//         if(arr[i]==x && first==-1)
//         {
//             first=i;
//         }
//         else if(arr[i]==x)
//         {
//             last=i;
//         }
//         else if(last==-1)
//         {
//             last=first;
//         }
//     }
//     return {first, last};
// }

int LowerBound(vector<int> &arr, int target)
{
    int low=0, high=arr.size()-1;
    int ans=-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(arr[mid]>=target)
        {
            ans=mid;
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    return ans;
}
int UpperBound(vector<int> &arr, int target)
{
    int low=0, high=arr.size()-1;
    int ans=-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(arr[mid]>target)
        {
            ans=mid;
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    return ans;
}
pair<int,int> FirstAndLastOccurence(vector<int> &arr, int target)
{
    int first=LowerBound(arr, target);
    if(first==arr.size() || arr[first]!=target)
    {
        return{-1, -1};
    }
    int last=UpperBound(arr, target);
    return{first, last-1};
}
int main()
{
    vector<int> arr={1,3,3,5};
    pair<int, int> ans=FirstAndLastOccurence(arr, 3);
    cout<<ans.first<<"  "<<ans.second;
    return 0;
}