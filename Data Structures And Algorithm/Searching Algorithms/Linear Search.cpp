// Time Complexity:- O(N), where 'N' is the number of element in an
//                   array.
// Auxiliary Space Complexity:- O(1), because we have not used any extra space.
#include<iostream>
using namespace std;
int Sequential_Search(int arr[], int n, int target)
{
    for(int i=0; i<n; i++)
    {
        if(arr[i]==target)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    int arr[]={21, 32, 45, 18, 90};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"The number is at index:\n"<<Sequential_Search(arr, n, 45);
    return 0;
}