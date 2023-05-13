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
ll n,m,ar[maxx+10],f[maxx+10] ; 
bool valid(ll t)
{
   set < int > fr ; 
   for (int i = 0; i < n ; ++i)
   {
      if(ar[i+1]==0)
      {
         fr.insert(i+1) ; 
      }
   }
   for(int i=1;i<=n;i++)
   {
      ll x = f[i] ; 
      ll k = min(x,t) ; 
      x-=k ; 
      x = x*2 ; 
      if(x>t){return false ;}
   }
   return true ;
}
int main()
{
   debugMode();
   ll test ;
   cin >> test ;
   while(test--)
   {
      ms(f,0) ; 
      cin >> n >> m ;
      for (int i = 0; i < n ; ++i)
      {
         cin >> ar[i+1] ; 
         f[ ar[i+1] ]++ ; 
      }
      ll l=1,r=mod,ans=0 ; 
      while(l<=r)
      {
         ll mid = (l+r)/2LL ;
         if(valid(mid))
         {
            ans = mid ; 
            r = mid-1 ; 
         }
         else
         {
            l = mid+1 ; 
         }
      }
      cout << ans << endl ;
   }
   return 0 ;
}