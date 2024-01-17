#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
    Node(int data){
        this->data=data;
        next=NULL;
        prev=NULL;
    }
};
// BRUTE FORCE APPROACH
// Time Complexity:- O(n^2)
// Space Complexity:- O(1)
// vector<pair<int, int>> FindPairs(Node* head, int k){
//     struct Node *temp1=head;
//     vector<pair<int, int>> arr;
//     while(temp1!=NULL){
//         struct Node *temp2=temp1->next;
//         while(temp2!=NULL && temp1->data+temp2->data<=k){
//             if(temp1->data+temp2->data==k){
//                 arr.push_back(make_pair(temp1->data, temp2->data));
//             }
//             temp2=temp2->next;
//         }
//         temp1=temp1->next;
//     }
//     return arr;
// } 

// OPTIMIZED APPROACH
// Time Complexity:- O(n)+O(n), O(n) to find the last node
//                   O(n) to find all the pairs.
// Space Complexity:- O(1), because we are using the extra space
//                    to store the result and not solve the problem.
vector<pair<int, int>> FindPairs(Node* head, int k){
    struct Node *left=head;
    struct Node *right=head;
    vector<pair<int, int>> arr;
    while(right->next){
        right=right->next;
    }
    while(left->data<right->data){
        if(left->data+right->data==k){
            arr.push_back(make_pair(left->data, right->data));
            left=left->next;
            right=right->prev;
        }
        else if(left->data+right->data>k){
            right=right->prev;
        }
        else{
            left=left->next;
        }
    }
    return arr;
}
int main() {
    struct Node *head = new Node(1);
    head->prev = NULL;
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(4);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new Node(9);
    head->next->next->next->next->prev = head->next->next->next;
    vector<pair<int, int>> ans = FindPairs(head, 5);
    if (ans.empty()) {
    cout <<"No pairs found."<<endl;
    } 
    else {
        for (const auto &element : ans) {
            cout<<element.first<<"  "<<element.second<<endl;
        }
    }

    return 0;
}
