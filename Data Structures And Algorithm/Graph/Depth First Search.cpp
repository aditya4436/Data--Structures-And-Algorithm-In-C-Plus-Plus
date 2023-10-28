/// Time Complexity:- O(V+E), here 'V' is the number of vertex that has been traversed and
                  /// 'E' is the number of edges that has been traversed.
/// Space Complexity:- O(V), here 'V' is the number of vertices that have occupied the space or memory.
#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<int> g[N];
bool visited[N];
void Add_Edges(int x, int y)
{
    g[x].push_back(y);
    g[y].push_back(x);
}
void Depth_First_Search(int vertex)
{
    visited[vertex]=true;
    cout<<vertex<<"  ";
    vector<int>:: iterator i;
    for(i=g[vertex].begin(); i!=g[vertex].end(); i++)
    {
        if(visited[*i])
        {
            continue;
        }
        Depth_First_Search(*i);
    }
}
void Iterative_Depth_First_Search(int vertex)
{
    vector<bool> visited(N, false);
    stack<int> st;
    st.push(vertex);
    while(!st.empty())
    {
        int s=st.top();
        st.pop();
        if(!visited[s])
        {
            cout<<s<<"  ";
            visited[s]=true;
        }
        for(auto i=g[s].begin(); i!=g[s].end(); i++)
        {
            if(!visited[*i])
            {
                st.push(*i);
            }
        }
    }
}
int main()
{
    Add_Edges(0, 1);
    Add_Edges(0, 2);
    Add_Edges(1, 2);
    Add_Edges(2, 0);
    Add_Edges(2, 3);
    Add_Edges(3, 3);
    cout<<"Following is Depth First Traversal (starting from vertex 1):\n";
    Depth_First_Search(1);
    cout<<endl;
    Iterative_Depth_First_Search(1);
    return 0;
}

/// Take input from the user.
/*int main()
{
    int vertex, edges;
    cout<<"Enter the number of vertex:\n";
    cin>>vertex;
    cout<<"Enter the number of edges:\n";
    cin>>edges;
    for(int i=0;i<vertex;i++)
    {
        int vertex1, vertex2;
        cout<<"Enter vertex 1:\n";
        cin>>vertex1;
        cout<<"Enter vertex 2:\n";
        cin>>vertex2;
        g[vertex1].push_back(vertex2);
        g[vertex2].push_back(vertex1);
    }
    Depth_First_Search(2);
    return 0;
}*/
