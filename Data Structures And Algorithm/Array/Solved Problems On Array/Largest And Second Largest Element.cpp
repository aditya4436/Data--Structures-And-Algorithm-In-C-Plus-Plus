// Time Complexity:- For both SecondLargestElement() and LargestElement() is same i.e., O(n).
#include<bits/stdc++.h>
using namespace std;
int SecondLargestElement(vector<int> &arr, int n)
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
    return slargest;
}
int LargestElement(vector<int> &arr, int n)
{
    int largest=arr[0];
    for(int i=0; i<n; i++)
    {
        if(arr[i]>largest)
        {
            largest=arr[i];
        }
    }
    return largest;
}
int main()
{
    vector<int> arr={10, 25, -12, -6, 20, 20 };
    int n=arr.size();
    cout<<"The first largest element:\n"<<LargestElement(arr, n);
    cout<<"\nThe second largest element:\n"<<SecondLargestElement(arr, n);
    return 0;
}
