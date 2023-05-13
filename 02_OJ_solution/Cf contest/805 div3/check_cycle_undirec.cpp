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
const ll maxx = 1e5+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
std::vector< int > g[maxx+10] ;
int par[maxx+10],n,m ; 
int cyfirst=0,cylast=0 ;
bool vis[maxx+10] ;  
bool dfs(int u,int p)
{
   vis[u] = true ; 
   for(auto v : g[u])
   {
      if(v==p){continue;}
      if(!vis[v])
      {
         par[v] = u ; 
         if(dfs(v,par[v]))
         {
            return true ;
         }
      }
      else // v is not the parent of u and was visited before 
      {
         cyfirst = v ; 
         cylast  = u ; 
         return true ; 
      }
   }
   return false ; 
}
int main()
{
   debugMode();
   // n nodes , m edges , g graph , check cycle in O(m)
   // for directed graph 
   ms(par,-1) ; 
   for (int i = 1; i <= n ; ++i)
   {
      if(!vis[i])
      {
         if(dfs(i,par[i]))
         {
            cout << "cycles has been found " << endl ; 
         }
      }
   }
   return 0 ;
}