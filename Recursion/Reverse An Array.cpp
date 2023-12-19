#include<iostream>
#include<algorithm>
using namespace std;
// Time Complexity:- O(n)
// Space Complexity:- O(n), this space is used internally by the computer
//                    to store the output of previously generated result
//                    untill the base condition is not satisfied.  
int Reverse_An_Array(int arr[], int n)
{
    if(n==0||n==1)
    {
        return n;
    }
    cout<<arr[n-1]<<"  ";
    return (Reverse_An_Array(arr, n-1));
} 
// void PrintReverse(int arr[], int l, int r){
//     if(l>=r){
//         return;
//     }
//     swap(arr[l], arr[r]);
//     PrintReverse(arr, l+1, r-1);
// }
// void PrintArray(int arr[], int n){
//     for(int i=0; i<n; i++){
//         cout<<arr[i]<<"  ";
//     }
// }
int main()
{
    int n, arr[5];
    n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<5;i++)
    {
        cout<<"Enter the array element:\n";
        cin>>arr[i];
    }
    cout<<"Reversed Array is:\n"<<Reverse_An_Array(arr, n);
    return 0;
}
