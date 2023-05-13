#include<bits\stdc++.h>
using namespace std ;
vector < int > g[1000];
int vis[10000];
void dfs(int v )
{
    if(vis[v]!=0){return;}
    vis[v]=1;
    for(int i=0;i<g[v].size();i++)
    {
        int u = g[v][i];
        dfs(u);
    }
}
int main()
{
    int edges ;
    cin >> edges ;
    for(int i=0;i<edges;i++)
    {
        int u,v;
        cin >> v >> u ;
        g[v].push_back(u);
    }
    int s;
    cin >> s ;
    dfs(s);
    return 0 ;
}
