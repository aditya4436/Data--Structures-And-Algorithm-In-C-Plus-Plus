#include<bits/stdc++.h>
using namespace std;
// Time Complexity:- O(min(logn1,logn2))
// Space Complexity:- O(1)
double MergeTwoSortedArray(vector<int> &a, vector<int> &b, int n1, int n2, int k){
        if(n1>n2){
        return kthElement(b, a, n2, n1, k);
    }
    int low=max(k-n2, 0), high=min(n1, k);
    int left=k;
    int n=n1+n2;
    while(low<=high){
        int mid1=(low+high)/2;
        int mid2=left-mid1;
        int l1=INT_MIN, l2=INT_MIN;
        int r1=INT_MAX, r2=INT_MAX;
        if(mid1<n1){
            r1=a[mid1];
        }
        if(mid2<n2){
            r2=b[mid2];
        }
        if(mid1-1>=0){
            l1=a[mid1-1];
        }
        if(mid2-1>=0){
            l2=b[mid2-1];
        }
        if(l1<=r2 && l2<=r1){
            return max(l1, l2);
        }
        else if(l1>r2){
            high=mid1-1;
        }
        else{
            low=mid1+1;
        }
    }
    return 0;
}
int main(){
    vector<int> a={2,4,6};
    vector<int> b={1,3,5};
    int n1=a.size(), n2=b.size(), k=4;
    cout<<MergeTwoSortedArray(a, b, n1, n1, k);
    return 0;
}
