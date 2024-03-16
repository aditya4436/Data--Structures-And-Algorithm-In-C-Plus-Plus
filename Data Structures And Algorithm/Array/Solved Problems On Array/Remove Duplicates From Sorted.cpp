#include<bits/stdc++.h>
using namespace std;

// Time Complexity:- O(n)
// Space Complexity:- O(1)
int RemoveDuplicates(vector<int> &nums){
    int n=nums.size();
    int count=1, j=1;
    for(int i=1; i<n; i++){
        if(nums[i]==nums[i-1]){
            count++;
        }

        else{
            count=1;
        }

        if(count<=2){
            nums[j++]=nums[i];
        }
    }
    return j;
}

int main(){
    vector<int> nums={0,0,1,1,1,1,2,3,3};

    int size=RemoveDuplicates(nums);
    cout<<"The number of unique elements that occurs atmost 2 times:\n"<<size<<endl;

    cout<<"Updated vector is:\n";
    for(int i=0; i<nums.size(); i++){
        cout<<nums[i]<<"  ";
    }
    
    return 0;
}
