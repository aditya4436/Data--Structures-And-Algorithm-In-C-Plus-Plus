#include<bits/stdc++.h>
using namespace std;
// BRUTE-FORCE APPROACH.
// Time Complexity:- O(n+m)
// Auxiliary Space Complexity:- O(m)
// vector<int> ShiftZeroes(vector<int> &nums, int n)
// {
//     vector<int> temp;
//     for(int i=0;i<n;i++)
//     {
//         if(nums[i]!=0)
//         {
//             temp.push_back(nums[i]);
//         }
//     }
//     int m=temp.size();
//     for(int i=0;i<m;i++)
//     {
//         nums[i]=temp[i];
//     }
//     for(int i=m; i<n; i++)
//     {
//         nums[i]=0;
//     }
//     return nums;
// }

// OPTIMIZED SOLUTION
// Time Complexity:- O(n)
// Auxiliary Space Complexity:- O(1)
vector<int> ShiftZeroes(vector<int> &arr, int n)
{
    int j=-1;
    for(int i=0; i<n; i++)
    {
        if(arr[i]==0)
        {
            j=i;
            break;
        }
    }
    if(j==-1)
    {
        return arr;
    }
    for(int i=j+1; i<n; i++)
    {
        if(arr[i]!=0)
        {
            swap(arr[i], arr[j]);
            j++;
        }
    }
    return arr;
}
int main()
{
    vector<int> arr={1, 0, 2, 3, 2, 0, 0, 4, 5, 1};
    int n=arr.size();
    vector<int> array=ShiftZeroes(arr, n);
    for(int i=0; i<n; i++)
    {
        cout<<array[i]<<"  ";
    }
    return 0;
}