#include<bits/stdc++.h>
using namespace std;

// Time Complexity:- O(n^2)
// Space Complexity:- O(1)
void BubbleSort(int arr[], int n){
    for(int i=0; i<n-1; i++){

        // The condition is in the loop is n-i-1,
        // because after every pass the largest 
        // element goes to its correct position
        // and hence we don't need to perforn sorting
        // on the last element.
        for(int j=0; j<n-i-1; j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

// Time Complexity:- O(n^2)
// Space Complexity:- O(n), because of recursion stack space.
void RecursiveBubbleSort(int arr[], int n){
    if(n==1){
        return;
    }

    // The condition is in the loop is n-1,
    // because after every pass the largest 
    // element goes to its correct position
    // and hence we don't need to perforn sorting
    // on the last element.
    for(int i=0; i<n-1; i++){
        if(arr[i]>arr[i+1]){
            swap(arr[i], arr[i+1]);
        }
    }
    RecursiveBubbleSort(arr, n-1);
}

void print(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<"  ";
    }
}
int main(){
    int arr[]={8, 9, 2, 5, 4, 7, 1, 10};
    int n=sizeof(arr)/sizeof(arr[0]);

    BubbleSort(arr, n);
    print(arr, n);

    cout<<endl;

    RecursiveBubbleSort(arr, n);
    print(arr, n);

    return 0;
}
