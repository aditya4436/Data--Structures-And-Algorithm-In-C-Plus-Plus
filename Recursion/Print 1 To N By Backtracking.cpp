#include<bits/stdc++.h>
using namespace std;
// Time Complexity:- O(n)
// Space Complexity:- O(n), this space is used internally by the computer
//                    to store the output of previously generated result
//                    untill the base condition is not satisfied.   
void PrintNTimes(int n){
    if(n==0){
        return;
    }
    PrintNTimes(n-1);
    cout<<n<<"  ";
}
int main(){
    int n=10;
    PrintNTimes(n);
    return 0;
}
