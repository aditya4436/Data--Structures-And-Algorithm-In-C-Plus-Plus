#include<bits/stdc++.h>
using namespace std;
// BRUTE-FORCE
// Time Complexity:- O(n*m)
// Space Complexity:- O(m)
// vector<int> Intersection(vector<int> arr1, vector<int> arr2, int n, int m)
// {
//     vector<int> temp;
//     vector <int> visited(arr2.size(), 0); 
//     for(int i=0; i<n; i++)
//     {
//         for(int j=0; j<m; j++)
//         {
//             if(arr1[i]==arr2[j] && visited[j]==0)
//             {
//                 temp.push_back(arr1[i]);
//                 visited[j]=1;
//                 break;
//             }
//             if(arr2[j]>arr1[i])
//             {
//                 break;
//             }
//         }
//     }
//     return temp;
// }

// OPTIMIZED APPROACH
// Time Complexity:- O(n+m)
// Space Complexity: O(1)
vector<int> Intersection(vector<int> arr1, vector<int> arr2, int n, int m)
{
    int i=0, j=0;
    vector<int> temp;
    while(i<n && j<m)
    {
        if(arr1[i]!=arr2[j])
        {
            i++;
        }
        else
        {
            temp.push_back(arr1[i]);
            i++;
            j++;
        }
    }
    return temp;
}
int main()
{
    vector<int> arr1={1, 2, 2, 3, 3, 4, 5, 6};
    vector<int> arr2={2, 3, 3, 5, 6, 7};
    int n=arr1.size();
    int m=arr2.size();
    vector<int> array=Intersection(arr1, arr2, n, m);
    for(int i=0; i<n; i++)
    {
        cout<<array[i]<<"  ";
    }
    return 0;
}