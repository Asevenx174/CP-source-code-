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
const ll maxx = 2e5+10,mod=1e9+7,imax=1e18+10,h=20;
ll up[maxx][h+5],in[maxx],out[maxx],tim=0,pre[maxx],par[maxx],kk[maxx];
vector < int > g[maxx];
bool anchestor(int a,int b)
{
    if( (in[a]<in[b]) && (in[b]<out[b]) && (out[b]<out[a]) ){return true ;} else{return false;}
}
int lca(int a,int b)
{
    if(a==b){return a;}
    if(anchestor(a,b)){return a;}
    if(anchestor(b,a)){return b;}
    for(int i=h;i>=0;i--)
    {
        if(!anchestor(up[a][i],b) && up[a][i]>0){ a = up[a][i] ; }
    }
    return up[a][0];
}
void dfs(int p,int c)
{
    par[c]=p;
    up[c][0]=p;
    in[c]=tim++;
    for(int i=1;i<=h;i++)
    {
        up[c][i]=up[ up[c][i-1] ][i-1];
    }
    for(auto x : g[c])
    {
        if(x!=p)
        {
            dfs(c,x);
        }
    }
    out[c]=tim++;
}
ll traverse(int p,int c)
{
    ll ans = 0 ;
    for(auto x : g[c] )
    {
        if(x!=p)
        {
            ans+=traverse(c,x);
        }
    }
    ans+=pre[c];
    return kk[c]=ans ;
}
int main()
{
   ll n,q ;
   cin >> n >> q ;
   for(int i=1;i<n;i++)
   {
       ll u,v ;
       cin >> u >> v ;
       g[u].push_back(v);
       g[v].push_back(u);
   }
   dfs(0,1);
   while(q--)
   {
       int a,b ;
       cin >> a >> b ;
       pre[a]++;
       pre[b]++;
       int ans = lca(a,b);
       pre[ans]--;
       pre[ par[ans] ]--;
       //cout << a << " " << b << " " << ans << endl ;
       //cout << ans << " " << par[ans ] << endl;
   }
   traverse(0,1);
   for(int i=1;i<=n;i++)
   {
       if(i!=1){cout << " " ;}
       cout << kk[i] ;
   }
   cout << endl ;
   return 0 ;
}
