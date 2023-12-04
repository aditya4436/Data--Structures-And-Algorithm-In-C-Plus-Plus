#include<bits/stdc++.h>
using namespace std;
// Time Complexity:- O(n)
// Space Complexity:- O(1)
// int FindPeak(vector<int> &arr)
// {
//     int n=arr.size();
//     for(int i=0; i<n; i++)
//     {
//         if ((i == 0 || arr[i - 1] < arr[i]) && ((i == n - 1) ||arr[i] > arr[i + 1]))
//         {
//             return arr[i];
//         }
//     }
//     return -1;
// }

// Time Complexity:- O(n)
// Space Complexity:- O(1)
// int FindPeak(vector<int> &arr)
// {
//     int n=arr.size();
//     for(int i=0; i<n; i++)
//     {
//       if((i==0) && arr[i+1]<arr[i])
//       {
//           return i;
//       }
//       if(i==(n-1) && arr[i-1]<arr[i])
//       {
//           return i;
//       }
//       if(arr[i]>arr[i-1] && arr[i]>arr[i+1])
//       {
//           return i;
//       }
//     }
//     return -1;
// }

// Time Complexity:- O(log n)
// Space Complexity:- O(1)
int FindPeak(vector<int> &arr) {
    // Write your code here
    int n=arr.size();
    int low=1, high=n-2;
    if(n==1)
    {
        return 0;
    }
    if(arr[0]>arr[1])
    {
        return 0;
    }
    if(arr[n-1]>arr[n-2])
    {
        return n-1;
    }
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])
        {
            return mid;
        }
        if(arr[mid]>arr[mid-1])
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    return -1;
}

int main()
{
    vector<int> arr={1,2,3,4,5};
    cout<<FindPeak(arr);
    return 0;
}