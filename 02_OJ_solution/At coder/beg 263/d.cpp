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
ll ar[maxx+10],lr[maxx+10],rr[maxx+10],n ; 
ll l,r ; 
int main()
{
   debugMode();
   cin >> n >> l >> r ; 
   for (int i = 0; i < n ; ++i)
   {
      cin >> ar[i+1] ; 
   }
   for(ll i=1;i<=n;i++)
   {
      lr[i] = min(i*l,lr[i-1]+ar[i]) ; 
   }
   for(ll i=n;i>0;i--)
   {
      ll j = n-i+1  ; 
      rr[i] = min(j*r,rr[i+1]+ar[i]);
   }
   ll ans = 1e18 ; 
   for(int i=0;i<=n;i++)
   {
      ll temp = lr[i]+rr[i+1] ; 
      ans = min(ans,temp) ; 
   }
   cout << ans << endl ;
   return 0 ;
}