#include<bits/stdc++.h>
using namespace std;
// BRUTE FORCE APPROACH
// Time Complexity:- O(n+k)
// Space Complexity:- O(k)
// void RightRotateArray(int arr[], int n, int k)
// {
//     if(n==0)
//     {
//         return;
//     }
//     k=k%n;
//     if(k==0)
//     {
//         return;
//     }
//     int temp[k];
//     for(int i=n-k; i<n; i++)
//     {
//         temp[i-(n-k)]=arr[i];
//     }
//     for(int i=n-k-1; i>=0; i--)
//     {
//         arr[i+k]=arr[i];
//     }
//     for(int i=0; i<k; i++)
//     {
//         arr[i]=temp[i];
//     }
// }

//OPTIMIZED SOLUTION
// Time Commplexity:- O(2*n)
// Space Complexity:-O(1)
void RightRotateArray(vector<int> &arr, int k)
{
    int n=arr.size()-1;
    if(n==0)
    {
        return;
    }
    k=k%arr.size();
    reverse(arr.begin() + (arr.size()-k), arr.end());
    reverse(arr.begin(), arr.begin() + arr.size()-k);
    reverse(arr.begin(), arr.end());
}
int main()
{
    vector<int> arr={1, 3, 5, 7, 9};
    int n=arr.size();
    int k=2;
    RightRotateArray(arr, k);
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<"  ";
    }
    return 0;
}