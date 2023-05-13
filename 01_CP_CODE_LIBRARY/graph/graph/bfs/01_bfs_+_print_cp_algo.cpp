#include<bits/stdc++.h>
using namespace std ;
const int maxx = 1e5+5;
int nodes,edges ;
vector < vector <int> > adj ;
vector < int > p(maxx),d(maxx);
vector < bool > used(maxx,false);
void bfs(int str)
{
    queue < int > q ;
    q.push(str);
    used[str]=true;
    p[str]=-1;
    d[str]=0;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int v : adj[u])
        {
           if(used[v]==false)
           {
               used[v]=true;
               d[v]=d[u]+1;
               q.push(v);
               p[v]=u;
           }
        }
    }
}
void pripath(int u)
{
    if(used[u]==false){cout << "NO PATH" << endl;}
    else
    {
        vector < int > path ;
        do
        {
            path.push_back(u);
            u=p[u];
        }
        while(u!=-1);
        reverse(path.begin(),path.end());
        for(auto it = path.begin();it!=path.end();it++)
        {
            cout << *it << " " ;
        }
        cout << endl;
    }
}
int main()
{
    cin >> nodes >> edges ;
    for(int i=1;i<=edges;i++)
    {
        int u,v;
        cin >> u >> v ;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int str;
    cin >> str ;
    bfs(str);
    cin >> str ;
    pripath(str);
    return 0 ;
}
