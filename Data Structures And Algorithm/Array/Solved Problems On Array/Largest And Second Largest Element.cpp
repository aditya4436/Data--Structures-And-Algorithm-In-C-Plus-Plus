// Time Complexity:- O(n).
#include<bits/stdc++.h>
using namespace std;
int LargestAndSecondLargestElement(vector<int> &arr, int n)
{
    int largest=arr[0];
    int slargest=INT_MIN;
    for(int i=0; i<n; i++)
    {
        if(arr[i]>largest)
        {
            slargest=largest;
            largest=arr[i];
        }
        else if(arr[i]<largest && arr[i]>slargest)
        {
            slargest=arr[i];
        }
    }
    cout<<"The largest element is:\n"<<largest<<endl;
    return slargest;
}
int main()
{
    vector<int> arr={10, 25, -12, -6, 20, 20 };
    int n=arr.size();
    cout<<"The second largest element:\n"<<LargestAndSecondLargestElement(arr, n);
    return 0;
}
