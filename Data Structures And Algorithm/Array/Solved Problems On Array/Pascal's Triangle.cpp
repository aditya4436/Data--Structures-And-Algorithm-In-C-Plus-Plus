#include<bits/stdc++.h>
using namespace std;
// Time Complexity:- O(colIndex), 'colIndex' is the number of colomn.
// Space Complexity:- O(1).
// This function prints the element at a given row index and colomn
// colomn index.
int GetPascalElement(int row, int col)
{
    long long res=1;
    for(int i=0; i<col; i++)
    {
        res=res*(row-i);
        res=res/(i+1);
    }
    return res;
}

// BRUTE-FORCE APPROACH TO PRINT THE Nth ROW.
// Time Complexity:- O(row * col) 'row' is the number of rows.
//                   'col' is number if colomns.
// Space Comlexity:- O(1), the extra space that I have used to store
//                   and return the ans and not to solve the problem.
// vector<int> GetRow(int row)
// {
//     vector<int> ans;
//     for(int i=1; i<=row; i++)
//     {
//         ans.push_back(GetPascalElement(row-1, i-1));
//     }
//     return ans;
// }

// OPTIMIZED APPROACH APPROACH TO PRINT THE Nth ROW.
// Time Complexity:- O(row).
// Space Complexity:- O(1), because I have not used any extra space
//                    to solve the problem. I have used extra space
//                    to store and return the answer.
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

// BRUTE FORCE APPROACH TO PRINT PASCAL TRIANGLE.
// Time Complexity:- O(row^3)
// Space Complexity:- O(1), because I have not used any extra space
//                    to solve the problem. I have used extra space
//                    to store and return the answer.
// vector<vector<int>> PascalTriangle(int row)
// {
//     vector<vector<int>> ans;
//     for(int i=1; i<=row; i++)
//     {
//         vector<int> temp;
//         for(int j=1; j<=i; j++)
//         {
//             temp.push_back(GetPascalElement(i-1, j-1));
//         }
//         ans.push_back(temp);
//     }
//     return ans;
// }

// OPTIMIZED APPROACH TO PRINT PASCAL TRIANGLE
// Time Complexity:- O(row^row)
// Space Complexity:- O(1)
vector<vector<int>> PascalTriangle(int row)
{
    vector<vector<int>> ans;
    for(int i=1; i<=row; i++)
    {
        ans.push_back(GetRow(i));
    }
    return ans;
}
int main()
{
    // It will print the element at given row and colomn of Pascal Triangle.
    // int row=5, col=3;
    // cout<<"The element at row "<<row<<" and "<<col<<" is:\n"<<GetPascalElement(row, col)<<endl;

    // This will print the elements at a given row.
    // int row=3;
    // vector<int> array=GetRow(row);
    // for(int i=0; i<array.size(); i++)
    // {
    //     cout<<array[i]<<"  ";
    // }

    int row=5;
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
