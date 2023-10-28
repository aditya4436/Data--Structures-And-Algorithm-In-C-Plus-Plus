#include<iostream>
#include<list>
using namespace std;
class Graph
{
    int V;
    list<int> *adj;
public:
    Graph(int V)
    {
        this->V=V;
        adj=new list<int>[V];
    }
    void Add_Edges(int x, int y)
    {
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int  Count_Edges()
    {
        int sum=0;
        for(int i=0;i<V;i++)
        {
            sum+=adj[i].size();
        }
        return sum/2;
    }
};
int main(void)
{
    int V=9;
    Graph g(V);
    g.Add_Edges(0, 1);
    g.Add_Edges(0, 7);
    g.Add_Edges(1, 2);
    g.Add_Edges(1, 7);
    g.Add_Edges(2, 3);
    g.Add_Edges(2, 8);
    g.Add_Edges(2, 5);
    g.Add_Edges(3, 4);
    g.Add_Edges(3, 5);
    g.Add_Edges(4, 5);
    g.Add_Edges(5, 6);
    g.Add_Edges(6, 7);
    g.Add_Edges(6, 8);
    g.Add_Edges(7, 8);
    cout<<g.Count_Edges()<<endl;
    return 0;
}
