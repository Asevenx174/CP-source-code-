#include<bits\stdc++.h>
using namespace std ;
int d[1000],f[1000],color[1000],dfs_time=0;
void dfs(vector < int > g[],int u)
{
   d[u]=++dfs_time;
   color[u]=1;
   for(int i=0;i<g[u].size();i++)
   {
       int v = g[u][i];
       if(color[v]==0)
       {
           dfs(g,v);
       }
   }
   color[u]=2;
   f[u]=++dfs_time;
   return ;
}
int main()
{
    vector < int > g[1000] ;
    int s,edges;
    cin >>  edges ;
    for(int i=0;i<edges;i++)
    {
        int u,v;
        cin >> u >> v ;
        g[u].push_back(v);
    }
    cin >> s ;
    dfs(g,s);
    return 0;
}
