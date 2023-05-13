#include<bits/stdc++.h>
#define pf printf
#define ff first
#define ss second
#define sef second.first
#define ses second.second
#define ms(a,b)            memset(a, b, sizeof(a))
#define lp(i,a,b) for (int i = a; i <= b; i++)
#define pii                pair <int,int>

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
ll ar[maxx],br[maxx],dr[maxx],n,add ; 
std::vector< int > g[maxx+10] ; 
bool used[maxx+10],sw[maxx+10] ; 
ll fastpow(ll n,ll k,ll p)
{
    ll ans = 1 ;
    while(k>0)
    {
        if(k&qq)
        { ans = (ans*n)%p; }
        k = k >> qq ;
        n = (n*n)%p;
    }
    return ans ;
}
void dfs(ll u)
{
   if(sw[u]){add=0;}
   used[u]=true ; 
   for(auto v : g[u] )
   {
       if(used[v]){continue;}
       dfs(v) ; 
   }
}
int main()
{
   debugMode();
   ll test ;
   cin >> test ;
   while(test--)
   {
      cin >> n ;
      lp(i,1,n)
      {
         cin >> ar[i] ; 
         used[i] = false ; 
         sw[i] = false ; 
         g[i].clear() ; 
      }
      lp(i,1,n)
      {
         cin >> br[i] ; 
      }
      lp(i,1,n)
      {
         cin >> dr[i] ;
         ll u = ar[i] , v = br[i] ; 
         ll f = dr[i] ; 
         if(u==v){continue;}
         g[u].push_back(v) ; 
         if(f!=0){sw[u]=true;sw[v]=true;}
      }
      ll p = 0 ; 
      lp(i,1,n)
      {
         if(used[i] || g[i].size()==0 ){continue;}
         add = 1 ; 
         dfs(i) ; 
         p+=add ; 
      }
      ll ans = fastpow(2,p,mod) ;
      cout << ans << endl ;
   }
   return 0 ;
}