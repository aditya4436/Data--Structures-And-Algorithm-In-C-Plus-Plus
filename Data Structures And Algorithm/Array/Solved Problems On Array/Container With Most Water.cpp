#include<bits/stdc++.h>
using namespace std;
// BRUTE FORCE APPROACH
// Time Complexity:- O(n^2)
// Space Complexity:- O(1)
// int ContainerWithMostWater(vector<int> &arr)
// {
//     int n=arr.size(), max_area=INT_MIN;
//     for(int i=0; i<n; i++)
//     {
//         for(int j=n-1; j>=0; j--)
//         {
//             int breadth=j-i;
//             int min_length=min(arr[i], arr[j]);
//             int curr_area=min_length*breadth;
//             max_area=max(max_area, curr_area);
//         }
//     }
//     return max_area;
// }

// OPTIMIZED APPROACH
// Time Complexity:- O(n)
// Space Complexity:- O(1)
int ContainerWithMostWater(vector<int> &arr)
{
    int i=0, j=arr.size()-1;
    int max_area=INT_MIN;
    while(i<j)
    {
        int min_length=min(arr[i], arr[j]);
        int breadth=j-i;
        if(arr[i]<arr[j])
        {
            i++;
        }
        else
        {
            j--;
        }
        int curr_area=min_length*breadth;
        max_area=max(max_area, curr_area);
    }
    return max_area;
}
int main()
{
    vector<int> arr={1,8,6,2,5,4,8,3,7};
    cout<<ContainerWithMostWater(arr);
    return 0;
}