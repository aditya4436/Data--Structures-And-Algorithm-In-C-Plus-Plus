#include<bits/stdc++.h>
using namespace std;
// Time Complexity:- O(n)
// Space Complexity:- O(1)
// int FindSingle(vector<int> &arr)
// {
//     int n=arr.size();
//     if(n==1)
//     {
//         return arr[0];
//     }
//     for(int i=0; i<n; i++)
//     {
//         if(arr[i]!=arr[i+1] && arr[i]!=arr[i-1])
//         {
//             return arr[i];
//         }
//         if(i==0 && arr[i]!=arr[i+1])
//         {
//             return arr[i];
//         }
//         if(i==n-1 && arr[i]!=arr[i-1])
//         {
//             return arr[i];
//         }
//     }
//     return -1;
// }

// Time Complexity:- O(n)
// Space Complexity:- O(1)
int FindSingle(vector<int> &arr)
{
    int low=1, high=arr.size()-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(arr[mid-1]!=arr[mid] && arr[mid+1]!=arr[mid])
        {
            return arr[mid];
        }
        if((mid%2)==0 &&  arr[mid+1]!=arr[mid] || (mid%2)==1 && arr[mid-1])
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    return -1;
}
int main()
{
    vector<int> arr={1,1,2,2,3,4,4,5,5};
    cout<<FindSingle(arr);
    return 0;
}