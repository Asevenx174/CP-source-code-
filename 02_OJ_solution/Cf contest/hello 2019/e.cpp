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
ll n,s ; 
ll calco(ll n)
{
   ll ans = 0 ; 
   while(n>9LL)
   {
      ll x = n%10LL ; 
      n = n/10LL ; 
      ans+=x ; 
   }
   ans+=n ; 
   return ans ; 
}
bool valid(ll idx)
{
      ll sum = calco(idx) ; 
      ll d = idx-sum ; 
      if(d>=s)
      {
         return true ; 
      }
      return false ; 
}
int main()
{
   debugMode();
   cin >> n >> s ; 
   ll l=1,r=n,sub=0 ; 
   while(l<=r)
   {
      ll m = (l+r)/2LL ; 
      if(!valid(m))
      {
         sub = m ; 
         l = m+1 ;  
      }
      else
      {
         r = m-1 ; 
      }
   }
   ll ans = n-sub ; 
   cout << ans << endl ;
   return 0 ;
}