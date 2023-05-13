#include<bits\stdc++.h>
#define inf 1 << 30
using namespace std ;
int nodes,edges;
vector < int > per(1005);
vector <  pair < int,int > >  g[1005] ;
bool bellford()
{
    per[1]=0;
    vector < int > dis (nodes+1,inf);
    vector < bool > relaxed(nodes+1,false);
    vector < int > cnt(nodes+1,0);
    dis[1]=0;
    queue < int > q ;
    q.push(1);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        relaxed[u]=false;
        for(int k=0;k<g[u].size();k++)
        {
            int v = g[u][k].first;
            int w = g[u][k].second;
            if(dis[u]+w<dis[v])
            {
                dis[v]=dis[u]+w;
                per[v]=u;
                if(!relaxed[v])
                {
                    q.push(v);
                    relaxed[v]=true;
                    cnt[v]++;
                    if(cnt[v]>=nodes){return false;}///not sure cnt[v]>nodes
                }
            }
        }
    }
    return true;
}
void pri(int x)
{
    if(x>0)
    {
        pri(per[x]);
        cout  << x  << " " ;
    }
}
int main()
{
    cin >> nodes >> edges ;
    for(int i=0;i<edges;i++)
    {
        int u,v,w;
        cin >> u >> v >> w ;
        g[u].push_back(make_pair(v,w));
    }
    if(!bellford())
    {
        cout << "Negative cycle" << endl;
    }
    else
    {
       pri(nodes);
    }
    return 0 ;
}
