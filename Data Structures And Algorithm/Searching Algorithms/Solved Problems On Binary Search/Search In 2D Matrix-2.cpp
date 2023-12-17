#include<bits/stdc++.h>
using namespace std;
// Time Complexity:- O(n+m)
// Space Complexity:- O(1)
bool SearchIn2DMatrix2(vector<vector<int>>& matrix, int target) {
    int n=matrix.size(), m=matrix[0].size();
    int row=0, col=m-1;
    while(row<n && col>=0){
        if(matrix[row][col]==target){
            return true;
        }
        else if(matrix[row][col]>target){
            col--;
        }
        else{
            row++;
        }
    }
    return false;
}
int main(){
    vector<vector<int>> arr={{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    int k=17;
    SearchIn2DMatrix2(arr, k)==true?cout<<"true":cout<<"false";
    return 0;
}
