#include<bits/stdc++.h>
using namespace std;
int SearchInSortedRotatedArray(vector<int> &arr, int target)
{
    int n=arr.size();
    int low=0, high=n-1, minimum=INT_MAX;
    while(low<=high)
    {
        int mid=(low+high)/2;
        minimum=min(arr[mid], minimum);
        if(arr[low]<=arr[mid])
        {
            minimum=min(arr[low], minimum);
            low=mid+1;
        }
        else
        {
            minimum=min(arr[mid], minimum);
            high=mid-1;
        }
    }
    return minimum;
}
int main()
{
    vector<int> arr={35, 43, 45, 1, 2, 9, 12, 13, 19, 20, 26, 28, 29, 32};
    int target=0;
    cout<<SearchInSortedRotatedArray(arr, target);
    return 0;
}