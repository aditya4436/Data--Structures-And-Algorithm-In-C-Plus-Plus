#include<bits/stdc++.h>
using namespace std;
// BRUTE FORCE APPROACH
// Time Complexity:- O(nlogn)
// Space Complexity:- The sorting operation usually requires additional space. 
//                    The standard sort operation typically has an average space
//                    complexity of O(log n). Apart from the sorting operation, 
//                    the algorithm uses only a constant amount of additional space
//                    for variables like n and i.
// int FirstMissingNumber(vector<int> &nums){
//     int n=nums.size();
//     sort(nums.begin(), nums.end());
//     if(nums[0]>1){
//         return 1;
//     }
//     for(int i=0; i<n; i++){
//         if(nums[i+1]!=nums[i]+1){
//             if(nums[i]+1==0){
//                 continue;
//             }

//             else{
//                 return (nums[i]+1);
//             }
//         }
//     }
//     return -1;
// }


// BETTER THAN BRUTE FORCE
// Time Complexity:- O(n)
// Space Complexity:- O(m)
// int FirstMissingNumber(vector<int> &nums){
//     int n=nums.size();
//     int minVal=nums[0], maxVal=nums[0];
//     for(int i=1; i<n; i++){
//         minVal=min(minVal, nums[i]);
//         maxVal=max(maxVal, nums[i]);
//     }
//     if(minVal>1){
//         return 1;
//     }

//     int m=maxVal-minVal+1;

//     vector<int> harr(m, 0);
//     for(int i=0; i<n; i++){
//         harr[nums[i]-minVal]=1;
//     }

//     for(int i=minVal; i<=maxVal; i++){
//         if(i<=0){
//             continue;
//         }
//         if(harr[i-minVal]==0){
//             return i;
//         }
//     }

//     return -1;
// }


// Time Complexity:- O(n^2) in worst case
// Space Complexity:- O(1)
// int FirstMissingNumber(vector<int> &nums){
//     int n=nums.size();
//     int smallest=INT_MAX;

//     for(int i=0; i<n; i++){
//         if(nums[i]>0 && nums[i]<smallest){
//             smallest=nums[i];
//         }
//     }

//     if(smallest>1 || smallest<0){
//         return 1;
//     }

//     int i=0;
//     while(i<n){
//         if(smallest+1==nums[i]){
//             smallest=smallest+1;
//             i=0;
//         }
        
//         else{
//             i++;
//         }
//     }
//     return smallest+1;
// }

int FirstMissingNumber(vector<int>& nums) {
    int n = nums.size();

    // First pass: Move each positive integer to its correct index
    for (int i = 0; i < n; ++i) {
        while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
            std::swap(nums[i], nums[nums[i] - 1]);
        }
    }

    // Second pass: Find the first index where the element is not equal to its index + 1
    for (int i = 0; i < n; ++i) {

        if (nums[i] != i + 1) {
            cout<<i+1<<endl;
            return i + 1;
        }
    }

    // All positive integers from 1 to n are present, return n + 1
    return n + 1;
}

int main(){
    // vector<int> arr={7,8,9,11,12};
    // vector<int> arr={3,4,-1,1};
    vector<int> arr={2, 3, 7, 6, 8, -1, -10, 15};
    // vector<int> arr={1,2,0};
    // vector<int> arr={-1, 0, 1, 3, 4, 5};
    cout<<FirstMissingNumber(arr);
    return 0;
}
