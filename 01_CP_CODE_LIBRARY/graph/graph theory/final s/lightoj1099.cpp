#include<iostream>
#include<utility>
#include<vector>
#include<queue>
#define  ff first
#define  ss second
#define mp make_pair
using namespace std ;
typedef pair< long long, int> pii;
typedef long long ll ;
const int N = 1e5+5;
const ll inf = 1e15;
int nodes,edges;
vector < int > g[N];
vector < ll > c[N];
ll d[N][2];
bool bck[N];
bool vis[N];
ll min_b[N];
void dijkstra()
{
    for(int i=1;i<=nodes;i++)
    {
        d[i][0]=inf;d[i][1]=inf;
        vis[i]=false;
        bck[i]=false;
        min_b[i]=inf;
        for(int j=0;j<(int)c[i].size();j++)
        {
            ll w = c[i][j];
            w+=w;
            min_b[i]=min_b[i]> w ? w : min_b[i] ;
        }
    }
    priority_queue < pii > q ;
    q.push(mp(0,1));
    d[1][0]=0;
    while(!q.empty())
    {
        pii top = q.top();
        q.pop();
        int u = top.ss ; ll w = -top.ff ;

        if(vis[u])
        {
            d[u][1]=d[u][1]> w ? w : d[u][1] ;
        }
        vis[u]=true;
        for(int i=0;i<(int)g[u].size();i++)
        {
            int v = g[u][i];
            ll uv = c[u][i],tcost;
            tcost=w+uv;
            if(tcost<d[v][0])
            {
                d[v][0]=tcost;
                q.push(mp(-tcost,v));
            }
            else if (tcost<d[v][1] && tcost!=d[v][0])
            {
                d[v][1]=tcost;
                q.push(mp(-tcost,v));
            }
        }
        if(!bck[u])
        {
           q.push(mp(-(w+min_b[u]),u));
           bck[u]=true;
        }
    }
}
int main()
{
    int t ;
    cin >> t ;
    for(int k=1;k<=t;k++)
    {
        cin >> nodes >> edges ;
        for(int j=1; j<=nodes; ++j) {g[j].clear(), c[j].clear();}
    for(int i=0;i<edges;i++)
    {
        int u,v;
        ll w ;
        cin >> u >> v >> w ;
        g[u].push_back(v);
        g[v].push_back(w);
        c[u].push_back(w);
        c[v].push_back(w);
    }
    dijkstra();
    cout << "Case " << k << ": " << d[nodes][1] << endl;
    }
    return 0;
}

