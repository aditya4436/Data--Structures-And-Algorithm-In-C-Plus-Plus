/// Time complexity:- O(E*log(V)), here 'E' is the number of edges and 'V' is the number of vertices.
/// Space Complexity:- O(V+E), here 'E' is the number of edges and 'V' is the number of vertices.
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int parent[N], sz[N];
void make_parent(int v)
{
    parent[v]=v;
    sz[v]=1;
}
int find(int v)
{
    if(parent[v]==v)
    {
        return parent[v];
    }
    return parent[v]=find(parent[v]);
}
void Union(int a, int b)
{
    a=find(a);
    b=find(b);
    if(a!=b)
    {
        if(sz[a]<sz[b])
        {
            swap(a, b);
        }
        parent[b]=a;
        sz[a]+=sz[b];
    }
}
void Kruskal_Algorithm(vector<pair<int, pair<int, int>>> &edges, int &n)
{
    sort(edges.begin(), edges.end());
    for(int i=1; i<=n; i++)
    {
        make_parent(i);
    }
    int total_weight=0;
    cout<<"The tree is constructed from the vertices:\n";
    for(auto &edge : edges)
    {
        int weight=edge.first;
        int vertex1=edge.second.first;
        int vertex2=edge.second.second;
        if(find(vertex1)==find(vertex2))
        {
            continue;
        }
        Union(vertex1, vertex2);
        total_weight+=weight;
        cout<<vertex1<<"  "<<vertex2<<endl;
    }
    cout<<"The total weight after constructing tree from tree "<<total_weight<<"  ";
}
void Add_Edges(vector<pair<int, pair<int, int>>> &edges, int &n, int &m)
{
    for(int i=0; i<m; i++)
    {
        int vertex1, vertex2, weight;
        cout<<"Enter the first vertex:\n";
        cin>>vertex1;
        cout<<"Enter the second vertex:\n";
        cin>>vertex2;
        cout<<"Enter the weight of the edge:\n";
        cin>>weight;
        edges.push_back({weight, {vertex1, vertex2}});
    }
}
int main()
{
    int n, m;
    cout<<"Enter the number of vertex:\n";
    cin>>n;
    cout<<"Enter the number of edges:\n";
    cin>>m;
    vector<pair<int, pair<int, int>>> edges;
    Add_Edges(edges, n, m);
    Kruskal_Algorithm(edges, n);
    return 0;
}
