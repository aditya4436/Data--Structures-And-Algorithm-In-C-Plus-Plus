#include<bits/stdc++.h>
using namespace std;
// Time Complexity:- O(n)
// Space Complexity:- O(n), this space is used internally by the computer
//                    to store the output of previously generated result
//                    untill the base condition is not satisfied.   
void PrintSum(int i, int sum){
    if(i<1){
        cout<<sum;
        return;
    }
    PrintSum(i-1, sum+i);
}
int main(){
    int n=3, sum=0;
    PrintSum(n, sum);
    return 0;
}
