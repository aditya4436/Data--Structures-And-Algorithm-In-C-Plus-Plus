#include<bits/stdc++.h>
using namespace std;
int FirstOccurence(vector<int> &arr, int target)
{
    int low=0, high=arr.size()-1;
    int first=-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(arr[mid]==target)
        {
            first=mid;
            high=mid-1;
        }
        else if(arr[mid]<target)
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    return first;
}
int LastOccurence(vector<int> &arr, int target)
{
    int low=0, high=arr.size()-1;
    int second=-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(arr[mid]==target)
        {
            second=mid;
            low=mid+1;
        }
        else if(arr[mid]<target)
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    return second;
}
int Count(vector<int>& arr, int x) 
{
	int first=FirstOccurence(arr, x);
	if(first==-1 || arr[first]!=x)
	{
		return 0;
	}
	int last=LastOccurence(arr, x);
	int ans=last-first+1;
	return ans;
}
int main()
{
    vector<int> arr={1,3,3,5};
    int target=3;
    cout<<Count(arr, target);
    return 0;
}