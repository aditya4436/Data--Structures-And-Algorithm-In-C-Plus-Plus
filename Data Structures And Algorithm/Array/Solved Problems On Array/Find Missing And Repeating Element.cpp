#include<bits/stdc++.h>
using namespace std;
// BRUTE FORCE APPROACH
// Time Complexity:- O(n^2)+O(n)
// Space Comlexity:- O(n)
// vector<int> RepeatingAndMissingNumber(vector<int> &arr)
// {
//     sort(arr.begin(), arr.end());
//     int n=arr.size(), count=1;
//     vector<int> ans;
//     for(int i=0; i<n; i++)
//     {
//         for(int j=i+1; j<n; j++)
//         {
//             if(arr[i]==arr[j])
//             {
//                 ans.push_back(arr[i]);
//             }
//         }
//     }
//     for(int i=1; i<n; i++)
//     {
//         if(arr[i]==arr[i-1])
//         {
//             continue;
//         }
//         if(arr[i]!=arr[i-1]+1)
//         {
//             ans.push_back(arr[i-1]+1);
//         }
//     }
//     return ans;
// }

// BRUTE FORCE-2
// Time Complexity:- O(n^2)
// Space Complexity:- O(1)
// vector<int> RepeatingAndMissingNumber(vector<int> &arr)
// {
//     int n=arr.size(), repeating=-1, missing=-1;
//     for(int i=1; i<=n; i++)
//     {
//         int count=0;
//         for(int j=0; j<n; j++)
//         {
//             if(arr[j]==i)
//             {
//                 count++;
//             }
//         }
//         if(count==2)
//         {
//             repeating=i;
//         }
//         else if(count==0)
//         {
//             missing=i;
//         }
//         if(repeating!=-1 && missing!=-1)
//         {
//             break;
//         }
//     }
//     return{repeating, missing};
// }

// BETTER THAN BRUTE FORCE
// Time Complexity:- O(2n)
// Space Complexity:- O(n)
// vector<int> RepeatingAndMissingNumber(vector<int> &arr)
// {
//     int m=INT_MIN;
//     int n=arr.size();
//     int repeating=-1;
//     int missing=-1;
//     vector<int> harr(n, 0);
//     for(int i=0; i<n; i++)
//     {
//         harr[arr[i]]++;
//     }
//     for(int i=1; i<=n; i++)
//     {
//         if(harr[i]==2)
//         {
//             repeating=i;
//         }
//         else if(harr[i]==0)
//         {
//             missing=i;
//         }
//         if(repeating!=-1 && missing!=-1)
//         {
//             break;
//         }
//     }
//     return{repeating, missing};
// }

vector<int> RepeatingAndMissingNumber(vector<int> &arr)
{
    long long n=arr.size();
    long long sn=(n*(n+1))/2;   //Sum of natural numbers
    long long s2n=(n*(n+1)*(2*n+1))/6;  //Sum of squares of natural number
    long long s=0, s2=0;
    for(int i=0; i<n; i++)
    {
        s+=arr[i];  // Sum of array elements
        s2+=(long long)arr[i]*(long long)arr[i];  //Sum of squares of array elements
    }
    long long val1=s-sn;
    long long val2=s2-s2n;
    val2=val2/val1;
    long long x=(val1+val2)/2;
    long long y=x-(val1);
    return {(int)x, (int)y};
}
int main()
{
    vector<int> arr={1,2,3,2};
    vector<int> ans=RepeatingAndMissingNumber(arr);
    for(int i=0; i<ans.size(); i++)
    {
        cout<<ans[i]<<"  ";
    }
    return 0;
}