#include<bits/stdc++.h>
using namespace std;
// Time Complexity:- O(n!*n), "n!" to generate all the possible permutations
//                   and "n" to traverse the array.
// Space Complexity:- O(n)+O(n), "n" for storing the generated permutation in "ds"
//                    and another "n" (freq) to mark the visited or pushed element of "nums"
void GeneratePermuatation(vector<int> &ds, vector<int> &nums, vector<vector<int>> &ans, int freq[]){
    if(ds.size()==nums.size()){
        ans.push_back(ds);
        return;
    }
    for(int i=0; i<nums.size(); i++){
        if(!freq[i]){
            ds.push_back(nums[i]);
            freq[i]=1;
            GeneratePermuatation(ds, nums, ans, freq);
            freq[i]=0;
            ds.pop_back();
        }
    }
}
vector<vector<int>> PrintPermutaions(vector<int> &nums){
    vector<vector<int>> ans;
    vector<int> ds;
    int freq[nums.size()];
    for(int i=0; i<nums.size(); i++){
        freq[i]=0;
    }
    GeneratePermuatation(ds, nums, ans, freq);
    return ans;
}
int main()
{
    vector<int> arr={1,2,3};
    vector<vector<int>> ans=PrintPermutaions(arr);
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<"  ";
        }
        cout<<endl;
    }
    return 0;
}
