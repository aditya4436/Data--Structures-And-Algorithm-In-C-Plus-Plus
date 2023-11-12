#include<bits/stdc++.h>
using namespace std;
// BRUTE FORCE APPROACH.
// Time Complexity:- O(n1 log n + n2 log n) + O(n1+n2)
// Auxiliary Space complexity:- O(n1+n2) + O(n1+n2)
// vector<int> RemoveDuplicates(vector<int> &arr1, vector<int> &arr2, int n, int m)
// {
//     set<int> s;
//     for(int i=0; i<n; i++)
//     {
//         s.insert(arr1[i]);
//     }
//     for(int i=0; i<m; i++)
//     {
//         s.insert(arr2[i]);
//     }
//     vector<int> temp;
//     for(auto it : s)
//     {
//         temp.push_back(it);
//     }
//     return temp;
// }

// OTIMIZED SOLUTION
// Time Complexity:- O(n+m)
// Space Complexity:- O(n+m)
vector<int> RemoveDuplicates(vector<int> &arr1, vector<int> &arr2, int n, int m)
{
    int i=0, j=0;
    vector<int> unionArray;
    while(i<n && j<m)
    {
        if(arr1[i]<=arr2[j])
        {
            if(unionArray.size()==0 || unionArray.back()!=arr1[i])
            {
                unionArray.push_back(arr1[i]);
            }
            i++;
        }
        else
        {
            if(unionArray.size()==0 || unionArray.back()!=arr2[j])
            {
                unionArray.push_back(arr2[j]);
            }
            j++;
        }
    }
    while(i<n)
    {
        if(unionArray.size()==0 || unionArray.back()!=arr1[i])
        {
            unionArray.push_back(arr1[i]);
        }
        i++;
    }
    while(j<m)
    {
        if(unionArray.size()==0 || unionArray.back()!=arr2[j])
        {
            unionArray.push_back(arr2[j]);
        }
        j++;
    }
    return unionArray;
}

int main()
{
    vector<int> arr1={1, 1, 2, 3, 4, 4, 5, 6, 6, 7};
    vector<int> arr2={7, 7, 8, 9, 9, 10, 10, 4, 3};
    int m=arr2.size();
    int n=arr1.size();
    vector<int> array=RemoveDuplicates(arr1, arr2, n, m);
    for(int i=0; i<n; i++)
    {
        cout<<array[i]<<"  ";
    }
    return 0;
}