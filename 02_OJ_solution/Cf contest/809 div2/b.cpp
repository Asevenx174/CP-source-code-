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
ll ar[maxx+10],n,f[maxx+10][5],dp[maxx+10],ans[maxx+10] ; 
int main()
{
   debugMode();
   std::vector < int > v ; 
   v.push_back(1) ;
   v.push_back(3) ;
   v.push_back(5) ;
   v.push_back(6) ; 
   v.push_back(7) ; 
   ll test ;
   cin >> test ;
   while(test--)
   {
      for (int i = 0; i < maxx ; ++i)
      {
         dp[i] = 1  ;
         ans[i] = 0 ; 
      }
      cin >> n ; 
      for (int i = 0; i < n ; ++i)
      {
         cin >> ar[i+1] ; 
      }
      for(int i=n;i>0;i--)
      {
         ll x = ar[i] ; 
         for(auto add : v )
         {
            ll j = i+add ; 
            if(j<=n && ar[j]==x)
            {
               dp[i] = max(dp[i],dp[j]+1) ; 
            }
         }
      }
      for(int i=1;i<=n;i++)
      {
         ll c = ar[i] ; 
         ans[c] = max(ans[c],dp[i]) ; 
      }
      for (int i = 0; i < n ; ++i)
      {
         if(i>0){cout << " " ; }
         cout << ans[i+1] ; 
      }
      cout << endl ;
   }
   return 0 ;
}