#include<bits/stdc++.h>
using namespace std;
// Time Complexity:- O(n*m)+O((n*m)log(n*m))
// Space Complexity:- O(n*m)
// int MedianOf2DArray(vector<vector<int>> arr){
//     vector<int> temp;
//     int n=arr.size(), m=arr[0].size();
//     for(int i=0; i<n; i++){
//         for(int j=0; j<m; j++){
//             temp.push_back(arr[i][j]);
//         }
//     }
//     sort(temp.begin(), temp.end());
//     return temp[((n*m)/2)];
// }

int UpperBound(vector<int> arr, int x, int m){
    int low=0, high=m-1, ans=m;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]>x){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}
int CountSmallEquals(vector<vector<int>> &arr, int n, int m, int x){
    int count=0;
    for(int i=0; i<n; i++){
        count+=UpperBound(arr[i], x, m);
    }
    return count;
}

// Time Complexity:- O(log(10^9)*n*logm), O(log(10^9)) is for the binary search
//                   O(n) to count the number of elements and O(logm) to find the
//                   max element int the row.
// Space Complexity:- O(1)
int MedianOf2DArray(vector<vector<int>> &arr){
    int n=arr.size(), m=arr[0].size();
    int low=1, high=1e9;
    int req=(n*m)/2;
    while(low<=high){
        int mid=(low+high)/2;
        int countSmall=CountSmallEquals(arr, n, m, mid);
        if(countSmall<=req){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return low;
}
int main(){
    vector<vector<int>> arr={{1,3,5}, {2,6,9}, {3,6,9}};
    cout<<MedianOf2DArray(arr);
    return 0;
}
