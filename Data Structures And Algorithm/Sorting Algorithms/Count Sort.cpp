// Time Complexity:- O(n+m), for best, average and worst case and 'n' and 'm'
//                   are the size of input_array and count_array.
// Auxiliary Space Complexity:- O(n+m), where 'n' and 'm' are the space taken
//                              by output_array and count_array respectively.
#include<bits/stdc++.h>
using namespace std;
vector<int> Count_Sort(vector<int> &input_array)
{
    int n=input_array.size();
    int m=0;
    for(int i=0; i<n; i++)
    {
        m=max(m, input_array[i]);
    }
    vector<int> count_array(m+1, 0);
    for(int i=0; i<n; i++)
    {
        count_array[input_array[i]]++;
    }
    for(int i=1; i<=m; i++)
    {
        count_array[i]+=count_array[i-1];
    }
    vector<int> output_array(n);
    for(int i=n-1; i>=0; i--)
    {
        output_array[count_array[input_array[i]]-1]=input_array[i];
        count_array[input_array[i]]--;
    }
    for(int i=0; i<n; i++)
    {
        input_array[i]=output_array[i];
    }
    return input_array;
}
void Print_Array(vector<int> &arr, int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<"  ";
    }
}
int main()
{
    vector<int> arr={543, 98, 217, 75, 329};
    int n=arr.size();
    vector<int> output_array=Count_Sort(arr);
    Print_Array(arr, n);
    return 0;
}
