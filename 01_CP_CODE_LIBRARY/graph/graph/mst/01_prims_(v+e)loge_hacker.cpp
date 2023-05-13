#include<iostream>
#include<vector>
#include<utility>
#include<queue>
#define ff first
#define ss second
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
using namespace std ;
const int maxx = 1e4+5;
typedef pair <int,int> pii ;
vector < pii > adj[maxx] ;
vector < bool > used(maxx+5,false);
int prims()
{
    priority_queue < pii , vector <pii> , greater<pii> > q ;
    q.push({0,1});
    int cost = 0 ;
    while(!q.empty())
    {
       pii p = q.top();
       int w = p.ff , v = p.ss ;
       if(used[v]){continue;}
       cost+=w;
       used[v]=true;
       for(int j=0;j<adj[v].size();j++)
       {
           pii x = adj[v][j];
           if(!used[x.ss])
           {
               q.push(x);
           }
       }
    }
    return cost ;
}
int main()
{
    int nodes ,edges ;
    cin >> nodes >> edges ;
    for(int i=1;i<=edges;i++)
    {
        int u,v,w;
        cin >> u >> v >> w ;
        adj[u].pb(mp(w,v));
        adj[v].pb(mp(w,u));
    }
    int mincost = prims();
    return 0 ;
}
