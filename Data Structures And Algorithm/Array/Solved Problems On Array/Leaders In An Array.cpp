#include<bits/stdc++.h>
using namespace std;
// Time Complexity:- O(n^2)
// Space Comlexity:- O(1)
// vector<int> Leaders(vector<int> &arr)
// {
//     int n=arr.size();
//     vector<int> ans;
//     for(int i=0; i<n; i++)
//     {
//         bool leader=true;
//         for(int j=i+1; j<n; j++)
//         {
//             if(arr[i]<arr[j])
//             {
//                 leader=false;
//                 break;
//             }
//         }
//         if(leader)
//         {
//             ans.push_back(arr[i]);
//         }
//     }
//     return ans;
// }

// OPTIMIZED APPROACH
// Time Complexity:- O(n*log n), because we have used sort function
// Space Complexity:- O(1). We are using the extra space to return or store the result
vector<int> Leaders(vector<int> &arr)
{
    int maximum=INT_MIN;
    vector<int> result;
    for(int i=arr.size()-1; i>=0; i--)
    {
        if(arr[i]>maximum)
        {
            result.push_back(arr[i]);
        }
        maximum=max(arr[i], maximum);
    }
    sort(result.begin(), result.end());
    return result;
}
int main()
{
    vector<int> arr={10, 22, 12, 3, 0, 6};
    vector<int> array=Leaders(arr);
    for(int i=0; i<array.size(); i++)
    {
        cout<<array[i]<<"  ";
    }
    return 0;
}