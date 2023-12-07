#include<bits/stdc++.h>
using namespace std;
bool IsPossible(vector<int> &arr, int distance, int cows){
    int last=arr[0], countCows=1;
    for(int i=1; i<arr.size(); i++){
        if(arr[i]-last>=distance){
            countCows++;
            last=arr[i];
        }
        if(countCows>=cows){
            return true;
        }
    }
    return false;
}

// Time Complexity:- O(n log n)+O(maximum), where 'maximum' is the 
//                   maximum difference between the maximum element
//                   stall and minimum element of stall.
// Space Complexity:- O(1)
// int MaximumDistanceBetweenTwoCows(vector<int> &arr, int cows){
//     int n=arr.size();
//     sort(arr.begin(), arr.end());
//     int maximum=arr[n-1]-arr[0], result=-1;
//     for(int i=1; i<=maximum; i++){
//         bool ans=IsPossible(arr, i,cows);
//         if(ans==true){
//             result=max(result, i);
//         }
//     }
//     return result;
// }

// Time Complexity:- O(n log n)+O(log(high)), where 'high' is the 
//                   maximum difference between the maximum element
//                   stall and minimum element of stall.
// Space Complexity:- O(1)
int MaximumDistanceBetweenTwoCows(vector<int> &arr, int cows){
    sort(arr.begin(), arr.end());
    int n=arr.size();
    int low=0, high=arr[n-1]-arr[0];
    while(low<=high){
        int mid=(low+high)/2;
        bool possible=IsPossible(arr, mid, cows);
        if(possible==true){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return high;
}
int main(){
    vector<int> arr={0,3,4,7,10};
    int cows=4;
    cout<<MaximumDistanceBetweenTwoCows(arr, 4);
    return 0;
}
