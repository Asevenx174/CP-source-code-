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

///%I64d   %Lf
///  ios::sync_with_stdio(0); cin.tie(0); 

using namespace std ;
typedef long long ll ;
typedef long double ld ; 
const int imin = 1e9+100;
const ll maxx = 1e5+10,mod=1e9+7,imax=2e9+10,big=1e18+5,qq=1,zz=0,tt=2;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}

ll h ;
vector < ll > gl[maxx];
int up[maxx][20],tim=0,in[maxx],out[maxx],lvl[maxx+10];
void dfsl(ll p,ll c)
{
    in[c]=tim++;
    up[c][0]=p ;
    for(int i=1;i<=h;i++)
    {
        up[c][i]=up[ up[c][i-1] ][ i-1 ] ;
    }
    for(auto x : gl[c])
    {
        if(x!=p)
        {
            lvl[x] = lvl[c]+1 ; 
            dfsl(c,x);
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

int dis(int a,int b)
{
   int m = lca(a,b) ; 
   cout << lvl[a] << " " << lvl[m] << " " << lvl[b] << endl ; 
   int ans = 2*lvl[m]-lvl[a]-lvl[b] ; 
   return ans ;
}

set<int> g[maxx+10]; // adjacency list (note that this is stored in set, not vector)
int sub[maxx+10], dad[maxx+10],val[maxx+10];

int dfs(int u, int p)
{
  sub[u] = 1;
  for(auto v : g[u])
  { 
    if(v != p) 
    {
      sub[u] += dfs(v, u);
    }
  }
  return sub[u];
}
int centroid(int u, int p, int n)
{
  for(auto v : g[u]) 
  {
    if(v != p)
    {
      if(sub[v] > n / 2) { return centroid(v, u, n); } 
    }
  }
  return u;
}
void build(int u, int p)
{
  int n = dfs(u, p);
  int c = centroid(u, p, n);
  if(p == -1) p = c;
  dad[c] = p;
 // cout << p << " " << c << endl ;

  vector<int> temp(g[c].begin(),g[c].end());
  for(auto v : temp) 
  {
    g[c].erase(v); g[v].erase(c);
    build(v, c);
  }
}
void update(int u)
{
   int cost = 0 , p=u ,temp = u ; 
   do
   {
      u = p ; 
      val[u] = min(val[u],cost) ; 
      p = dad[u] ;  
      if(p>0)
      {
         cost=dis(p,temp) ; 
      }
   }
   while(p!=0) ; 
}
int query(int u)
{
   int temp=u,p=u,ans=mod ; 
   do
   {
      u=p ; 
      ans = min(ans,val[u]+dis(u,temp)) ; 
      p = dad[u] ; 
   }
   while(p!=0) ;
   return ans ;  
}
void solve()
{
   int n,m ;
   cin >> n >> m ; 
   for (int i = 0; i < n+5; ++i)
   {
      val[i] = mod ; 
   }
   for (int i = 0; i+1 < n ; ++i)
   {
      int a,b ;
      cin >> a >> b ; 
      g[a].insert(b) ; 
      g[b].insert(a) ; 
      
      gl[a].push_back(b) ; 
      gl[b].push_back(a) ; 
   }
   h = ceil(log2(n));
   lvl[1] = 1 ; 
   dfsl(0,1);

   build(1,0) ; 
   update(1) ; 
   for (int i = 0; i < m ; ++i)
   {
      int t,v ;
      cin >> t >> v ; 
      if(t==1)
      {
        update(v) ; 
      }
      else
      {
        cout << query(v) << endl ;
      }
   }
}
int main()
{
   debugMode();
   ll test = 1 ; 
   //cin >> test ; 
   while(test--)
   {
      solve() ; 
   }
   return 0 ;
}