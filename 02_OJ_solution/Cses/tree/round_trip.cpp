#include<bits/stdc++.h>
#define pb           push_back
#define mp           make_pair
#define pf printf
#define ff first
#define ss second
#define sef second.first
#define ses second.second
#define PI 3.14159265 /// tan inverse = atan(value)*(180/PI)

#define ms(a,b)            memset(a, b, sizeof(a))
#define lp(i,a,b) for (int i = a; i <= b; i++)
#define pii                pair <int,int>

#define SL(a)              scanf("%I64d",&a)
#define SLL(a,b)           scanf("%I64d %I64d",&a,&b)
#define PL(x) printf("%I64d\n",(x))
#define PLL(x,y) printf("%I64d %I64d\n",x,y)

#define S(a)              scanf("%d",&a)
#define SS(a,b)           scanf("%d %d",&a,&b)
#define P(x) printf("%d\n",(x))
#define PP(x,y) printf("%d %d\n",x,y)
using namespace std ;
typedef long long ll ;
const int imin = 1e9+100;
const ll maxx = 1e5+10,mod=1e9+7,imax=1e18+10;
vector < int > g[maxx];
int par[maxx],dep[maxx],f=0,q;
bool used[maxx];
void dfs(int p,int u)
{
    if(f!=0){ return ; }
    used[u]=true ;
    for(auto x : g[u])
    {
        if(x!=p &&  used[x] )
        {
            f=u;
            q=x;
            return ;
        }
        if(!used[x])
        {
            dep[x]=dep[u]+1;
            par[x]=u ;
            dfs(u,x);
        }
    }
}
void pri(int u)
{
    if(u==f)
    {
        cout << u ;
        return ;
    }
    pri(par[u]);
    cout << " " << u ;
}
int main()
{
    ms(dep,mod);
    int n,m ;
    cin >> n >> m ;
    for(int i=1;i<=m;i++)
    {
        int u,v ;
        cin >> u >> v ;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dep[1]=1;
    for(int i=1;i<=n;i++)
    {
        if(!used[i])
        {
            dfs(0,i);
        }
        if(f!=0){break;}
    }
    if(f==0){cout << "IMPOSSIBLE" << endl; return 0 ; }
    vector < int > an ;
    int last = q ;
    while(last!=f)
    {
        an.push_back(last);
        last = par[last];
    }
    an.push_back(f);
    reverse(an.begin(),an.end());
    an.push_back(f);
    cout << an.size() << endl ;
    int idx = 0 ;
    for(auto x : an )
    {
        if(idx!=0){cout << " " ;}
        idx = 1 ;
        cout << x ;
    }
    cout << endl ;
    return 0 ;
}
