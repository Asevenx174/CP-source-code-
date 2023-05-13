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
ll ar[maxx+10],n ; 
std::vector < ll > g[maxx+10] ;
bool used[maxx+10] ; 
multiset < ll > s ; 
ll ans = 0 ; 
void dfs(ll u)
{
   auto it = s.begin() ; 
   ans = max(ans,*it) ; 
   used[u] = true ; 
   for(auto v : g[u])
   {
      if(used[v]){continue;}
      auto it = s.find(ar[v]) ;
      ll f = 0 ; 
      if(ar[v]<maxx)
      { 
         if(it!=s.end())
         {
            s.erase(it) ; 
            f = 1 ; 
         }
      }
      dfs(v) ; 
      if(f)
      {
         s.insert(ar[v]) ; 
      }
   }
}
int main()
{
   debugMode();
   cin >> n ;
   for (int i = 0; i < n ; ++i)
   {
      cin >> ar[i+1] ; 
   }
   for (int i = 0; i+1 < n ; ++i)
   {
      ll u,v ;
      cin >> u >> v ;
      g[u].push_back(v) ; 
      g[v].push_back(u) ; 
   }
   for (int i = 0; i < maxx ; ++i)
   {
      s.insert(i) ; 
   }
   if(ar[1]<maxx)
   {
      s.erase(s.find(ar[1])) ; 
   }
   dfs(1) ; 
   cout << ans << endl ;
   return 0 ;
}