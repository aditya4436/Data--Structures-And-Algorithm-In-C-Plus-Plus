// Time Complexity:- O(N LogN), N is the size of the vetor.
// Auxiliary Space Complexity:- O(N), we are using additional space while merging
//                              the elements of the vector.
#include<bits/stdc++.h>
using namespace std;
void Merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;
    int left=low;
    int right=mid+1;
    while(left<=mid && right<=high)
    {
        if(arr[left]<arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left<=mid)
    {
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=high)
    {
        temp.push_back(arr[right]);
        right++;
    }
    for(int i=low; i<=high; i++)
    {
        arr[i]=temp[i-low];
    }
}
void Merge_Sort(vector<int> &arr, int low, int high)
{
    if(low>=high)
    {
        return;
    }
    int mid=(low+high)/2;
    Merge_Sort(arr, low, mid);
    Merge_Sort(arr, mid+1, high);
    Merge(arr, low, mid, high);
}
void Print_Array(vector<int> &arr, int size)
{
    int i;
    for(i=0; i<size; i++)
    {
        cout<<arr[i]<<"  ";
    }
}
int main()
{
    vector<int> arr={4, 6, 2, 5, 7, 9, 1, 3};
    int n=arr.size();
    cout<<"Sorted array is:\n";
    Merge_Sort(arr, 0, n-1);
    Print_Array(arr, n);
    return 0;
}