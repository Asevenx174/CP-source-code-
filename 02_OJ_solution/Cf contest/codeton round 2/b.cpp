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
ll ar[maxx+10],n,lim ; 
ll calco(ll l,ll r)
{
   ll m = (l+r)/2LL ; 
   ll ans = max(abs(m-l),abs(m-r)) ;
   return ans ; 
}
int main()
{
   debugMode();
   ll test ;
   cin >> test ;
   while(test--)
   {
      cin >> n >> lim ; 
      for (int i = 0; i < n ; ++i)
      {
         cin >> ar[i+1] ; 
      }
      ll l = ar[1] , r = ar[1] ,ans = 0  ; 
      for(int i=2;i<=n;i++)
      {
         l = min(l,ar[i]) ; 
         r = max(r,ar[i]) ; 
         ll val = calco(l,r) ; 
         if(val>lim)
         {
            ans++ ; 
            l = ar[i] ; 
            r = ar[i] ; 
         }
      }
      cout << ans << endl ;
   }
   return 0 ;
}