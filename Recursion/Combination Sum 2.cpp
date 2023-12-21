#include<bits/stdc++.h>
using namespace std;
// Time Complexity:- O(2^n)*k, if the all the elments in an array are unique
//                   then it will generate 2^n subsequences and 'k' is the average
//                   size of every combination.
// Space Complexity:- O(k*x), where 'k' is the average size of every combination and
//                    'x' is the number of combination.
void FindCombination(int index, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds){
    if(target==0){
        ans.push_back(ds);
        return;
    }
    for(int i=index; i<arr.size(); i++){
        if(i>index && arr[i]==arr[i-1]){
            continue;
        }
        if(arr[i]>target){
            break;
        }
        ds.push_back(arr[i]);
        FindCombination(i+1, target-arr[i], arr, ans, ds);
        ds.pop_back();
    }
}
vector<vector<int>> CombinationSum(vector<int> &arr, int target){
    vector<vector<int>> ans;
    vector<int> ds;
    sort(arr.begin(), arr.end());
    FindCombination(0, target, arr, ans, ds);
    return ans;
}
int main(){
    vector<int> arr={10,1,2,7,6,1,5};
    int target=8;
    vector<vector<int>> ans=CombinationSum(arr, target);
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<"  ";
        }
        cout<<endl;
    }
    return 0;
}
