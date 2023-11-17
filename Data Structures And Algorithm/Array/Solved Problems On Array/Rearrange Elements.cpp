#include<bits/stdc++.h>
using namespace std;
// Time Complexity:- O(n+(n/2))
// Space Complexi:- O(n), because we have used extra space n/2 space for both
//                  the positve and negative elements.
// vector<int> RearrangeElements(vector<int> arr)
// {
//     int n=arr.size();
//     vector<int> pos;
//     vector<int> neg;
//     for(int i=0; i<n; i++)
//     {
//         if(arr[i]>0)
//         {
//             pos.push_back(arr[i]);
//         }
//         else
//         {
//             neg.push_back(arr[i]);
//         }
//     }
//     for(int i=0; i<n/2; i++)
//     {
//         arr[i*2]=pos[i];
//         arr[i*2+1]=neg[i];
//     }
//     return arr;
// }

// WHEN THE POSITIVE ELEMENTS ARE MORE THAN NEGATIVE OR VICE-VERSA
// Time Complexity:- O(2n)
// Space Complexity:- O(n)
// vector<int> RearrangeElements(vector<int> arr)
// {
//     int n=arr.size();
//     vector<int> pos;
//     vector<int> neg;
//     for(int i=0; i<n; i++)
//     {
//         if(arr[i]>0)
//         {
//             pos.push_back(arr[i]);
//         }
//         else
//         {
//             neg.push_back(arr[i]);
//         }
//     }
//     if(pos.size()<neg.size())
//     {
//         for(int i=0; i<pos.size(); i++)
//         {
//             arr[i*2]=pos[i];
//             arr[i*2+1]=neg[i];
//         }
//         int index=pos.size()*2;
//         for(int i=pos.size(); i<neg.size(); i++)
//         {
//             arr[index]=neg[i];
//             index++;
//         }
//     }
//     else
//     {
//         for(int i=0; i<neg.size(); i++)
//         {
//             arr[i*2]=pos[i];
//             arr[i*2+1]=neg[i];
//         }
//         int index=neg.size()*2;
//         for(int i=neg.size(); i<pos.size(); i++)
//         {
//             arr[index]=pos[i];
//             index++;
//         }
//     }
//     return arr;
// }

// OPTIMAL APPROACH
// Time Complexity:- O(n)
// Space Complexity:- O(n)
vector<int> RearrangeElements(vector<int> arr)
{
    int n=arr.size();
    vector<int> ans(n, 0);
    int posIndex=0, negIndex=1;
    for(int i=0; i<n; i++)
    {
        if(arr[i]<0)
        {
            ans[negIndex]=arr[i];
            negIndex+=2;
        }
        else
        {
            ans[posIndex]=arr[i];
            posIndex+=2;
        }
    }
    return ans;
}
int main()
{
    vector<int> arr={-1, 1,2,-4,-5};
    vector<int> array=RearrangeElements(arr);
    for(int i=0; i<arr.size(); i++)
    {
        cout<<array[i]<<"  ";
    }
    return 0;
}