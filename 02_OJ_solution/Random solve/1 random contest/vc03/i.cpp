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
const ll maxx = 2e5+10,mod=1e9+7,imax=1e18+10;
ll h ;
vector < ll > g[maxx];
ll up[maxx][30],tim=0,in[maxx],out[maxx];
bool used[maxx+10] ; 
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



int val[maxx+10],best=0,node=0,par[maxx+10] ; 
void ass(int u,int lvl)
{
   used[u] = true ;
   val[u] = lvl ;  
   if(lvl>best)
   {
     best = lvl ; 
     node = u ;  
   }
   for(auto v : g[u])
   {
      if(used[v]){continue;}
      par[v] = u ; 
      ass(v,lvl+1) ; 
   }
}
inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int main()
{
   debugMode();
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
   ass(1,1);  
 

   memset(used,false,sizeof(used)) ; 
   int a = node ; 
   best = 0 ; 
   par[a] = a ; 
   ass(a,1) ;
   int b = node ;  
   memset(used,false,sizeof(used)) ; 
   int temp = b ; 
   used[b] = true ; 
   while(par[temp]!=a)
   {
      temp = par[temp] ; 
      used[temp] = true ; 
   }
   used[a] = true ; 
   ll f = 0 ; 
   ll ans = 0 ; 
   dfs(0,a) ; 
   vector < pair < int , pii > > pq ; 
  // cout << val[a] << " " << val[b] << " " << val[5] << " " << val[2] << endl ;
   for(int i=1;i<=n;i++)
   {
     if(used[i])
     {
        f++ ; 
     }
     else
     {
        ll l = lca(a,i) ;
        cout << i << " " << a << " " << l << endl ;
        ll temp1 = abs(val[a]-val[l])+abs(val[l]-val[i]) ;
        l = lca(b,i);
        cout << i << " " << b << " " << l << endl ;
        ll temp2 = abs(val[b]-val[l])+abs(val[l]-val[i]) ; 
        //cout << i << " " << temp1 << " " << temp2  << endl ; 
        ans+=max(temp1,temp2) ; 
        if(temp2>temp1){swap(a,b);}
        pq.push_back({i,{a,i}}) ; 
     }
   }
   pq.push_back({b,{a,b}}) ; 
   while(par[b]!=a)
   {
      b = par[b] ;
      pq.push_back({b,{a,b}}) ;  
   }
   ans+=( (f*(f-1LL))/2LL ) ;
   cout << ans << endl ; 
   for(auto x : pq )
   {
      cout << x.sef << " " << x.ses << " " << x.ff << endl ;
   }
   return 0 ;
}
