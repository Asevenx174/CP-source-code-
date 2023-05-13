#include<bits\stdc++.h>
using namespace std ;
const int N = 1e5+5 ;
const int inf = 1<<30;
vector < int > g[N],c[N];
int nodes,edges;
void bellford()
{
    int dis[nodes+2];
    for(int i=1;i<=nodes;i++){dis[i]=inf;}
    dis[1]=0;
    for(int i=1;i<nodes;i++)
    {
        for(int j=1;j<=nodes;j++)
        {
            int u=j;
            for(int k=0;k<g[j].size();k++)
            {
                int v = g[u][k],uv=c[u][k];
                if(dis[u]+uv<dis[v]){dis[v]=dis[u]+uv;}
            }
        }
    }

     for(int j=1;j<=nodes;j++)
        {
            int u=j;
            for(int k=0;k<g[j].size();k++)
            {
                int v = g[u][k],uv=c[u][k];
                if(dis[u]+uv<dis[v]){cout << "neg cycle" << endl;return;}
            }
        }
    for(int i=2;i<=nodes;i++)
    {
        cout << "1" << " " << i << " -> " << dis[i] << endl;
    }
}
int main()
{
    cin >> nodes >> edges ;
    for(int i=0;i<edges;i++)
    {
        int u,v,w;
        cin >> u >> v >> w ;
        g[u].push_back(v);
        c[u].push_back(w);
    }
    bellford();
    return 0;
}
