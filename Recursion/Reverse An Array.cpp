#include<bits/stdc++.h>
using namespace std;
// Time Complexity:- O(n)
// Space Complexity:- O(n), this space is used internally by the computer
//                    to store the output of previously generated result
//                    untill the base condition is not satisfied.   
void ReverseArray(int arr[], int n){
    if(n==0){
        return;
    }
    cout<<arr[n-1]<<" ";
    ReverseArray(arr, n-1);
}

// void ReverseArray(int arr[], int l, int r){
//     if(l>=r){
//         return;
//     }
//     swap(arr[l], arr[r]);
//     ReverseArray(arr, l+1, r-1);
// }

// void ReverseArray(int arr[], int n, int i){
//     if(i>=n/2){
//         return;
//     }
//     swap(arr[i], arr[n-i-1]);
//     ReverseArray(arr, n, i+1);
// }
void PrintArray(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<"  ";
    }
}
int main(){
    int arr[]={1,2,3,4,5};
    int n=5, i=0;
    int l=0, r=n-1;
    // ReverseArray(arr, n, i);
    // ReverseArray(arr, l, r);
    ReverseArray(arr, n);
    // PrintArray(arr, n);
    return 0;
}
