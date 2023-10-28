#include<bits/stdc++.h>
using namespace std;
class Graph
{
    int V;
    list<int> *adj;
    void Topological_Sort_Utility(int v, bool visited[], stack<int> &st);
public:
    Graph(int V);
    void Add_Edge(int x, int y);
    void Topological_Sort();
};
Graph::Graph(int V)
{
    this->V=V;
    adj=new list<int>[V];
}
void Graph::Add_Edge(int v, int w)
{
    adj[v].push_back(w);
}
void Graph::Topological_Sort_Utility(int v, bool visited[], stack<int> &st)
{
    visited[v]=true;
    list<int>:: iterator i;
    for(i=adj[v].begin(); i!=adj[v].end(); i++)
    {
        if(!visited[*i])
        {
            Topological_Sort_Utility(*i, visited, st);
        }
    }
    st.push(v);
}
void Graph::Topological_Sort()
{
    stack<int> st;
    bool *visited=new bool[V];
    for(int i=0; i<V; i++)
    {
        visited[i]=false;
    }
    for(int i=0; i<V; i++)
    {
        if(visited[i]==false)
        {
            Topological_Sort_Utility(i, visited, st);
        }
    }
    while(!st.empty())
    {
        cout<<st.top()<<"  ";
        st.pop();
    }
    delete[] visited;
}
int main()
{
    Graph g(6);
    g.Add_Edge(5, 2);
    g.Add_Edge(5, 0);
    g.Add_Edge(4, 0);
    g.Add_Edge(4, 1);
    g.Add_Edge(2, 3);
    g.Add_Edge(3, 1);
    cout<<"Following is the output of Topological Sort:\n";
    g.Topological_Sort();
    return 0;
}
