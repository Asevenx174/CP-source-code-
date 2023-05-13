#include<iostream>
#include<cstring>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std ;
vector < int > g[105],in(105),out(105);
vector < pair < int,int > > p;
bool used[105];
bool com(const pair <int,int> &a,const pair <int,int> &b)
{
    return a.second>b.second;
}
int timek=0;
void dfs(int u)
{
    in[u]=++timek;
    for(int i=0;i<g[u].size();i++)
    {
        int v = g[u][i];
        if(used[v]==false)
        {dfs(v);}
    }
    out[u]=++timek;
    p.push_back(make_pair(u,out[u]));
    used[u]=true;
    return  ;
}
int main()
{
    int u,v,n,m;
    while(cin >> n >> m)
     {
        for(int i=0;i<103;i++)
        {
            g[i].clear();
        }
        p.clear();
        timek=0;
        memset(used,false,sizeof(used));
        if(n==m && n==0){return 0;}
        for(int i=0;i<m;i++)
        {
            int u,v;
            cin >> u >> v;
            g[u].push_back(v);
        }
        for(int i=1;i<=n;i++)
        {
            if(used[i]==true){continue;}
            dfs(i);
        }
        sort(p.begin(),p.end(),com);
        for(int i=0;i<n;i++)
        {
            cout << p[i].first ;
            if(i<n-1){cout << " ";}
        }
        cout << endl;
    }
    return 0 ;
}
