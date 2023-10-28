#include<iostream>
using namespace std;
class Graph
{
    int n;
    int g[10][10];
public:
    Graph(int x)
    {
        n=x;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                g[i][j]=0;
            }
        }
    }
    void Display_Adjacency_Matrix()
    {
        for(int i=0;i<n;i++)
        {
            cout<<endl;
            for(int j=0;j<n;j++)
            {
                cout<<g[i][j]<<"  ";
            }
        }
    }
    void Add_Edge(int x, int y)
    {
        if((x>=n)||y>n)
        {
            cout<<"Vertex does not exists.\n";
        }
        if(x==y)
        {
            cout<<"Same vertex.\n";
        }
        else
        {
            g[y][x]=1;
            g[x][y]=1;
        }
    }
    void Add_Vertex()
    {
        n++;
        int i;
        for(i=0;i<n;i++)
        {
            g[i][n-1]=0;
            g[n-1][i]=0;
        }
    }
    void Remove_Vertex(int x)
    {
        if(x>n)
        {
            cout<<"Vertex not present.\n";
            return;
        }
        else
        {
            int i;
            while(x<n)
            {
                for(i=0;i<n;i++)
                {
                    g[i][x]=g[i][x+1];
                }
                for(i=0;i<n;i++)
                {
                    g[x][i]=g[x+1][i];
                }
                x++;
            }
            n--;
        }
    }
};
int main()
{
    Graph obj(4);
    obj.Add_Edge(0, 1);
    obj.Add_Edge(0, 2);
    obj.Add_Edge(1, 2);
    obj.Add_Edge(2, 3);
    cout<<"Adjacency Matrix representation of Graph:";
    obj.Display_Adjacency_Matrix();
    obj.Add_Vertex();
    obj.Add_Edge(4, 1);
    obj.Add_Edge(4, 3);
    cout<<"\n\nAdjacency Matrix representation of Graph after inserting an edges and a vertex:";
    obj.Display_Adjacency_Matrix();
    obj.Remove_Vertex(1);
    cout<<"\n\nAdjacency Matrix representation of Graph after removing a vertex:";
    obj.Display_Adjacency_Matrix();
    return 0;
}
