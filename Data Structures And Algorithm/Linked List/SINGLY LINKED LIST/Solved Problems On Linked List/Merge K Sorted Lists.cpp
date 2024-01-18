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
// struct Node *ConvertArrayToLinkedList(vector<int> &arr){
// 	struct Node *head=new Node(arr[0]);
// 	if(head==NULL){
// 		return NULL;
// 	}
// 	struct Node *current=head;
// 	for(int i=1; i<arr.size(); i++){
// 		struct Node *temp=new Node(arr[i]);
// 		current->next=temp;
// 		current=temp;
// 	}
// 	return head;
// }
// BRUTE FORCE APPROACH
// Time Complexity:- O(k*n)+O((m)log(m))+O(m), O(k*n) to convert
//                   linked list to array, O((m)log(m)) to sort the
//                   array and O(m) to convert the array to linked list.
// m=n*k
// k is the number of linked lists
// n is assumed to the size of each lists
// Space Complexity:- O(m)+O(m), O(m) to push the data of the linked list
//                    into array and O(m) to store the linked list which is
//                    converted from the array.
// struct Node *MergeKSortedLinkedList(vector<Node*> &lists){
//     vector<int> arr;
//     for(int i=0; i<lists.size(); i++){
//         struct Node *temp=lists[i];
//         while(temp!=NULL){
//             arr.push_back(temp->data);
//             temp=temp->next;
//         }
//     }
//     sort(arr.begin(), arr.end());
//     struct Node *newHead=ConvertArrayToLinkedList(arr);
//     return newHead;
// }

// BETTER APPROACH
// struct Node *MergeTwoSortedList(struct Node *head1, struct Node *head2){
//     if(!head1){
//         return head2;
//     }
//     if(!head2){
//         return head1;
//     }
//     if(head1->data>head2->data){
//         swap(head1, head2);
//     }
//     Node *res=head1;
//     while(head1 && head2){
//         Node *temp=NULL;
//         while(head1 && head1->data<=head2->data){
//             temp=head1;
//             head1=head1->next;
//         }
//         temp->next=head2;
//         swap(head1,head2);
//     }
//     return res;
// }
// Assuming the size of each linked list to be n.
// We have to merge 'k' sorted lists.
// When we are merging two linked list the size of 
// linked is increased by 'n' which means after every
// merge operation 'n' number of nodes are added to the
// linked list.
// Suppose k=4,then the number of iteration performed is
// (n+2n+3n+4n),now take n common n(1+2+3+4),therefore the 
// complexity becomes O(n(4*(4+1)/2)).
// Suppose 'k' was even more larger, then the time complexity
// would be O(n*(k*(k+1)/2)).
// Time Complexity:-O(n*(k*(k+1)/2))
// Space Complexity:- O(1)
// struct Node *MergeKSortedLinkedList(vector<Node*> &lists){
//     struct Node *head=lists[0];
//     for(int i=1; i<lists.size(); i++){
//         head=MergeTwoSortedList(head, lists[i]);
//     }
//     return head;
// }

// Note:- For any opearation on priority queue the
// time complexity is always logarithmic.
// Here we have assumed the size of each linked
// list to be 'n'.
// Time Complexity:- O(k*log(k))+O(k*n)*O(3*log(k)),
//                   O(k*log(k)), to insert k lists in
//                   priority queue. O(k*n), for while loop.
//                   O(3*log(k)) because we are performing
//                   three operations on priority queue.
// Space Complexity:- O(k), because we are using 
//                    priority queue.
struct Node *MergeKSortedLinkedList(vector<Node*> &lists){
    priority_queue<pair<int, Node*>, vector<pair<int, Node*>>, greater<pair<int, Node*>>>pq;
    for(int i=0; i<lists.size(); i++){
        if(lists[i]){
            pq.push({lists[i]->data, lists[i]});
        }
    }
    struct Node *dummy=new Node(-1);
    struct Node *temp=dummy;
    while(!pq.empty()){
        auto it=pq.top();
        pq.pop();
        if(it.second->next){
            pq.push({it.second->next->data, it.second->next});
        }
        temp->next=it.second;
        temp=temp->next;
    }
    return dummy->next;
}
void Traverse(struct Node *head){
    if(head==NULL){
        return;
    }
    struct Node *temp=head;
    while(temp){
        cout<<temp->data<<"  ";
        temp=temp->next;
    }
}
int main() {
    vector<Node*> lists;
    lists.push_back(new Node(12));
    lists.back()->next = new Node(14);
    lists.back()->next->prev = lists.back();
    lists.back()->next->next = new Node(16);
    lists.back()->next->next->prev = lists.back()->next;

    lists.push_back(new Node(10));
    lists.back()->next = new Node(12);
    lists.back()->next->prev = lists.back();

    lists.push_back(new Node(8));
    lists.back()->next = new Node(20);
    lists.back()->next->prev = lists.back();

    struct Node *mergedHead = MergeKSortedLinkedList(lists);
    cout << "Merged Sorted List: ";
    Traverse(mergedHead);
    return 0;
}
