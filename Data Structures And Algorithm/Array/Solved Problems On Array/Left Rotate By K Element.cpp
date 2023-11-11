// Time Complexity:- O(n+d)
// Auxiliary Space Complexity:- O(d)
#include<bits/stdc++.h>
using namespace std;
vector<int> LeftRotate(vector<int> arr, int n, int d)
{
    d=d%n;
    vector<int> temp;
    for(int i=0; i<d; i++)
    {
        temp.push_back(arr[i]);
    }
    for(int i=d; i<n; i++)
    {
        arr[i-d]=arr[i];
    }
    for(int i=n-d; i<n; i++)
    {
        arr[i]=temp[i-(n-d)];
    }
    return arr;
}
int main()
{
    vector<int> arr={1, 2, 3, 4, 5, 6, 7};
    int n=arr.size();
    vector<int> array=LeftRotate(arr, n, 3);
    for(int i=0; i<n; i++)
    {
        cout<<array[i]<<"  ";
    }
    return 0;
}