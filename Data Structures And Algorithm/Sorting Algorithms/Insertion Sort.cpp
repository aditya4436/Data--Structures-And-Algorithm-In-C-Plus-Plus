#include<bits/stdc++.h>
using namespace std;

// Time Complexity:- O(n^2)
// Space Complexity:- O(1)
void InsertionSort(int arr[], int n){
    for(int i=1; i<n; i++){
        int key=arr[i];
        int j=i-1;

        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

void print(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<"  ";
    }
}

int main(){
    int arr[]={8,9,2,5,4,7,1,10};
    int n=sizeof(arr)/sizeof(arr[0]);

    InsertionSort(arr, n);
    print(arr, n);
    return 0;
}
