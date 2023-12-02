#include<bits/stdc++.h>
using namespace std;
// Best And Average Case Time Complexity:- O(log n)
// Worst Case Time Complexity:- O(n/2)
// Space Complexity:- O(1)
bool SearchInSortedRotatedArray(vector<int> &arr, int target)
{
    int n=arr.size();
    int low=0, high=n-1, ans=-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(arr[mid]==target)
        {
            return true;
        }
        if(arr[low]==arr[mid] && arr[mid]==arr[high])
        {
            low=low+1;
            high=high-1;
            continue;
        }
        if(arr[low]<=arr[mid])
        {
            if(arr[low]<=target && target<=arr[mid])
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        else
        {
            if(arr[mid]<=target && target<=arr[high])
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
    }
    return false;
}
int main()
{
    vector<int> arr={1,0,1,1,1};
    int target=0;
    cout<<SearchInSortedRotatedArray(arr, target);
    return 0;
}