#include<bits/stdc++.h>
using namespace std;
// Time Complexity: O(4^(m*n)), because on every cell we need to try 4 different directions.
// Space Complexity:  O(m*n), Maximum Depth of the recursion tree(auxiliary space).
void Solve(int i, int j, vector<vector<int>> &a, int n, vector<string> &ans, string move, vector<vector<int>> &vis, int di[], int dj[]){
    if(i==n-1 && j==n-1){
        ans.push_back(move);
        return;
    }
    string dir="DLRU";
    for(int ind=0; ind<4; ind++){
        int nexti=i+di[ind];
        int nextj=j+dj[ind];
        if(nexti>=0 && nextj>=0 && nexti<n && nextj<n && !vis[nexti][nextj] && a[nexti][nextj]==1){
            vis[i][j]=1;
            Solve(nexti, nextj, a, n, ans, move+dir[ind], vis, di, dj);
            vis[i][j]=0;
        }
    }
}
vector<string> FindPath(vector<vector<int>> &a, int n){
    vector<string> ans;
    vector<vector<int>> vis(n, vector<int>(n, 0));
    int di[]={+1, 0, 0, -1};
    int dj[]={0, -1, 1, 0};
    if(a[0][0]==1){
        Solve(0, 0, a, n, ans, "", vis, di, dj);
    }
    return ans;
}
int main() {
    int n=4;
    vector<vector<int>> m={{1,0,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};
    vector<string> ans=FindPath(m, 4);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<"  ";
    }
    return 0;
}
