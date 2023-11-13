// Time Complexity:- O(n)
// Auxiliary Space Complexity:- O(1)
#include<bits/stdc++.h>
using namespace std;
int MaximumConsecutiveOnes(vector<int> &nums)
{
    int n=nums.size();
    int count=0, m=0;
    for(int i=0; i<n; i++)
    {
        if(nums[i]==1)
        {
            count++;
        }
        else
        {
            count=0;
        }
        m=max(count, m);
    }
    return m;
}
int main()
{
    vector<int> arr={1, 1, 0, 1, 1, 1, 0, 1, 1};
    cout<<MaximumConsecutiveOnes(arr);
    return 0;
}