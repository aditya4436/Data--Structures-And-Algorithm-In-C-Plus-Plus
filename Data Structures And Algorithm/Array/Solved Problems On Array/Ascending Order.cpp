// Time Complexity:- O(n), because we are traversing through each element
//                   in an array.
// Auxiliary Space Complexity:- O(1)
#include<bits/stdc++.h>
using namespace std;
bool AscendingOrder(vector<int> arr, int n)
{
    for(int i=1; i<n; i++)
    {
        if(arr[i-1]>arr[i])
        {
            return false;
        }
    }
    return true;
}
int main()
{
    vector<int> arr={10, 22, 36, 49, 51};
    int n=arr.size();
    if(AscendingOrder(arr, n)==true)
    {
        cout<<"The array is in ascending order.";
    }
    else{
        cout<<"The array is not in ascending order.";
    }
}