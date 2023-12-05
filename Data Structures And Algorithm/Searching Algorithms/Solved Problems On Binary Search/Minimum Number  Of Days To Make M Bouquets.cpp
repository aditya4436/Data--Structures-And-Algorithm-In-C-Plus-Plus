#include<bits/stdc++.h>
using namespace std;
// Time Compelxity:- O(maximum-minimum), to find the day and O(n) to check if
//                   it possible or not to make 'm' bouquets/
// Space Complexity:- O(1)
bool IsPossible(vector<int> &arr, int day, int k, int m){
    int result=0, count=0;
    for(int i=0; i<arr.size(); i++){
        if(arr[i]<=day){
            count++;
        }
        else{
            result+=(count/m);
            count=0;
        }
    }
    result+=(count/m);
    if(result>=k){
        return true;
    }
    else{
        return false;
    }
}
// int RoseGarden(vector<int> &arr, int k, int m){
//     int minimum=INT_MAX, maximum=INT_MIN;
//     for(int i=0; i<arr.size(); i++){
//         minimum=min(minimum, arr[i]);
//         maximum=max(maximum, arr[i]);
//     }
//     for(int i=minimum; i<=maximum; i++){
//         if(IsPossible(arr, i, k, m)){
//             return i;
//         }
//     }
//     return -1;
// }

int Minimum(vector<int> &arr){
    int minimum=INT_MAX;
    for(int i=0; i<arr.size(); i++){
        minimum=min(arr[i], minimum);
    }
    return minimum;
}
int Maximum(vector<int> &arr){
    int maximum=INT_MIN;
    for(int i=0; i<arr.size(); i++){
        maximum=max(arr[i], maximum);
    }
    return maximum;
}

// Time Complexity:- O(log(maximum-minimum)), where 'maximum; is the maximum element
//                   of an array/
// Space Complexity:- O(1)
int RoseGarden(vector<int> &arr, int k, int m){
    int low=Minimum(arr), high=Maximum(arr), ans=-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(IsPossible(arr, mid, k, m)){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }   
    return ans;
}
int main(){
    vector<int> arr={7,7,7,7,13,11,12,7};
    int k=3, m=2;
    cout<<RoseGarden(arr, k, m);
    return 0;
}