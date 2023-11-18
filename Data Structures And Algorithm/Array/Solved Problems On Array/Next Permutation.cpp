#include<bits/stdc++.h>
using namespace std;
// vector<int> NextPermutation(vector<int> &arr)
// {
//     next_permutation(arr.begin(), arr.end());
//     return arr;
// }

// Time Complexity:- O(3n), because of two for loops and one to reverse the array which
//                   takes O(n) time.
// Space Complexity:- O(1)
vector<int> NextPermutation(vector<int> &arr)
{
    int n=arr.size(), index=-1;
    for(int i=n-2; i>=0; i--)
    {
        if(arr[i]>arr[i+1])
        {
            index=i;
            break;
        }
    }
    for(int i=n-1; i>index; i--)
    {
        if(arr[i]>arr[index])
        {
            swap(arr[index], arr[i]);
            break;
        }
    }
    if(index==-1)
    {
        reverse(arr.begin(), arr.end());
        return arr;
    }
    reverse(arr.begin()+index+1, arr.end());
    return arr;
}
int main()
{
    vector<int> arr={3, 1, 2};
    vector<int> array=NextPermutation(arr);
    for(int i=0; i<arr.size(); i++)
    {
        cout<<array[i]<<"  ";
    }
    return 0;
}