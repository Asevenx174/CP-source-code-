#include<bits/stdc++.h>
#define pf printf
#define ff first
#define ss second
#define sef second.first
#define ses second.second
#define ms(a,b)            memset(a, b, sizeof(a))
#define pii                pair < long long , long long >

///%I64d   %Lf
///  ios::sync_with_stdio(0); cin.tie(0); 
/// ar.resize(n+10, vector<int>(m+10)); // 2d vector 
using namespace std ;
typedef long long ll ;
typedef long double ld ; 
const int imin = 1e9+100;
const ll maxx = 3e5+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll ar[maxx+10],br[maxx+10] ; 
int main()
{
   debugMode();
   ll n,k ;
   cin >> n >> k ;
   for (int i = 0; i < n ; ++i)
   {
      cin >> ar[i+1] ; 
   }
   std::vector <  pii > pq ;
   for(ll i=2;i<=n;i++)
   {
      pq.push_back({ar[i]-ar[i-1],i-1ll}) ; 
   }
   sort(pq.begin(),pq.end(),greater<pii>());
   auto it = pq.begin() ; 
   int temp = k-1 ; 
   while(temp--)
   {
      pii p = *it ; it++ ;
      br[p.ss] = 1 ; 
   }
   ll l = mod ; 
   ll r = -mod ; 
   ll ans = 0 ;
   br[n] = 1 ; 
   for(int i=1;i<=n;i++)
   {
      l = min(l,ar[i]) ; 
      r = max(r,ar[i]) ; 
      if(br[i])
      {
         ans+=(r-l) ; 
         l = mod ; 
         r = -mod ; 
      } 
   }
   cout << ans << endl ; 
   return 0 ;
}