// OPTIMIZED APPROACH WHEN THE ELEMENT IN AN ARRAY CONATINS BOTH +VE AND -VE ELEMENT
// Time Complexity:- O(n*log n)
// SpaceComplexity:- O(n)
int LongestSubarrayWithSumK(vector<int> &arr, int k)
{
    int n=arr.size();
    int maxlen=0, sum=0;
    map<int, int> preSumMap;
    for(int i=0; i<n; i++)
    {
        sum+=arr[i];
        if(sum==k)
        {
            maxlen=max(maxlen, i+1);
        }
        int rem=sum-k;
        if(preSumMap.find(rem)!=preSumMap.end())
        {
            int len=i-preSumMap[rem];
            maxlen=max(maxlen, len);
        }
        if(preSumMap.find(sum)==preSumMap.end())
        {
            preSumMap[sum]=i;
        }
    }
    return maxlen;
}
int main()
{
    vector<int> arr={10, 5, 2, 7, 1, 9};
    int k=15;
    cout<<LongestSubarrayWithSumK(arr, k);
    return 0;
}