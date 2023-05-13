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
const ll maxx = 5010 ,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll n,m,xr[maxx+10] ; 
ll pq[maxx+10],dp[maxx+5][maxx+5] ; 
ll calco(ll idx,ll t)
{
   if(dp[idx][t]!=-1){return dp[idx][t];}
   if(idx>n){return 0;}
   ll a = calco(idx+1,t+1)+xr[idx]+pq[t+1] ;
   ll b = calco(idx+1,0) ;
   return dp[idx][t] = max(a,b) ;   
} 
int main()
{
   debugMode();
   memset(dp,-1,sizeof(dp)) ; 
   cin >> n >> m ;
   for (int i = 0; i < n ; ++i)
   {
      cin >> xr[i+1] ; 
   }
   for (int i = 0; i < m ; ++i)
   {
      ll c,y ; 
      cin >> c >> y ; 
      pq[c] = y ; 
   }
   ll ans = calco(1,0) ;  
   cout << ans << endl ;
   return 0 ;
}