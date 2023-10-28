/// Time complexity:- O(E*log(V)), here 'E' is the number of edges and 'V' is the number of vertices.
/// Space Complexity:- O(V+E), here 'E' is the number of edges and 'V' is the number of vertices.
#include<bits/stdc++.h>
using namespace std;
class Disjoint_Set_Union
{
    int *parent, *rank;
public:
    Disjoint_Set_Union(int n)
    {
        parent=new int[n];
        rank=new int[n];
        for(int i=0;i<=n;i++)
        {
            parent[i]=i;
            rank[i]=1;
        }
    }
    int Find(int i)
    {
        if(i==parent[i])
        {
            return i;
        }
        return parent[i]=Find(parent[i]);
    }
    void Union(int x, int y)
    {
        int s1=Find(x);
        int s2=Find(y);
        if(s1!=s2)
        {
            if(rank[s1]<rank[s2])
            {
                parent[s1]=s2;
            }
            else if(rank[s1]>rank[s2])
            {
                parent[s2]=s1;
            }
            else
            {
                parent[s2]=s1;
                rank[s1]+=1;
            }
        }
    }
    void Belongs_To_Same_Component(int x, int y)
    {
        if(Find(x)==Find(y))
        {
            cout<<x<<" and "<<y<<" belongs to the same component.\n";
        }
        else
        {
            cout<<x<<" and "<<y<<" does not belongs to the same component.\n";
        }
    }
};
class Graph
{
    vector<vector<int>> edgelist;
    int V;
public:
    Graph(int V)
    {
        this->V=V;
    }
    void Add_Edges(int x, int y, int w)
    {
        edgelist.push_back({w, x, y});
    }
    void Kruskal_Algorithm_MST()
    {
        Disjoint_Set_Union s(V);
        sort(edgelist.begin(), edgelist.end());
        int total_cost=0;
        cout<<"The tree is constructed from the vertices:\n";
        for(auto &edge : edgelist)
        {
            int weight=edge[0];
            int vertex1=edge[1];
            int vertex2=edge[2];
            if(s.Find(vertex1)==s.Find(vertex2))
            {
                continue;
            }
            s.Union(vertex1, vertex2);
            total_cost+=weight;
            cout<<vertex1<<" -- "<<vertex2<<" == "<<weight<<endl;
        }
        cout<<"Minimum Cost Spanning Tree: "<<total_cost<<endl;
    }
};
int main()
{
    Graph g(4);
    g.Add_Edges(0, 1, 10);
    g.Add_Edges(1, 3, 15);
    g.Add_Edges(2, 3, 4);
    g.Add_Edges(2, 0, 6);
    g.Add_Edges(0, 3, 5);
    g.Kruskal_Algorithm_MST();
    Disjoint_Set_Union ds(7);
    ds.Union(1, 2);
    ds.Union(2, 3);
    ds.Union(4, 5);
    ds.Union(6, 7);
    ds.Union(5, 6);
    /// Here we are checking if 3 and 7 belongs to the same component.
    /// We can do these for any given node or vertexes.
    ds.Union(3, 7);
    ds.Belongs_To_Same_Component(3, 7);
    return 0;
}
