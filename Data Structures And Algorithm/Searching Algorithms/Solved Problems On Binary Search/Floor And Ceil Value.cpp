#include<bits/stdc++.h>
using namespace std;
// Time Complexity:- O(log n)
// Space Complexity:- O(1)
int FindFloor(vector<int> &arr, int target)
{
    int n=arr.size();
    int ans=-1;
    int low=0, high=n-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(arr[mid]<=target)
        {
            ans=arr[mid];
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    return ans;
}
int FindCeil(vector<int> &arr, int target)
{
    int n=arr.size();
    int ans=-1;
    int low=0, high=n-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(arr[mid]>=target)
        {
            ans=arr[mid];
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    return ans;
}
pair<int, int> GetFloorAndCeil(vector<int> &arr, int n, int x)
{
    int f=FindFloor(arr, x);
    int c=FindCeil(arr, x);
    return make_pair(f, c);
}
int main()
{
    vector<int> arr={3,4,4,7,8,9};
    int n=arr.size();
    int x=5;
    pair<int, int> ans=GetFloorAndCeil(arr, n, x);
    cout<<ans.first<<"  "<<ans.second;
    return 0;
}