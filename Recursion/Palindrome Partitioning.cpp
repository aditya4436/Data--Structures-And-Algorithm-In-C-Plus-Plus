#include <bits/stdc++.h> 
using namespace std;
// Time Complexity:- O((2^n)*k*(n/2)), O(n/2), to generate all the substring
//                   O(n/2) to check if the substring generated is a palindrome
//                   or not. O(k) is for inserting the palindromes into another
//                   data structure, where 'k' is the average length of the palindrome
//                   list.
// Space Complexity:- O(k*x), 'k is the average length of the list of palindromes and
//                    if we have 'x' such list of palindromes in our final answer. The depth
//                    of the recursion tree is n, so the auxiliary space required is equal to
//                    the O(n).
bool IsPaLindrome(string s, int start, int end){
    while(start<=end){
        if(s[start++]!=s[end--]){
            return false;
        }
    }
    return true;
}
void GeneratePalindromes(int index, string &s, vector<string> &path, vector<vector<string>> &res){
    if(index==s.size()){
        res.push_back(path);
        return;
    }
    for(int i=index; i<s.size(); i++){
        if(IsPaLindrome(s, index, i)){
            path.push_back(s.substr(index, i-index+1));
            GeneratePalindromes(i+1, s, path, res);
            path.pop_back();
        }
    }
}
vector<vector<string>> Partition(string &s) 
{
    vector<vector<string>> res;
    vector<string> path;
    GeneratePalindromes(0, s, path, res);
    return res;
}
int main()
{
    string s="aabb";
    vector<vector<string>> ans=Partition(s);
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<"  ";
        }
        cout<<endl;
    }
    return 0;
}
