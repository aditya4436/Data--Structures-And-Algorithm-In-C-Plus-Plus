#include<bits/stdc++.h>
using namespace std;
// Time Complexity:- O(2^n)+O((2^n)log(2^n))
// Space Complexity:- O(2^n)
void Sum(int index, vector<int> &arr, int sum, vector<int> &ans){
    if(index==arr.size()){
        ans.push_back(sum);
        return;
    }
    Sum(index+1, arr, sum+arr[index], ans);
    Sum(index+1, arr, sum, ans);
}
vector<int> SubsetSum(vector<int> &num){
	vector<int> ans;
	int sum=0;
	Sum(0, num, sum, ans);
	sort(ans.begin(), ans.end());
	return ans;	
}
int main(){
    vector<int> arr={3,1,2};
    int sum=0;
    vector<int> ans=SubsetSum(arr);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<"  ";
    }
    return 0;
}
