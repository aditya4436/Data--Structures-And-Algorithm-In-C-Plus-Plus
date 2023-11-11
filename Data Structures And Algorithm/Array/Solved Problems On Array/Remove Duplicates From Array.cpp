// Time Complexity:- O(n)
// Auxiliary Space Complexity:- O(1)
#include<bits/stdc++.h>
using namespace std;
int RemoveDuplicates(vector<int> &arr, int n)
{
    int i=0;
    for(int j=1; j<n; j++)
    {
        if(arr[i]!=arr[j])
        {
            arr[i+1]=arr[j];
            i++;
        }
    }
    return (i+1);
}
int main()
{
    vector<int> arr={1, 2, 2, 3, 3, 3, 4, 4, 5, 5};
    int n=arr.size();
    cout<<RemoveDuplicates(arr, n);
    return 0;
}