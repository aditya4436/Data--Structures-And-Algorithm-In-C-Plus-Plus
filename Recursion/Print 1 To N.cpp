#include<bits/stdc++.h>
using namespace std;
// Time Complexity:- O(n)
// Space Complexity:- O(n), this space is used internally by the computer
//                    to store the output of previously generated result
//                    untill the base condition is not satisfied.   
void PrintNTimes(int i, int n){
    if(i>n){
        return;
    }
    cout<<i<<"  ";
    PrintNTimes(i+1, n);
}
int main(){
    int n=4, i=1;
    PrintNTimes(1, n);
    return 0;
}
