#include<bits/stdc++.h>
using namespace std;
// Time Complexity:- O(2^n)*k, if the all the elments in an array are unique
//                   then it will generate 2^n subsequences and 'k' is the average
//                   size of every combination.
// Space Complexity:- O(k*x), where 'k' is the average size of every combination and
//                    'x' is the number of combination.
void FindCombination(int index, int target, vector<int> &candidates, vector<vector<int>> &ans, vector<int> &ds){
    if(index==candidates.size()){
        if(target==0){
            ans.push_back(ds);
        }
        return;
    }
    if(candidates[index]<=target){
        ds.push_back(candidates[index]);
        FindCombination(index, target-candidates[index], candidates, ans, ds);
        ds.pop_back();
    }
    FindCombination(index+1, target, candidates, ans, ds);
}
vector<vector<int>> CombinationSum(vector<int> &candidates, int target){
    vector<vector<int>> ans;
    vector<int> ds;
    FindCombination(0, target, candidates, ans, ds);
    return ans;
}
int main(){
    vector<int> arr={3,1,2};
    int target=5;
    vector<vector<int>> ans=CombinationSum(arr, target);
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<"  ";
        }
        cout<<endl;
    }
    return 0;
}
