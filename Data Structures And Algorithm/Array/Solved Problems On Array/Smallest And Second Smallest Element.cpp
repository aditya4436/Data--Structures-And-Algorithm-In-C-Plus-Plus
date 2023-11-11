// Time Complexity:- O(n).
#include<bits/stdc++.h>
using namespace std;
int SmallestElement(vector<int> &nums, int n)
{
    int smallest_element=nums[0];
    int second_smallest_element=INT_MAX;
    for(int i=0; i<n; i++)
    {
        if(nums[i]<smallest_element)
        {
            second_smallest_element=smallest_element;
            smallest_element=nums[i];
        }
        else if(nums[i]>smallest_element && nums[i]<second_smallest_element)
        {
            second_smallest_element=nums[i];
        }
    }
    cout<<"The smallest element is:\n"<<smallest_element<<endl;
    return second_smallest_element;
}
int main()
{
    vector<int> arr={10, 25, -12, -6, 20, 20 };
    int n=arr.size();
    cout<<"The second smallest element is:\n"<<SmallestElement(arr, n);
    return 0;
}