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
int ar[maxx+10],n,k ; 
std::vector < int > g[maxx+10] ;
int xr[maxx+10] ; 
bool used[maxx+10] ; 
int dfs(int u)
{
   used[u] = true ; 
   int temp = ar[u] ; 
   for(auto v : g[u])
   {
      if(used[v]){continue;}
      int val = dfs(v) ; 
      temp = temp^val ; 
   }
   return xr[u] = temp ; 
}
int ans = 0 ; 
void dfs2(int u,int p)
{
   if(p>0)
   {
      int r = xr[1]^xr[u] ; 
      int l = xr[u] ;  
      if(l==r)
      {
         ans=1;
      }
   }
   used[u] = true ; 
   for(auto v : g[u])
   {
      if(used[v]){continue;}
      dfs2(v,u) ; 
   }
}
int main()
{
   debugMode();
   int test ;
   cin >> test ;
   while(test--)
   {
      memset(used,false,sizeof(used)) ;
      ans = 0 ; 
      int val = 0 ; 
      cin >> n >> k ;
      for (int i = 0; i < n ; ++i)
      {
         cin >> ar[i+1] ; 
         val = val^ar[i+1] ; 
         g[i+1].clear() ; 
      }
      for (int i = 0; i+1 < n ; ++i)
      {
         int u,v ;
         cin >> u >> v ;
         g[u].push_back(v) ;
         g[v].push_back(u) ; 
      }
      int temp = dfs(1) ; 
      memset(used,false,sizeof(used)) ; 
      dfs2(1,0) ; 
     // cout << xr[1] << " " << xr[3] << endl ;  
      if(ans || val==0)
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