#include<bits/stdc++.h>
using namespace std;
// Time Complexity:- O(n*m)
// Space Complexity:- O(1)
// int MaximumOnesIndex(vector<vector<int>> &arr, int n, int m){
//     int index=-1, maximumCount=-1;
//     for(int i=0; i<n; i++){
//         int countOnes=0;
//         for(int j=0; j<m; j++){
//             countOnes+=arr[i][j];
//         }
//         if(maximumCount<countOnes){
//             maximumCount=countOnes;
//             index=i;
//         }
//     }
//     return index;
// }

// Time Complexity:- O(nlogm), 'n' number of rows and 'm'
//                   number columns.
// Space Complexity:- O(1)
int LowerBound(vector<int> &arr, int n, int k){
    int low=0, high=n-1;
    int ans=n;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]>=k){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}
int MaximumOnesIndex(vector<vector<int>> &arr, int n, int m){
    int index=-1, maximumCount=0;
    for(int i=0; i<n; i++){
        int countOnes=0;
        countOnes=m-LowerBound(arr[i], m, 1);
        if(maximumCount<countOnes){
            maximumCount=countOnes;
            index=i;
        }
    }
    return index;
}
int main()
{
    vector<vector<int>> arr={{0,0,0}, {0,0,1}, {0,0,0}};
    int n=3,m=3;
    cout<<MaximumOnesIndex(arr, n, m);
    return 0;
}
