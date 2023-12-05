#include<bits/stdc++.h>
using namespace std;
// Time Complexity:- O(m*log n)
// Space Complexity:- O(1)
// int SquareRoot(int n, int m){
//     for(int i=1; i<=m; i++){
//         if(round(pow(i, n))==m){
//             return i;
//         }
//         else if(round(pow(i, n))>m){
//             break;
//         }
//     }
//     return -1;
// }

// Time Complexity:- O(log m)
// Space Complexity:- O(1);
int SquareRoot(int n, int m){
    int low=1, high=m;
    while(low<=high){
        int mid=(low+high)/2;
        if(round(pow(mid, n))==m){
            return mid;
        }
        else if(round(pow(mid, n))<m){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return -1;
}
int main()
{
    int n=4, m=27;
    cout<<SquareRoot(n, m);
    return 0;
}