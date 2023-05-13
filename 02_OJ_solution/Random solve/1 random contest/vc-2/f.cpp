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
const ll maxx = 1e5+5 , mod = 1e9+7,imax=1e18,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll pre[100],dis[maxx+10] ; 
ll len = mod ; 
std::vector< ll > v[100] ;
vector < int > g[maxx+10] ; 
void calco(ll p,ll k)
{
   ll idx = 0 ;
   while(1)
   {
      ll temp = (qq << idx ) ; 
      if(temp>p){break;}
      if( ( temp&p) )
      {
         pre[idx]++ ; 
         v[idx].push_back(k) ; 
         if(pre[idx]>2){len=3;}
      }
      idx++ ; 
   } 
}

int par[maxx+10] ; 
int cyfirst=0,cylast=0 ;
bool vis[maxx+10] ;  
bool dfs(int u,int p)
{
   bool so = false ; 
   vis[u] = true ; 
   for(auto v : g[u])
   {
      if(v==p){continue;}
      if(!vis[v])
      {
         par[v] = u ; 
         dis[v] = dis[u]+1 ; 
         if(dfs(v,par[v]))
         {
            so = true ; 
         }
      }
      else // v is not the parent of u and was visited before 
      {
         cyfirst = v ; 
         cylast  = u ; 
         so =  true ;
         ll co = dis[cylast]-dis[cyfirst]+1 ; 
         len = min(len,co) ; 
      }
   }
   return so ; 
}

int main()
{
   debugMode();
   ll n ;
   cin >> n ;
   for (int i = 0; i < n ; ++i)
   {
      ll x ;
      cin >> x ;
      calco(x,i) ; 
   }
   if(len==3)
   {
      cout << len << endl ; return 0 ; 
   }
   for (int i = 0; i < 62 ; ++i)
   {
      for (int j = 0; j < v[i].size() ; ++j)
      {
         for (int k = j+1 ; k < v[i].size() ; ++k)
         {
            int a = v[i][j] ; 
            int b = v[i][k] ; 
            g[a].push_back(b) ; 
            g[b].push_back(a) ; 
         }
      }
   }
   len = mod ; 
   for (int i = 0; i < n ; ++i)
   {
      if(!vis[i])
      {
         dis[i] = 0 ; 
         if(dfs(i,-1))
         {
             
         }
      }
   }
   if(len==mod){len=-1;}
   cout << len << endl ;
   return 0 ;
}