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
ll ar[maxx+10],n,k ; 
ll valid(ll l)
{
    ll sum = 0 ; 
    for (int i = 0; i < n ; ++i)
    {
       ll x = min(ar[i],l) ; 
       sum+=x ; 
    }
    return sum ; 
}
int main()
{
   debugMode();
   cin >> n >> k ;
   for (int i = 0; i < n ; ++i)
   {
      cin >> ar[i] ; 
   }
   ll l=0,r=1e18,tk,cy ; 
   while(l<=r)
   {
      ll m = (l+r)/2LL ;
      ll val = valid(m) ; 
      if(val<k)
      {
         cy = m ; 
         l = m+1 ; 
         tk = val ; 
      }
      else
      {
         r = m-1 ; 
      }
   }
   k-=tk ; 
   for (int i = 0; i < n ; ++i)
   {
      ll x = min(ar[i],cy) ; 
      ar[i]-=x ; 
      if(ar[i]>0 && k>0)
      {
         ar[i]-- ; 
         k-- ; 
      }
   }
   for (int i = 0; i < n ; ++i)
   {
      if(i>0){cout << " " ;}
      cout << ar[i] ; 
   }
   cout << endl ;
   return 0 ;
}