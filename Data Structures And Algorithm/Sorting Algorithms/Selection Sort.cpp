#include<bits/stdc++.h>
using namespace std;
// Time Complexity:- O(n^2)
// Space Complexity:- O(1)
int Minimum(int arr[], int i, int n){
    int smallest=arr[i], pos=i;

    for (int j=i+1; j<n-1; j++) {
        if (arr[j]<smallest) {
            smallest=arr[j];
            pos=j;
        }
    }
    return pos;
}

void SelectionSort(int arr[], int n){
    for(int i=0; i<n; i++){
        int pos=Minimum(arr, i, n);
        if(arr[pos]<arr[i]){
            swap(arr[pos], arr[i]);
        }
    }
}

// Time Complexity:- O(n^2)
// Space Complexity:- O(n), recursion stack space.
void RecursiveSelectionSort(int arr[], int i, int n){
    if(n==1){
        return;
    }

    int pos=Minimum(arr, i, n);

    if(pos!=i){
        swap(arr[pos], arr[i]);
    }
    
    RecursiveSelectionSort(arr, i+1, n-1);
}

void print(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<"  ";
    }
}
int main(){
    int arr[]={8, 9, 2, 5, 4, 7, 1, 10};
    // int arr[]={1, 2, 3, 4, 5};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"Iterative Selection Sort:\n";
    SelectionSort(arr, n);
    print(arr, n);

    cout<<"\nRecursive Selection Sort:\n";
    RecursiveSelectionSort(arr, 0, n);
    print(arr, n);
    return 0;
}
