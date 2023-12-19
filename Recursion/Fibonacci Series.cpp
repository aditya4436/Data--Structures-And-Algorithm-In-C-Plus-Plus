#include<bits/stdc++.h>
using namespace std;
// Time Complexity:- O(2^n), because everytime we are calling the
//                   function times.
// Space Complexity:- O(n), at maximum there could be n function calls
//                    waiting in the recursion stack since we need to
//                    calculate the nth fibonacci number for which we 
//                    we also need to calculate (n-1) fibonacci number
//                    before it.
int FibonacciNumber(int n){
    if(n<=1){
        return n;
    }
    return FibonacciNumber(n-1)+FibonacciNumber(n-2);
}
int main(){
    int n=4;
    cout<<FibonacciNumber(n);
    return 0;
}
