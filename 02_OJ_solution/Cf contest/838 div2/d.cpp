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
const ll maxx = 2e5+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0,tt=2;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}

ll pr[maxx+10],n,ar[maxx+10] ;
ll sol(ll x)
{
    ll p = x*(x+1LL) ;
    p = p/2LL ;
    return p ;
}
ll calco(ll i,ll l,ll r)
{
    //return 0 ; 
   ll lim = tt*i ; 
   ll len = r-l+qq ; 
   if(len>lim || ( l<=ar[i] && ar[i]<=r ) ){ return zz ;}
   ll idx = ar[i] ; 
   ll sum = 0 ; 
   if(idx<l)
   {
      while(idx+qq<=l)
      {
         idx++ ; 
         len = r-idx+qq ; 
         ll k = min(lim-len+qq,n-r+qq) ; 
         k = max(k,zz) ; 
         sum+=k ; 
      }
   }
   else
   {
      while(idx-qq>=r)
      {
        idx-- ; 
        len = idx-l+qq ; 
        ll k = min(lim-len+qq,l) ; 
        k = max(k,zz) ; 
        sum+=k ; 
      }
   }
   return sum ; 
}
int main()
{
    debugMode();
   ll test ;
   cin >> test ;
   while(test--)
   {
       cin >> n ;
       for(int i=0;i<=n;i++)
       {
           ar[i] = 0 ;
       }
       for(int i=1;i<=n;i++)
       {
           ll x ;
           cin >> x ;
           ar[x] = i ;
       }
       ll l = ar[0] ;
       ll r = ar[0] ;
       ll ans = qq ;
       for(int i=1;i<n;i++)
       {
           //cout << i << " " << l << " ?? " << r << endl ;
           ll add = calco(i,l,r) ;
           ans+=add ;
           ll x = ar[i] ;
           l = min(l,x) ;
           r = max(r,x) ;
       }
       cout << ans << endl ;
   }
   return 0 ;
}