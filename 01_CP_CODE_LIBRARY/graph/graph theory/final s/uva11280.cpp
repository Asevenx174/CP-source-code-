#include<bits\stdc++.h>
#define inf 1<<30
using namespace std ;
const int N = 1005 ;
map < string , int > m;
vector < int > g[N],c[N];
int plen,dis[N],nodes,edges,path[N],lvl[N];
void bellford()
{
    for(int i=1;i<=nodes;i++){dis[i]=inf;path[i]=inf;}
    dis[1]=0;
    for(int i=1;i<nodes;i++)
    {
        for(int j=1;j<=nodes;j++)
        {
            int u=j;
            for(int k=0;g[u].size();k++)
            {
               int v = g[u][k];
               int cost = c[u][k];
               if(dis[u]+cost<dis[v])
               {
                   dis[v]=dis[u]+cost;
               }
            }
        }
    }
}
int main()
{
    int t ;
    cin >> t ;
    for(int p=1;p<=t;p++)
    {
        cin >> nodes;
        for(int i=1;i<=nodes;i++)
        {
            g[i].clear();
            c[i].clear();
            string s ;
            cin >> s ;
            m[s]=i;
        }
        cin >> edges;
        for(int i=1;i<=edges;i++)
        {
          string uu,vv;
          int w,u,v;
          cin >> uu >> vv >> w ;
          u=m[uu];
          v=m[vv];
          g[u].push_back(v);
          c[u].push_back(w);
        }
        while(cin >> plen)
        {
            if(plen==0){break;}
            else
            {
                bellford();
            }
        }
    }
}
