#include<bits\stdc++.h>
#define inf 1<<30;
using namespace std ;
int nodes,edges,source ;
struct node
{
    int uu ;
    int cost ;
    node(int a,int b){uu=a;cost=b;}
    bool operator < (const node& p)const
    {
        return cost>p.cost;
    }
};
void dijstkra(vector<int>g[],vector < int > c[])
{
    int dis[nodes+1];
    for(int i=1;i<=nodes;i++){dis[i]=inf;}
    dis[source]=0;
    priority_queue < node > q ;
    q.push(node(source,0));
    while(!q.empty())
    {
       node top = q.top();
       q.pop();
       int u = top.uu;
       for(int i=0;i<(int)g[u].size();i++)
       {
           int v = g[u][i];
           if(dis[u]+c[u][i]<dis[v])
           {
               dis[v]=dis[u]+c[u][i];
               q.push(node(v,dis[v]));
           }
       }
    }
     for(int i=1;i<=nodes;i++)
    {
        cout << source << " " << dis[i]  << endl;
    }
}
int main()
{
    vector < int > g[10000],c[10000];
    cin >> nodes >> edges ;
    for(int i=0;i<edges;i++)
    {
        int u,v,w;
        cin >> u >> v >> w ;
        g[u].push_back(v);
        g[v].push_back(u);
        c[u].push_back(w);
        c[v].push_back(w);
    }
    cin >> source ;
    dijstkra(g,c);
    return 0;
}
/*
4 4
1 2 2
2 3 1
1 3 5
3 4 3
1
*/
