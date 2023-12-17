#include<bits/stdc++.h>
using namespace std;
// Time Complexity:- O(n*m)
// Space Complexity:- O(1)
// bool SearchIn2DMatrix(vector<vector<int>> &arr, int k){
//     int n=arr.size(), m=arr[0].size();
//     for(int i=0; i<n; i++){
//         for(int j=0; j<m; j++){
//             if(arr[i][j]==k){
//                 return true;           
//             }
//         }
//     }
//     return false;
// }

// Time Complexity:- O(nlogm)
// Space Complexity:-O(1)
// bool BinarySearch(vector<int> &arr, int k){
//     int m=arr.size();
//     int low=0, high=m-1;
//     while(low<=high){
//         int mid=(low+high)/2;
//         if(arr[mid]==k){
//             return true;
//         }
//         else if(k>arr[mid]){
//             low=mid+1;
//         }
//         else{
//             high=mid-1;
//         }
//     }
//     return false;
// }
// bool SearchIn2DMatrix(vector<vector<int>> &arr, int k){
//     int n=arr.size();
//     int m=arr[0].size();
//     for(int i=0; i<n; i++){
//         if(arr[i][0]<=k && k<=arr[i][m-1]){
//             return BinarySearch(arr[i], k);
//         }
//     }
//     return false;
// }

// Time Complexity:- O(log(n*m))
// Space Complexity:- O(1)
bool SearchIn2DMatrix(vector<vector<int>> &arr, int k){
    int n=arr.size(), m=arr[0].size();
    int low=0, high=(n*m-1);
    while(low<=high){
        int mid=(low+high)/2;
        int row=mid/m, col=mid%m;
        if(arr[row][col]==k){
            return true;
        }
        else if(k>arr[row][col]){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return false;
}
int main(){
    vector<vector<int>> arr={{1,3,4}, {5,6,7}, {8,9,10}};
    int k=5;
    SearchIn2DMatrix(arr, k)==true?cout<<"true":cout<<"false";
    return 0;
}
