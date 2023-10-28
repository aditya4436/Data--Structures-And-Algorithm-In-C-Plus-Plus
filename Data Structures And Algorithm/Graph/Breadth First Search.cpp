/// Time Complexity:- O(V+E), here 'V' is the number of vertex that has been traversed and
                  /// 'E' is the number of edges that has been traversed.
/// Space Complexity:- O(V), here 'V' is the number of vertices that have occupied the space or memory.
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int N=1e5+10;
vector<int> g[N];
bool visited[N];
int level[N];
void Breadth_First_Search(int vertex)
{
    queue<int> q;
    q.push(vertex);
    visited[vertex]=true;
    while(!q.empty())
    {
        int current_vertex=q.front();
        q.pop();
        cout<<current_vertex<<"  ";
        for(int child: g[current_vertex])
        {
            if(!visited[child])
            {
                q.push(child);
                visited[child]=true;
                level[child]=level[current_vertex]+1;
            }
        }
    }
}
void Add_Edges(int x, int y)
{
    g[x].push_back(y);
    g[y].push_back(x);
}
int main()
{
    Add_Edges(0, 1);
    Add_Edges(0, 2);
    Add_Edges(1, 2);
    Add_Edges(2, 0);
    Add_Edges(2, 3);
    Add_Edges(3, 3);
    cout<<"Following is Breadth First Traversal (starting from vertex 2):\n";
    Breadth_First_Search(2);
}
/// Takes input from the user.
/*int main()
{
    int nodes;
    cout<<"Enter the number of nodes:\n";
    cin>>nodes;
    for(int i=0;i<nodes-1;i++)
    {
        int x, y;
        cout<<"Enter the first vertex:\n";
        cin>>x;
        cout<<"Enter the second vertex:\n";
        cin>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    Breadth_First_Search(1);
    for(int i=1; i<=nodes; i++)
    {
        cout<<"\n"<<i<<": "<<level[i]<<endl; //It prints the level of the nodes or vertices.
    }
}*/
