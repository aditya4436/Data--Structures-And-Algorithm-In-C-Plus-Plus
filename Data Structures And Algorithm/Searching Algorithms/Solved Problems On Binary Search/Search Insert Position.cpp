#include<bits/stdc++.h>
using namespace std;
// Time Complexity:- O(log n)
// Space Complexity:- O(1)
int LowerBound(vector<int> &arr, int target)
{
    int ans=arr.size();
    int low=0, high=ans-1;
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
int main()
{
    vector<int> arr={1,3,7,9,11,12,45};
    int target=13;
    cout<<LowerBound(arr, target);
    return 0;
}