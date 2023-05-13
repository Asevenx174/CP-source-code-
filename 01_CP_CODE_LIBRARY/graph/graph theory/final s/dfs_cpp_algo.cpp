#include<bits\stdc++.h>
using namespace std ;
int dfs_timer=0;
vector < int > g[1000] ;
vector < int > in,out;
int color[10000];
void dfs(int v)
{
    in[v]=++dfs_timer;
    color[v]=1;
    for(int i=0;i<g[v].size();i++)
    {
        int u = g[v][i];
        if(color[u]==0)
        {
            dfs(u);
        }
    }
    color[v]=2;
    out[v]=++dfs_timer;
}
int main()
{
    int edges,nodes,st_node;
    cin >> edges >> nodes;
    for(int i=0;i<edges;i++)
    {
        int u,v;
        cin >> v >> u ;
        g[v].push_back(u);
    }
    cin >> st_node ;
    dfs(st_node);
    for(int i=1;i<=nodes;i++)
    {
        cout << "i -> " << in[i] << " " << out[i] << endl;
    }
    return 0 ;
}
