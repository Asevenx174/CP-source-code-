#include<bits/stdc++.h>
using namespace std ;
const int maxx = 3005;
vector < tuple <int,int,int> > bad ;
//map < int , pair <int,int> > :: iterator it ;
vector < int > lvl(maxx),p(maxx);
vector < bool > used(maxx,false);
vector < int > g[maxx] ;
void bfs(int s)
{
    used[s]=true;
    p[s]=-1;
    lvl[s]=0;
    queue < int > q ;
    q.push(s);
    while(!q.empty())
    {
        int u = q.front(),a=0,b=0,c=0;
        q.pop();
        for(int i=0;i<g[u].size();i++)
        {
            int v = g[u][i];
            if(!used[v] && !binary_search(bad.begin(),bad.end(),make_tuple(p[u],u,v)))
            {
               used[v]=true;
               lvl[v]=lvl[u]+1;
               p[v]=u;
               q.push(v);
            }
        }
    }
}
int main()
{
    int nodes,edges,t;
    cin >> nodes >> edges >> t ;
    for(int i=0;i<edges;i++)
    {
        int u,v;
        cin >> u >> v ;
        g[u].push_back(v);
    }
    for(int i=0;i<t;i++)
    {
        int a,b,c;
        cin >> a >> b >> c ;
        bad.push_back(make_tuple(a,b,c));
    }
    sort(bad.begin(),bad.end());
    bfs(1);
    if(used[nodes])
    {
        vector < int > v ;
        while(p[nodes]!=-1)
        {
            v.push_back(nodes);
            nodes=p[nodes];
        }
        v.push_back(nodes);
        reverse(v.begin(),v.end());
        int sz = v.size();
        cout << sz << endl;
        sz--;
        for(int i=0;i<sz;i++)
        {
            cout << v[i] << " " ;
        }
        cout << v[sz] << endl;
    }
    else
    {
        cout << "-1" << endl;
    }
    return 0 ;
}
