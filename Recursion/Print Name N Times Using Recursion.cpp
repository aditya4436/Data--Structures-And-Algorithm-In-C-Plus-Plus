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
    cout<<"Aditya  ";
    i++;
    PrintNTimes(i, n);
}
int main(){
    int n=5,i=1;
    PrintNTimes(i, n);
    return 0;
}
