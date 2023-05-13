#include<bits/stdc++.h>
using namespace std ;
vector < int > g[1000] ;
vector < int > in(1000),out(1000),color(1000,0);
int dfs_timer=0;
void dfs(int v)
{
    in[v]=++dfs_timer;
    color[v]=1;
    for(int i=0;i<g[v].size();i++)
    {
        int u=g[v][i];
        if(color[u]==0)
        {
            dfs(u);
        }
    }
    out[v]=++dfs_timer;
    color[v]=2;
    return ;
}
int main()
{
   int nodes,edges;
   cin >> edges >> nodes ;

   for(int i=0;i<edges;i++)
   {
       int u,v;
       cin >> u >> v ;
       g[u].push_back(v);
   }

   int s ;
   cin >> s ;
   dfs(s);
   cout << in[1] << " " << out[1] << " " << color[1] << endl;
   return 0 ;
}
