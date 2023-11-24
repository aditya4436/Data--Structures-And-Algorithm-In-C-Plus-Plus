#include<bits/stdc++.h>
using namespace std;
// Time Complexiy:- O(col)
// Space Complexity:- O(1)
// This will print the element at the given row and colomn.
// int nCr(int row, int col)
// {
//     long long res=1;
//     for(int i=0; i<col; i++)
//     {
//         res=res*(row-i);
//         res=res/(i+1);
//     }
//     return res;
// }

// BRUTE FORCE APPROACH TO PRINT THE PASCAL TRIANGLE
// Time Complexity:- O(row*col)+O(col) to print each element of the row.
// Space Complexity:- O(1)
// vector<vector<int>> PascalTriangle(int row)
// {
//     vector<vector<int>> ans;
//     for(int i=1; i<=row; i++)
//     {
//         vector<int> temp;
//         for(int j=1; j<=i; j++)
//         {
//             temp.push_back(nCr(i-1, j-1));
//         }
//         ans.push_back(temp);
//     }
//     return ans;
// }

// BRUTE FORCE APPROACH TO PRINT THE Nth ROW THE PASCAL TRIANGLE.
// Time Complexity:- O(row)
// Space Complexity:- O(1)
// vector<int> GetRow(int row)
// {
//     vector<int> ans;
//     for(int i=1; i<=row; i++)
//     {
//         ans.push_back(nCr(row-1, i-1));
//     }
//     return ans;
// }

// OPTIMIZED APPROACH TO PRINT THE Nth ROW THE PASCAL TRIANGLE.
// Time Complexity:- O(row)
// Space Complexiyt:- O(1)
vector<int> GetRow(int row)
{
    long long res=1;
    vector<int> ans;
    ans.push_back(res);
    for(int i=1; i<row; i++)
    {
        res=res*(row-i);
        res=res/(i);
        ans.push_back(res);
    }
    return ans;
}

// OPTIMIZED APPROACH TO PRINT THE PASCAL'S TRIANGLE.
// Time Complexity:- O(n)+O(row), because to get the row it takes O(row).
// Space Complexity:-O(1)
vector<vector<int>> PascalTriangle(int N) 
{
    // Write your code here.
    vector<vector<int>> ans;
    for (int i = 1; i <= N; i++) 
    {
        ans.push_back(GetRow(i));
    }
    return ans;
}
int main()
{
    int row=5, col=3;
    vector<vector<int>> array=PascalTriangle(row);
    for(auto it : array)
    {
        for(auto element : it)
        {
            cout<<element<<"  ";
        }
        cout<<"\n";
    }
    return 0;
}