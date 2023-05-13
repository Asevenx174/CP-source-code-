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
const ll maxx = 103,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll n,ar[maxx+10],dp[maxx+3][maxx+5][maxx+5] ; 
int main()
{
   debugMode();
   cin >> n ;
   for (int i = 0; i < n ; ++i)
   {
      cin >> ar[i+1] ; 
   }
   ll ans = 0 ; 
   for(int i=1;i<=n;i++)
   {
      dp[i][1][0] = i ; 
   }
   for(int i=2;i<=n;i++)
   {
      for(int j=2;j<=i;j++)
      {
         for(int k=0;k<n;k++)
         {
            int p = (ar[i]+k)%j ; 
            dp[i][j][p]+=dp[i-1][j-1][k] ; 
         }
      }
   }
   for(int j=1;j<=n;j++)
   {
      ans+=dp[n][j][0] ; 
      cout << j << " " << dp[n][j][0] << endl ;
   }
   cout << ans << endl ; 
   return 0 ;
}