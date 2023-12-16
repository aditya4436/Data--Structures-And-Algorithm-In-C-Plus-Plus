#include<bits/stdc++.h>
using namespace std;
// BRUTE FORCE APPROACH
// Time Complexity:- O(n1+n2)
// Space Complexity:- O(n1+n2)
// double Median(vector<int> &a, vector<int> &b){
//     vector<int> ans;
//     int n1=a.size(), n2=b.size();
//     int left=0, right=0;
//     while(left<n1 && right<n2){
//         if(a[left]<b[right]){
//             ans.push_back(a[left]);
//             left++;
//         }
//         else{
//             ans.push_back(b[right]);
//             right++;
//         }
//     }
//     while(left<n1){
//         ans.push_back(a[left]);
//         left++;
//     }
//     while(right<n2){
//         ans.push_back(b[right]);
//         right++;
//     }
//     int n=n1+n2;
//     if(n%2==1){
//         return ans[n/2];
//     }
//     return (double)(((double)(ans[n/2])+(double)(ans[n/2-1]))/2.0);
// }

// Time Complexity:- O(n1+n2)
// Space Complexity:- O(1)
// double Median(vector<int> &a, vector<int> &b){
//     int n1=a.size(), n2=b.size();
//     int n=(n1+n2);
//     int index2=n/2, index1=index2-1, count=0;
//     int index1element=-1, index2element=-1;
//     int left=0, right=0;
//     while(left<n1 && right<n2){
//         if(a[left]<b[right]){
//             if(count==index1){
//                 index1element=a[left];
//             }
//             if(count==index2){
//                 index2element=a[left];
//             }
//             count++;
//             left++;
//         }
//         else{
//             if(count==index1){
//                 index1element=b[right];
//             }
//             if(count==index2){
//                 index2element=b[right];
//             }
//             count++;
//             right++;
//         }
//     }
//     while(left<n1){
//         if(count==index1){
//             index1element=a[left];
//         }
//         if(count==index2){
//             index2element=a[left];
//         }
//         count++;
//         left++;
//     }
//     while(right<n2){
//         if(count==index1){
//             index1element=b[right];
//         }
//         if(count==index2){
//             index2element=b[right];
//         }
//         count++;
//         right++;
//     }
//     if(n%2==1){
//         return index2element;
//     }
//     return (double)((double)(index1element+index2element)/2.0);
// }

// Time Complexity:- O(min(logn1,logn2))
// Space Complexity:- O(1)
double Median(vector<int> &a, vector<int> &b){
    int n1=a.size();
    int n2=b.size();
    if(n1>n2){
        return Median(b, a);
    }
    int low=0, high=n1;
    int left=(n1+n2+1)/2;
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
            if(n%2==1){
                return(max(l1, l2));
            }
            return ((double)(max(l1,l2)+min(r1,r2))/2.0);
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
    cout<<Median(a,b);
    return 0;
}
