#include<bits/stdc++.h>
using namespace std;
// Time Complexity:- O(n/2) because the function checks till the
//                   (n/2)th character of the string.
// Space Complexity:- O(n/2) this space is taken by the recursive stack
bool IsPalindrome(string s, int n, int i){
    if(i>=n/2){
        return true;
    }
    if(s[i]!=s[n-i-1]){
        return false;
    }
    return IsPalindrome(s, n, i+1);
}
int main(){
    string s="Aditya";
    int n=s.size(), i=0;
    if(IsPalindrome(s, n, i)==true){
        cout<<"The string is Palindrome.";
    }
    else{
        cout<<"The string is not Palindrome.";
    }
    return 0;
}
