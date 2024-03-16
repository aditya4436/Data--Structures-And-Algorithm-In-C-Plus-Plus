#include<bits/stdc++.h>
using namespace std;
// Time Complexty:- O(n log n)
// Auxiliary Space Complexity:- O(log n)

// int SingleElement(vector<int> &nums){
//     sort(nums.begin(), nums.end());
//     int n=nums.size();

//     if(n==1 || nums[0]!=nums[1]){
//         return nums[0];
//     }

//     if(nums[n-1]!=nums[n-2]){
//         return nums[n-1];
//     }

//     for(int i=1; i<n-1; i++){
//         if(nums[i]==nums[i-1] || nums[i]==nums[i+1]){
//             continue;
//         }
//         else{
//             return nums[i];
//         }
//     }
//     return -1;
// }

// Time Complexity:- O(n)
// Space Complexity:- O(n)
int SingleElement(vector<int> &nums){
    int n=nums.size();
    unordered_map<int, int> inMap;
    
    for(int i=0; i<n; i++){
        inMap[nums[i]]++;
    }

    for(auto it : inMap){
        if(it.second==1){
            return it.first;
        }
    }
    return -1;
}

int main(){
    // vector<int> nums={0,1,0,1,0,1,99};
    // vector<int> nums={1, 1, 2, 2, 3};
    // vector<int> nums={4, 4, 5, 5, 6, 6, 7};
    // vector<int> nums={2, 2, 3, 3, 4, 4, 5}; 
    // vector<int> nums={1, 1, 2, 2, 3, 4, 4};
    // vector<int> nums={-1, -1, 0, 0, 1};
    vector<int> nums={1, 1, 2, 2, 3, 3};
    cout<<SingleElement(nums);
    return 0;
}
