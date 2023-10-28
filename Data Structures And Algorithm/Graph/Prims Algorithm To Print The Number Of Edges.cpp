#include<bits/stdc++.h>
using namespace std;
# define INF 0x3f3f3f3f
typedef pair<int, int> iPair;
class Graph
{
	int V;
	list< pair<int, int> > *adj;
public:
	Graph(int V);
	void Add_Edges(int u, int v, int w);
	void Prims_Minimum_Spanning_Tree();
};
Graph::Graph(int V)
{
	this->V=V;
	adj=new list<iPair> [V];
}
void Graph::Add_Edges(int u, int v, int w)
{
	adj[u].push_back(make_pair(v, w));
	adj[v].push_back(make_pair(u, w));
}
void Graph::Prims_Minimum_Spanning_Tree()
{
	priority_queue<iPair, vector <iPair> , greater<iPair>> pq;
	int src=0;
	vector<int> key(V, INF);
	vector<int> parent(V, -1);
	vector<bool> visited(V, false);
	pq.push(make_pair(0, src));
	key[src]=0;
	while (!pq.empty())
	{
		int u=pq.top().second;
		pq.pop();
		if(visited[u]==true)
        {
			continue;
		}
		visited[u]=true;
		list<pair<int, int>>::iterator i;
		for (i=adj[u].begin(); i!=adj[u].end(); ++i)
		{
			int v=(*i).first;
			int weight=(*i).second;
			if (visited[v]==false && key[v]>weight)
			{
				key[v]=weight;
				pq.push(make_pair(key[v], v));
				parent[v]=u;
			}
		}
	}
    cout<<"The tree constructed from the edges:\n";
	for (int i=1; i<V; ++i)
    {
        cout<<parent[i]<<"--"<<i<<endl;
    }
}
int main()
{
	int V = 9;
	Graph g(V);
	g.Add_Edges(0, 1, 4);
	g.Add_Edges(0, 7, 8);
	g.Add_Edges(1, 2, 8);
	g.Add_Edges(1, 7, 11);
	g.Add_Edges(2, 3, 7);
	g.Add_Edges(2, 8, 2);
	g.Add_Edges(2, 5, 4);
	g.Add_Edges(3, 4, 9);
	g.Add_Edges(3, 5, 14);
	g.Add_Edges(4, 5, 10);
	g.Add_Edges(5, 6, 2);
	g.Add_Edges(6, 7, 1);
	g.Add_Edges(6, 8, 6);
	g.Add_Edges(7, 8, 7);
	g.Prims_Minimum_Spanning_Tree();
	return 0;
}
