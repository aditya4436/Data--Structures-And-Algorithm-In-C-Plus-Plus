#include<bits/stdc++.h>
using namespace std;
// OPTIMIZED APPROACH
// Time Complexity:- O((n/2)*(n/2))
// Space Complexity:- O(1)
vector<vector<int>> rotate(vector<vector<int>> &arr)
{
    int n=arr.size();
    vector<vector<int>> ans(n, vector<int> (n, 0));
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            swap(arr[i][j], arr[j][i]);
        }
    }
    for(int i=0; i<n; i++)
    {
        reverse(arr[i].begin(), arr[i].end());
    }
    return arr;
}
int main() {
    vector < vector < int >> arr;
    arr =  {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector < vector < int >> rotated = rotate(arr);
    cout << "Rotated Image" << endl;
    for (int i = 0; i < rotated.size(); i++) {
    for (int j = 0; j < rotated[0].size(); j++) {
        cout << rotated[i][j] << " ";
    }
    cout << "\n";
    }

}