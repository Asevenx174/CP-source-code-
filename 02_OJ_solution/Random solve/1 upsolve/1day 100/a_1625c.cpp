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
const ll maxx = 505 ,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int dp[maxx+10][maxx+10],n,l,k,dr[maxx+10],ar[maxx+10] ; 
int main()
{
   debugMode();
   cin >> n >> l >> k ; 
   for (int i = 0; i < maxx ; ++i)
   {
      for (int j = 0; j < maxx ; ++j)
      {
         dp[i][j] = mod ; 
      }
   }
   for (int i = 0; i < n ; ++i)
   {
      cin >> dr[i+1] ; 
   }
   dr[n+1] = l ; 
   dr[n+2] = l ; 
   for (int i = 0; i < n ; ++i)
   {
      cin >> ar[i+1] ; 
   }
   dp[0][0]=0 ; 
   for(int i=1;i<=n+1;i++)
   {
      dp[i][0] = dp[i-1][0]+(dr[i+1]-dr[i])*ar[i] ;  
   }
   for(int i=2;i<=n+1;i++)
   {
      for(int j=1;j<=min(k,i-1);j++)
      {
         int p = i-1 ; 
         while(p>0)
         {
            int dlt = i-p-1 ; 
            if(dlt>j){break;}
            int add = (dr[i+1]-dr[i])*ar[i] ;
            int add2 = (dr[i]-dr[p+1])*ar[p] ; 
            dp[i][j] = min(dp[i][j],dp[p][j-dlt]+add+add2) ;
            p-- ;  
         } 
      }
   }
   int ans = mod ; 
   for(int i=0;i<=k;i++)
   {
      ans = min(ans,dp[n+1][i]) ; 
   }
   cout << ans << endl ; 
   return 0 ;
}