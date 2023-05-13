#include<bits/stdc++.h>
#define pii   pair < int ,int >
#define pb(a)             push_back(a)
#define mp(a,b)           make_pair(a,b)
#define pf printf
#define ff first
#define ss second
#define sef second.first
#define ses second.second
#define sii(a,b)           scanf("%d %d",&a,&b)
#define EulerGamma 0.57721566490153286060651209;/// when n>1e6  nth harmonic num = log(x+.5)+EulerGamma;
using namespace std ;
typedef long long ll ;
const int maxx = 1010 ;
vector < pair < int , pii > > g , ans  ;
int par[maxx+10],siz[maxx+10];
void set_value(int x)
{
    par[x]=x;
    siz[x]=1;
}
int sendroot(int x)
{
    if(x==par[x]){return x ; }
    par[x]=sendroot(par[x]);
}
void add(int a,int b)
{
    int p1 = sendroot(a);
    int p2 = sendroot(b);
    if(p1!=p2)
    {
        if(siz[a]<siz[b]){swap(a,b);}
        par[b]=a;
        siz[a]+=siz[b];
    }
}
int main()
{
    ifstream obj ;
    obj.open("kgraph.txt");
    int n ;
    obj >> n ;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int w ;
            obj >> w ;
            g.push_back({w,{i,j}});
        }
    }
    sort(g.begin(),g.end());
    for(auto it : g )
    {
        int w = it.ff , u = it.sef , v = it.ses ;
        if(sendroot(u)!=sendroot(v))
        {
            add(u,v);
            ans.push_back({w,{u,v}});
        }
    }
    cout << "the edges of minimum spanning tree - > " << endl;
    int f=1;
    for(auto it : ans )
    {
        cout << f << " edge " << "( " << it.sef << " " << it.ses  << " ) = " << it.ff << endl;
        f++;
    }
    return 0 ;
}
