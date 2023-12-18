#include<bits/stdc++.h>
using namespace std;
int MaximumElementIndex(vector<vector<int>> &arr, int n, int m, int col){
    int maxElement=-1, maxIndex=-1;
    for(int i=0; i<n; i++){
        if(arr[i][col]>maxElement){
            maxElement=arr[i][col];
            maxIndex=i;
        }
    }
    return maxIndex;
}
// Time Complexity:- O(nlogn)
// Space Complexity:- O(1)
vector<int> PeakIn2DArray(vector<vector<int>> &arr){
    int n=arr.size(), m=arr[0].size();
    int low=0, high=m-1;
    while(low<=high){
        int mid=(low+high)/2;
        int row=MaximumElementIndex(arr, n, m, mid);
        int left=mid-1>=0 ? arr[row][mid-1] : -1;
        int right=mid+1<m ? arr[row][mid+1] : -1;
        if(arr[row][mid]>left && arr[row][mid]>right){
            return {row,mid};
        }
        else if(arr[row][mid]>left){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return {-1, -1};
}
int main()
{
    vector<vector<int>> matrix={{4,2,5,1,4,5}, {2,9,3,2,3,2},{1,7,6,0,1,3}, {3,6,2,3,7,2}};
    vector<int> ans=PeakIn2DArray(matrix);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<"  ";
    }
    return 0;
}
