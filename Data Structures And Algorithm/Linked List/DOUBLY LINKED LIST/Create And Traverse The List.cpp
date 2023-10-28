#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node *previous;
    Node *next;
};
struct Node *head=NULL;
struct Node *
tail=NULL;
void Add_Nodes_To_The_List()
{
    int data_of_the_list;
    cout<<"Enter the data of the list:\n";
    cin>>data_of_the_list;
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data_of_the_list;
    if(head==NULL)
    {
        head=newNode;
        tail=newNode;
        head->previous=NULL;
        head->next=NULL;
    }
    else
    {
        tail->next=newNode;
        newNode->previous=tail;
        tail=newNode;
        tail->next=NULL;
    }
}
void Traverse_The_List()
{
    struct Node *current=head;
    if(head==NULL)
    {
        cout<<"List is empty!\n";
    }
    else
    {
        while(current!=NULL)
        {
            cout<<current->data<<"  ";
            current=current->next;
        }
        cout<<"NULL";
    }
}
int main()
{
    int number_of_nodes_required, i;
    cout<<"Enter the number of nodes required:\n";
    cin>>number_of_nodes_required;
    for(i=0;i<number_of_nodes_required;i++)
    {
        Add_Nodes_To_The_List();
    }
    Traverse_The_List();
    return 0;
}
