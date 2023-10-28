/// Time Complexity: O(E*log(E)) where 'E' is the number of edges
/// Auxiliary Space: O(V^2) where 'V' is the number of vertex.
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
// The typedef is a keyword that is used to provide existing 
// data types with a new name. The C typedef keyword is used
// to redefine the name of already existing data types.
int Minimum_Spanning_Tree(int V, int E, int edges[][3])
{ 
	vector<vector<int>> adj[V];
	for (int i=0; i<E; i++)
    {
		int u=edges[i][0];
		int v=edges[i][1];
		int wt=edges[i][2];
		adj[u].push_back({v, wt});
		adj[v].push_back({u, wt});
	}
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	vector<bool> visited(V, false);
	int res=0;
	pq.push({0, 0});
	while(!pq.empty())
    {
		auto p=pq.top();
		pq.pop();	
		int wt=p.first;
		int u=p.second;	
		if(visited[u]==true)
        {
			continue;
		}	
		res+=wt;
		visited[u]=true;
		for(auto v : adj[u])
        {
			if(visited[v[0]]==false)
			{
				pq.push({v[1], v[0]});
			}
		}
	}	
	return res;
}
int main()
{
	int graph[][3] = {{0, 1, 5},
					{1, 2, 3},
					{0, 2, 1}};
	cout<<"The sum of edge weights of the Minimum Spanning Tree:\n"<<Minimum_Spanning_Tree(3, 3, graph)<<endl;
	return 0;
}
