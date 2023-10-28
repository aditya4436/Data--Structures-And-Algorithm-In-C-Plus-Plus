///A program to search an existing node in the list
#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
struct Node *head=NULL;
struct Node *tail=NULL;
void Add_Nodes_To_The_List()
{
    int data_of_the_list;
    cout<<"Enter the data of the list:\n";
    cin>>data_of_the_list;
    struct Node *newNode=new Node;
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
        cout<<"NULL.";
    }
}
int Search_An_Existing_Node()
{
    struct Node *temp=head;
    int i=0, data_to_be_searched, flag;
    if(temp==NULL)
    {
        cout<<"List is empty!\n";
    }
    else
    {
        cout<<"Enter the data to search its position:\n";
        cin>>data_to_be_searched;
        while(temp!=NULL)
        {
            if(temp->data==data_to_be_searched)
            {
                cout<<"Data or node found at "<<i+1<<" position.\n";
                return 0;
            }
            else
            {
                flag=1;
            }
            i++;
            temp=temp->next;
        }
        if(flag==1)
        {
            cout<<"Data not found.\n";
        }
    }
    return 0;
}
int main()
{
    int number_of_nodes_required, i;
    cout<<"Enter the number of modes required:\n";
    cin>>number_of_nodes_required;
    for(i=0;i<number_of_nodes_required;i++)
    {
        Add_Nodes_To_The_List();
    }
    Traverse_The_List();
    Search_An_Existing_Node();
    return 0;
}
