#include<bits/stdc++.h>
using namespace std;
// Time Complexity:- O(n), to calculate the time taken to eat
//                   banana and O(log maximum), where maximum
//                   is the maximum element in an array.
// Space Complexity:- O(1)
int TimeTaken(vector<int> &arr, int index){
    int time=0;
    for(int i=0; i<arr.size(); i++){
        time+=ceil((double)(arr[i])/(double)(index));
    }
    return time;
}
int Maximum(vector<int> &arr){
    int maximum=INT_MIN;
    for(int i=0; i<arr.size(); i++){
        maximum=max(arr[i], maximum);
    }
    return maximum;
}
int MinimumEatingSpeed(vector<int> &arr, int hour) {
    int low=1, high=Maximum(arr), ans=-1;
    while(low<=high){
        int mid=(low+high)/2;
        int req_time=TimeTaken(arr, mid);
        if(req_time<=hour){
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
    vector<int> arr={7,15,6,3};
    int hour=8;
    cout<<MinimumEatingSpeed(arr, 8);
    return 0;
}