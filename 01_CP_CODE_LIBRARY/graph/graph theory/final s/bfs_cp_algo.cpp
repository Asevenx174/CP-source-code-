#include<bits/stdc++.h>
using namespace std ;
int main()
{
    int n,edges,s;
    cin >> n >> edges ;

    vector < int > g[n+2] ;
    queue< int > q;
    vector< bool > used(n+2,false);
    vector< int > d(n+2), p(n+2);

    for(int i=0;i<edges;i++)
    {
        int u,v;
        cin >> u >> v ;
        g[u].push_back(v);
    }

    cin >> s ;
    q.push(s);
    used[s]=true;
    d[s]=0;
    p[s]=-1;

    while(!q.empty())
    {
        int v=q.front();
        q.pop();
        for(int i=0;i<g[v].size();i++)
        {
            int u = g[v][i];
            if(!used[u])
            {
                d[u]=d[v]+1;
                p[u]=v;
                used[u]=true;
                q.push(u);
            }
        }
    }
    int e;
    cin >> e ;
    if(used[e]){cout << d[e]<<endl;}
    return 0 ;
}
