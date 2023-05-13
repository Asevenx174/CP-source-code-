#include<bits/stdc++.h>
#define pf printf
#define ff first
#define ss second
#define sef second.first
#define ses second.second
#define ms(a,b)            memset(a, b, sizeof(a))
#define pii                pair < int ,int  >

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
ll ar[maxx+10],br[maxx+10],temp=0  ; 
map < pii , ll > pq ; 
ll ans = 0 ; 
void calco(ll b,ll a)
{
   if(a*b>zz)
   {
      a = max(a,-a) ; 
      b = max(b,-b) ;
      ll g = __gcd(a,b) ; 
      a = a/g  ;
      b = b/g  ;
      pq[{b,a}]++ ; 
      ans = max(ans,pq[{b,a}]) ; 
   }
   else if(a*b<zz)
   {
      a = max(a,-a) ; 
      b = max(b,-b) ;
      ll g = __gcd(a,b) ; 
      a = a/g  ;
      b = b/g  ;
      pq[{-b,a}]++ ; 
      ans = max(ans,pq[{-b,a}]) ;
   }
   else if(b==zz && a==zz)
   {
      pq[{0,0}]++ ; 
   }
   else if(b==0)
   {
      temp++ ; 
   }
}
int main()
{
   debugMode();
   ll n ;
   cin >> n ;
   for (int i = 0; i < n ; ++i)
   {
      ll x ;
      cin >> x ;
      ar[i+1] = x ; 
   }
   for (int i = 0; i < n ; ++i)
   {
      ll x ;
      cin >> x ;
      br[i+1] = x ;
      calco(br[i+1],ar[i+1]) ;  
   }
   ans = max(ans,temp)+pq[{0,0}] ; 
   cout << ans << endl ;
   return 0 ;
}