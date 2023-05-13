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
ll n,hr[maxx+10],pr[maxx+10] ; 
int main()
{
   debugMode();
   ll test ;
   cin >> test ;
   while(test--)
   {
      cin >> n ; 
      for (int i = 0; i < n ; ++i)
      {
         cin >> hr[i+1] ; 
      }
      if(n%2==1)
      {
         ll ans = 0  ;
         for(int i=2;i<n;i+=2)
         {
            ll best = max(hr[i+1],hr[i-1])+1 ; 
            ll cost = max(zz,best-hr[i]) ;
            ans+=cost ; 
         }
         cout << ans << endl ; 
         continue ; 
      }
      // n is even  
      ll idx = n-2,suf=0 ; 
      while(idx>1)
      { 
         ll best = max(hr[idx+1],hr[idx-1])+1 ; 
         ll cost = max(zz,best-hr[idx]) ; 
         suf+=cost ; 
         pr[idx] = suf ;
         idx-=2 ; 
      }
      idx = n-1 ; 
      suf = 0 ; 
      while(idx>1)
      { 
         ll best = max(hr[idx+1],hr[idx-1])+1 ; 
         ll cost = max(zz,best-hr[idx]) ; 
         suf+=cost ; 
         pr[idx] = suf ;
         idx-=2 ; 
      }
      ll ans = pr[2] ; 
      for(int i=2;i<n;i+=2)
      {
         ll temp = pr[2]-pr[i] ; 
         temp+=pr[i+1] ; 
         ans = min(ans,temp) ;   
      }
      cout << ans << endl ;
   }
   return 0 ;
}