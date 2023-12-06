#include<bits/stdc++.h>
using namespace std;
// BRUTE FORCE APPROACH
// Time Complexity:- O(n)
// Space Complexity:- O(1)
// int KthMissingNumber(vector<int> &arr, int k){
//     for(int i=0; i<arr.size(); i++){
//         if(arr[i]<=k){
//             k++;
//         }
//         else{
//             break;
//         }
//     }
//     return k;
// }


// OPTIMAL APPROACH
// Time Complexity:- O(log n)
// Space Complexity:- O(1) 
int KthMissingNumber(vector<int> &arr, int k){
    int low=0, high=arr.size()-1;
    while(low<=high){
        int mid=(low+high)/2;
        int missing=arr[mid]-(mid+1);
        if(missing<k){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return (high+k+1);
}
int main()
{
    vector<int> arr={4,7,9,10};
    int k=4;
    cout<<KthMissingNumber(arr, k);
    return 0;
}