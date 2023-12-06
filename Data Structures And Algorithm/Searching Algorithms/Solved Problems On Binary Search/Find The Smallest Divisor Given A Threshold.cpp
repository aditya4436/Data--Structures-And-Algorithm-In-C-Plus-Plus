#include<bits/stdc++.h>
using namespace std;
int Divide(vector<int> &arr, int threshold){
    int ans=0;
    for(int i=0; i<arr.size(); i++){
        ans+=ceil((double)(arr[i])/(double)(threshold));
    }
    return ans;
}

// Time Complexity: -O(maximum*n), where 'maximum' is the maximum element
//                  in an array and 'n' is the number of number of element.
// SpaceComplexity:- O(1)
// int SmallestDivisor(vector<int> &arr, int threshold){
//     int maximum=INT_MIN, result=0;
//     for(int i=0; i<arr.size(); i++){
//         maximum=max(arr[i], maximum);
//     }
//     for(int i=1; i<=maximum; i++){
//         result=Divide(arr, i);
//         if(result<=threshold){
//             return i;
//         }
//     }
//     return-1;
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

// Time Compelxity:- O(log (maximum)*n), where 'maximum' is the maximum element
//                  in an array and 'n' is the number of number of element.
// Space Complexity:- O(1)
int SmallestDivisor(vector<int> &arr, int threshold){
    int low=Minimum(arr), high=Maximum(arr), ans=-1;    
    while(low<=high){
        int mid=(low+high)/2;
        int result=Divide(arr, mid);
        if(result<=threshold){
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
    vector<int> arr={1,2,5,9};
    int threshold=6;
    cout<<SmallestDivisor(arr, threshold);
    return 0;
}