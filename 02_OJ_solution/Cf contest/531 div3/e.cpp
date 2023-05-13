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
const ll maxx = 2e5+10,mod= 998244353 ,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int ar[maxx+10],n ; 
set < int > g[maxx+10] ; 
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
int main()
{
   debugMode();
   map < int ,int > pq ; 
   cin >> n ; 
   lp(i,1,n){cin >> ar[i] ; pq[ ar[i] ] = i ;  }
   std::vector< pii > pp ;
   int idx = 1 ; 
   while(idx<=n)
   {
      int l = idx ; 
      int x = ar[idx] ; 
      int r = pq[x] ; 
      if(l>=r){idx++;continue;}
      while(idx<r)
      {
         r = max(r,pq[ ar[idx] ]) ; 
         idx++ ; 
      }
      pp.push_back({l,r}) ; 
      idx = r+1 ; 
   }
   pp.push_back({n+1,n+1}) ; 
   ll ans = 1 ; 
   int l = 2 ;  
   for(auto x : pp )
   {
      int r = x.ff-1 ; 
      if(l<=r)
      {
         ll len = r-l+1 ; 
         ans = (ans*fastpow(2,len,mod))%mod ; 
      }
      l = x.ss+1 ; 
   }
   cout << ans << endl ;
   return 0 ;
}