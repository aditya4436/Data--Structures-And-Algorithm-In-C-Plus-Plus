///A program to Add Nodes To The List
#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
struct Node *head=NULL;
struct Node *tail=NULL;

void Add_Nodes_To_The_List(int data_of_the_list)
{
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data_of_the_list;
    newNode->next=NULL;
    if(head==NULL)
    {
        head=newNode;
        tail=newNode;
    }
    else
    {
        tail->next=newNode;
        tail=newNode;
    }
}
int main()
{
    Add_Nodes_To_The_List(1);
    Add_Nodes_To_The_List(2);
    Add_Nodes_To_The_List(3);
    Add_Nodes_To_The_List(4);
    return 0;
}
