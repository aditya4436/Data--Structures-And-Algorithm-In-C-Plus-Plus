// Time Complexity:- O(d*(n+k)), where 'd' is the number of digit, 'n'
//                   is the number of elements in the array and 'k' is
//                   the base number system being used or basically it
//                   is the range of the digits.
// Space Complexity:- O(n+k), where 'n' is the number of elements in the
//                    array and 'k' is the range of the digits.
#include<iostream>
using namespace std;
int Maximum_Element(int input_array[], int n)
{
    int max=input_array[0];
    for(int i=1; i<n; i++)
    {
        if(input_array[i]>max)
        {
            max=input_array[i];
        }
    }
    return max;
}
void Count_Sort(int input_array[], int n, int exp)
{
    int output_array[n];
    int i, count_array[10]={0};
    for(int i=0; i<n; i++)
    {
        count_array[(input_array[i]/exp)%10]++;
    }
    for(int i=1; i<10; i++)
    {
        count_array[i]+=count_array[i-1];
    }
    for(int i=n-1; i>=0; i--)
    {
        output_array[count_array[(input_array[i]/exp)%10]-1]=input_array[i];
        count_array[(input_array[i]/exp)%10]--;
    }
    for(int i=0; i<n; i++)
    {
        input_array[i]=output_array[i];
    }
}
void Radix_Sort(int arr[], int n)
{
    int max=Maximum_Element(arr, n);
    for(int exp=1; max/exp>0; exp*=10)
    {
        Count_Sort(arr, n, exp);
    }
}
void Print_Array(int arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<"  ";
    }
}
int main()
{
    int arr[]={543, 98, 217, 75, 329};
    int n=sizeof(arr)/sizeof(arr[0]);
    Radix_Sort(arr, n);
    Print_Array(arr, n);
    return 0;
}