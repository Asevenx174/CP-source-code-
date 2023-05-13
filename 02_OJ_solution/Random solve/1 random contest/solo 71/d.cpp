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

using namespace std ;
typedef long long ll ;
typedef long double ld ; 
const int imin = 1e9+100;
const ll maxx = 2e5+10,mod=1e9+7,imax=2e9+10,big=1e18+5,qq=1,zz=0,tt=2;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll n,k  ;
std::vector < ll > ar ; 
bool valid(ll val,ll idx)
{
  ll sum = 0 ; 
  while(idx<=n)
  {
     ll add = max(zz,val-ar[idx]) ; 
     sum+=add ; 
     idx++ ; 
  }
  if(sum>k){return false;}
  return true ; 
}
void solve()
{
   ar.clear() ; 
   cin >> n >> k ; 
   for (int i = 0; i < n ; ++i)
   {
      ll x ;
      cin >> x ;
      ar.push_back(x) ; 
   }
   sort(ar.begin(),ar.end()) ; 
   ll idx = (n+qq)/tt ; 
   ll l = zz ,r=1e18+5 ;
   ll ans = l ; 
   while(l<=r)
   {
      ll m = (l+r)/tt ; 
      if(valid(m,idx-qq))
      {
         ans = m ; 
         l = m+qq ; 
      }
      else
      {
         r = m-qq ; 
      }
   } 
   cout << ans << endl ;  
}
int main()
{
   debugMode();
   ll test = 1 ; 
   // cin >> test ; 
   while(test--)
   {
      solve() ; 
   }
   return 0 ;
}