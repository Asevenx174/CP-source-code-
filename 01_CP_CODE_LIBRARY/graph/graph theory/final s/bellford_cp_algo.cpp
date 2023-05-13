#include<bits\stdc++.h>
using namespace std ;
const int  inf  = 1e9;
int nodes,edges;
struct edge
{
    int a,b,c;
    edge(int x,int y,int z)
    {
        a=x;
        b=y;
        c=z;
    }
};
vector < edge > g;
void bellford()
{
    vector < int > dis (nodes+1,inf) ;
    vector < int > per (nodes);
    dis[1]=0;
    per[1]=-1;
    for(int i=1;i<nodes;i++)
    {
        bool f = true ;
        for(int j=0;j<edges;j++)
        {
            int u = g[j].a , v = g[j].b , w = g[j].c ;
            if(dis[u]+w<dis[v])
            {
                per[v]=u;
                dis[v]=dis[u]+w;
                f=false;
            }
        }
        if(f==true){break;}
    }
    /*for(int i=1;i<=nodes;i++)
    {
        cout << i << " " << dis[i] << endl;
    }*/
    if(dis[nodes]==inf)
    {
        cout << "No path" << endl;
    }
    else
    {
        vector < int > path ;
        do
        {
            path.push_back(nodes);
            nodes=per[nodes];
        }
        while(nodes!=-1);
        reverse(path.begin(),path.end());
        for(int i=0;i<path.size();i++)
        {
            cout << path[i] << " " ;
        }
        cout << endl;
    }
}
int main()
{
    cin >> nodes >> edges ;
    for(int i=0;i<edges;i++)
    {
        int u,v,w;
        cin >> u >> v >> w ;
        g.push_back(edge(u,v,w));
    }
    bellford();
    return 0;
}
