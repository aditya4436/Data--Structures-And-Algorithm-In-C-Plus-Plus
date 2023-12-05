#include<bits/stdc++.h>
using namespace std;
// Time Complexity:- O(log n)
// Space Complexity:- O(1)
int SquareRoot(vector<int> &arr, int n){
    int size=arr.size(),ans=-1;
    int low=0, high=size-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]*arr[mid]<=n){
            ans=arr[mid];
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return ans;
}
int main()
{
    vector<int> arr={2,4,6,8,10};
    cout<<SquareRoot(arr, 64);
    return 0;
}