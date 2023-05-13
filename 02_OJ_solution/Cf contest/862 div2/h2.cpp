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
/// vector<vector<int>> vec( n , vector<int> (m));
using namespace std ;
typedef long long ll ;
typedef long double ld ; 
const int imin = 1e9+100;
const ll maxx = 30000+10,mod=1e9+7,imax=2e9+10,big=1e18+5,qq=1,zz=0,tt=2;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
bool used[maxx+10] ; 
vector < pii > g[maxx+10],k[maxx+10] ;
int n,dw[maxx+10],up[maxx+10],ans[maxx+10] ; 
void dfs(int u)
{
   used[u] = true ; 
   dw[u] = 0 ; 
   for(auto p : g[u])
   {
      int v = p.ff ; 
      int w = p.ss ; 
      if(used[v]){continue;}
      dfs(v) ; 
      dw[u] = max(dw[u],dw[v]+w) ; 
      k[u].push_back({dw[v]+w,v}) ; 
   }
   sort(k[u].begin(),k[u].end(),greater<pii>()) ; 
}
void dfs2(int u,int sum)
{
   //cout << u << " " << sum << endl ;
   used[u] = true ; 
   for(auto p : g[u])
   {
      int v = p.ff ; 
      int w = p.ss ; 
      if(used[v]){continue;}
      int lim = min(2,(int)k[u].size()) ;
      int add = sum+w ; 
      auto it = k[u].begin() ; 
      for (int i = 0; i < lim ; ++i)
      {
         pii q = *it ; it++ ; 
         if(q.ss==v){continue;}
         add = max(add,w+q.ff) ; 
      } 
      up[v] = add ; 
      dfs2(v,add) ; 
   }
   ans[u] = max(dw[u],sum) ; 
}
int t = 1 ; 
void solve()
{
   cin >> n ;
   for (int i = 0; i < n+5; ++i)
   {
      g[i].clear() ; 
      k[i].clear() ; 
   }
   for (int i = 1 ; i < n ; ++i)
   {
      int u,v,w ;
      cin >> u >> v >> w ; 
      u++ ; 
      v++ ; 
      g[u].push_back({v,w}) ;
      g[v].push_back({u,w}) ; 
   }
   memset(used,false,sizeof(used)) ; 
   dfs(1) ;
   memset(used,false,sizeof(used)) ;
   dfs2(1,0) ;  
   cout << "Case " << t++ << ":" << endl ;
   for (int i = 0; i < n ; ++i)
   {
      //if(i>0){cout << " ";}
      cout << ans[i+1] << endl ; 
   }
}
int main()
{
   debugMode();
   ios::sync_with_stdio(0); cin.tie(0);
   ll test = 1 ; 
   cin >> test ; 
   while(test--)
   {
      solve() ; 
   }
   return 0 ;
}