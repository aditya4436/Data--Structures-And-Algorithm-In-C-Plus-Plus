#include<bits/stdc++.h>
using namespace std;
// Time Complexity:- O(2^n*K), '2^n' is for the recursive calls 
//                   and 'k' is the assumed to be the average size
//                   of the subsets.
// Space Complexity:- O(2^n)
void GenerateSubsets(int index, vector<int> &arr, vector<int> &ds, vector<vector<int>> &ans, int n){
    ans.push_back(ds);
    for(int i=index; i<n; i++){
        if(i!=index && arr[i]==arr[i-1]){
            continue;
        }
        ds.push_back(arr[i]);
        GenerateSubsets(i+1, arr, ds, ans, n);
        ds.pop_back();
    }
}
vector<vector<int>> PrintSubsets(vector<int> &arr, int n){
    n=arr.size();
    vector<int> ds;
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    GenerateSubsets(0, arr, ds, ans, n);
    return ans;
}
int main(){
    vector<int> arr={3,1,2};
    int n;
    vector<vector<int>> ans=PrintSubsets(arr, n);
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<"  ";
        }
        cout<<endl;
    }
    return 0;
}
