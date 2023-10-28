///A program to Traverse The Given List
#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
struct Node *head=NULL;
struct Node *tail=NULL;
void Add_Nodes_To_The_List(int data)
{
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
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
void Traverse_The_List()
{
    struct Node *current;
    if(head==NULL)
    {
        cout<<"List is empty.\n";
    }
    else
    {
        current=head;
        while(current!=NULL)
        {
            cout<<current->data<<"  ";
            current=current->next;
        }
    }
}
int main()
{
    Add_Nodes_To_The_List(1);
    Add_Nodes_To_The_List(2);
    Add_Nodes_To_The_List(3);
    Traverse_The_List();
    return 0;
}

