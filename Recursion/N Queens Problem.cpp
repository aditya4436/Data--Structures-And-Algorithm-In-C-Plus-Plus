#include<bits/stdc++.h>
using namespace std;
// Time Complexity:- O(n!*n),because we are trying out all the possible ways.
// Space Complexity:- O(n^2)
void solve(int col, vector<string> &board, vector<vector<string>> &ans, vector<int> &leftRow,
vector<int> &upperDiagonal, vector<int> &lowerDiagonal, int n){
    if(col==n){
        ans.push_back(board);
        return;
    }
    for(int row=0; row<n; row++){
        if(leftRow[row]==0 && lowerDiagonal[row+col]==0 && upperDiagonal[n-1+col-row]==0){
            board[row][col]='Q';
            leftRow[row]=1;
            lowerDiagonal[row+col]=1;
            upperDiagonal[n-1+col-row]=1;
            solve(col+1, board, ans, leftRow, upperDiagonal, lowerDiagonal, n);
            board[row][col]='.';
            leftRow[row]=0;
            lowerDiagonal[row+col]=0;
            upperDiagonal[n-1+col-row]=0;
        }
    }
}
vector<vector<string>> solveQueens(int n){
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n, '.');
    for(int i=0; i<n; i++){
        board[i]=s;
    }
    vector<int> leftRow(n, 0), upperDiagonal(2*n-1, 0), lowerDiagonal(2*n-1, 0);
    solve(0, board, ans, leftRow, upperDiagonal, lowerDiagonal, n);
    return ans;
}
int main(){
    int n=4;
    vector<vector<string>> ans=solveQueens(n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<ans[i][j]<<"  ";
        }
        cout<<endl;
    }
    return 0;
}
