#include<bits/stdc++.h>
#define pf printf
#define ff first
#define ss second
#define sef second.first
#define ses second.second
#define ms(a,b)            memset(a, b, sizeof(a))
#define pii                pair <int,int>

///%I64d   %Lf
///  ios::sync_with_stdio(0); cin.tie(0); 
/// ar.resize(n+10, vector<int>(m+10)); // 2d vector 
using namespace std ;
typedef long long ll ;
typedef long double ld ; 
const int imin = 1e9+100;
const ll maxx = 2e5+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
std::vector < int > g[maxx+10] ;
bool used[maxx+10] ; 
int dep[maxx+10] ; 
void dfs(int u)
{
   used[u] = true ; 
   for(auto v : g[u])
   {
      if(used[v]){continue;}
      dep[v] = dep[u]+1 ; 
      dfs(v) ; 
   }
}

ll up[maxx][20],tim=0,in[maxx],out[maxx],h;

void dfs22(ll p,ll c)
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
            dfs22(c,x);
        }
    }
    out[c]=tim++;
}

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
   debugMode();
   int n ;
   cin >> n ;
   h = ceil(log2(n));
   for (int i = 0; i+1 < n ; ++i)
   {
      int u,v ;
      cin >> u >> v ;
      g[u].push_back(v) ;
      g[v].push_back(u) ; 
   }
   dfs(1) ; 
   dfs22(0,1) ; 
   int q ;
   cin >> q ;
   while(q--)
   {
      vector < pii > pq ; 
      int k ;
      cin >> k ;
      for (int i = 0; i < k ; ++i)
      {
         int x ;
         cin >> x ;
         pq.push_back({dep[x],x}) ; 
      }
      sort(pq.begin(),pq.end(),greater<pii>()) ; 
      if(pq.size()<3)
      {
         cout << "YES" << endl ; continue ; 
      }
      auto it = pq.begin() ; 
      pii p = *it ; 
      int v = p.ss ,x=0 ,u=0 ; 
      it++ ; 
      while(it!=pq.end())
      {
         p = *it ; 
         u = p.ss ; 
         x = lca(u,v) ; 
         //cout << u << " " << v << " " << x << endl ;
         if(x!=u)
         {
            it++ ; 
            break ; 
         }
         it++ ; 
      }
      int f = 1 ; 
      while(it!=pq.end())
      {
         p = *it ; 
         int y = p.ss ; 
         if(dep[y]<=dep[x] && x!=y){f=0;break;}
         int l = lca(y,u) ;
         int r = lca(y,v) ; 
         if(l!=y && r!=y && y!=x)
         {
            //cout << u << " " << v << " " << x << " " << y << endl ;
            f = 0 ; break ; 
         }
         it++ ; 
      } 
      if(f==1)
      {
         cout << "YES" << endl ;
      }
      else
      {
         cout << "NO" << endl ; 
      }
   }
   return 0 ;
}