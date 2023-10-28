///A program to delete the the first node or the first data from the list
#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node(int data)
    {
        this->data=data;
        next=NULL;
    }
};
struct Node *head=NULL;
struct Node *tail=NULL;
void Add_Nodes_To_The_List()
{
    int data_of_the_list;
    cout<<"Enter the data of the list:\n";
    cin>>data_of_the_list;
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
void Traverse_The_List()
{
    Node *current=head;
    if(head==NULL)
    {
        cout<<"List is empty...\n";
    }
    else
    {
        while(current!=NULL)
        {
            cout<<current->data<<"   ";
            current=current->next;
        }
    }
}
void Delete_The_First_Node()
{
    Node *temp=head;
    if(head==NULL)
    {
        cout<<"List is empty...\n";
    }
    else
    {
        head=head->next;
        free(temp);
        temp=NULL;
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
    cout<<"The list before deleting an element or data from the beginning of the list:\n";
    Traverse_The_List();
    cout<<endl;
    Delete_The_First_Node();
    cout<<"The list after deleting an element or data from the beginning of the list:\n";
    Traverse_The_List();
    return 0;
}
