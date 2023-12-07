#include<bits/stdc++.h>
using namespace std;
int AllocatePages(vector<int> &arr, int pages){
    int student=1, studentPages=0;
    for(int i=0; i<arr.size(); i++){
        if(studentPages+arr[i]<=pages){
            studentPages+=arr[i];
        }
        else{
            student++;
            studentPages=arr[i];
        }
    }
    return student;
}
// Time Complexity:- O(n)*O(high-low), where high is the sum of array elements
//                   and 'low' is the minimum element in an array
// Space Complexity:- O(1)
int MaximumPages(vector<int> &arr, int student){
    if(student>arr.size()){
        return -1;
    }
    int low=*max_element(arr.begin(), arr.end());
    int high=accumulate(arr.begin(), arr.end(), 0);
    for(int i=low; i<=high; i++){
        if(AllocatePages(arr, i)==student){
            return i;
        }
    }
    return low;
}

// Time Complexity:- O(n)*O(log(high-low)), where high is the sum of array elements
//                   and 'low' is the minimum element in an array
int MaximumPages(vector<int> &arr, int student){
    if(student>arr.size()){
        return -1;
    }
    int low=*max_element(arr.begin(), arr.end());
    int high=accumulate(arr.begin(), arr.end(), 0);
    while(low<=high){
        int mid=(low+high)/2;
        if(AllocatePages(arr, mid)>student){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return low;
}
int main(){
    vector<int> arr={25,46,28,49,24};
    int student=4;
    cout<<MaximumPages(arr, student);
    return 0;
}