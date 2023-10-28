#include<iostream>
#include<vector>
using namespace std;
void Add_Edges(vector<int> adj[], int x, int y)
{
    adj[x].push_back(y);
    adj[y].push_back(x);
}
void Delete_Edges(vector<int> adj[], int x, int y)
{
    for(int i=0;i<adj[x].size();i++)
    {
        if(adj[x][i]==y)
        {
            adj[x].erase(adj[x].begin()+i);
            break;
        }
    }
    for(int i=0;i<adj[y].size();i++)
    {
        if(adj[y][i]==x)
        {
            adj[y].erase(adj[y].begin()+i);
            break;
        }
    }
}
void Print_Adjacency_List(vector<int> adj[], int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<"Vertex "<<i<<"  ";
        for(auto x:adj[i])
        {
            cout<<"->"<<x;
        }
        cout<<endl;
    }
}
int main()
{
    int size=5;
    vector<int> adj[size];
    Add_Edges(adj, 0, 1);
    Add_Edges(adj, 0, 4);
    Add_Edges(adj, 1, 2);
    Add_Edges(adj, 1, 3);
    Add_Edges(adj, 1, 4);
    Add_Edges(adj, 2, 3);
    Add_Edges(adj, 3, 4);
    Print_Adjacency_List(adj, size);
    Delete_Edges(adj, 1, 4);
    cout<<endl;
    Print_Adjacency_List(adj, size);
    return 0;
}

