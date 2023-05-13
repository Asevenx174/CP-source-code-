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
ll h ;
vector < ll > g[maxx];
ll up[maxx][20],tim=0,in[maxx],out[maxx];
void dfs(ll p,ll c)
{
    in[c]=tim++;
    up[c][0]=p ;
    for(int i=1;i<=h;i++)
    {
        up[c][i]=up[ up[c][i-1] ][ i-1 ] ;
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
bool ancestor(ll a,ll b)
{
    if( (in[a]<in[b]) && (in[b]<out[b]) && (out[b]<out[a]) )
    {
        return true ;
    }
    return false ;
}
ll lca(ll a,ll b)
{
    if(a==b) {return a ; } /////************************8
    if(ancestor(a,b))
    {
        return a ;
    }
    if(ancestor(b,a))
    {
        return b ;
    }
    for(int i=h;i>=0;i--)
    {
        if(!ancestor(up[a][i],b) && up[a][i]>0)
        {
            a = up[a][i] ;
        }
    }
    return up[a][0];
}
int main()
{
   ll n ;
   cin >> n ;
   for(int i=1;i<n;i++)
   {
       ll u,v ;
       cin >> u >> v ;
       g[u].push_back(v);
       g[v].push_back(u);
   }
   h = ceil(log2(n));
   dfs(0,1);
   int q ;
   cin >> q ;
   while(q--)
   {
       int a,b ;
       cin >> a >> b ;
       cout << lca(a,b) << endl;
   }
   return 0 ;
}
