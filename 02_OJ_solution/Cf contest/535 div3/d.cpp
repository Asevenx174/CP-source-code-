#include<bits/stdc++.h>
#define pf printf
#define ff first
#define ss second
#define sef second.first
#define ses second.second
#define ms(a,b)            memset(a, b, sizeof(a))
#define lp(i,a,b) for (int i = a; i <= b; i++)
#define pii                pair <int,int>

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
int dp[maxx+10][10],ar[maxx+10],br[maxx+10]; 
int main()
{
   debugMode();
   ms(dp,mod) ; 
   dp[0][1]=0 ; 
   dp[0][2]=0 ; 
   dp[0][3]=0 ; 

   map < char ,int > ci ; 
   map < int ,char > ic ; 
   ic[1] = 'R' ;
   ic[2] = 'G' ;
   ic[3] = 'B' ;
   ci['R'] = 1 ; 
   ci['G'] = 2 ; 
   ci['B'] = 3 ;  
   int n ;
   cin >> n ; 
   string s ;
   cin >> s ;
   int idx = 1 ; 
   for(auto c : s )
   {
      int x = ci[c] ; 
      ar[idx++] = x ; 
   }
   int ans = mod ; 
   for(int i=1;i<=n;i++)
   {
      int x = ar[i] ; 
      lp(j,1,3)
      {
          int add = x!=j ? 1 : 0 ; 
          lp(k,1,3)
          {
             if(j==k){continue;}
             dp[i][j] = min(dp[i][j],add+dp[i-1][k]) ; 
          }
          if(i==n)
          {
             ans = min(ans,dp[n][j]) ; 
          }
      }
   }
   int last = 0 ; 
   for(int i=1;i<=3;i++)
   {
       if(dp[n][i]==ans){last=i;}
   }
   br[n]=last ; 
   for(int i=n-1;i>0;i--)
   {
      int x = ar[i+1] ; 
      int who = 0 ; 
      lp(j,1,3)
      {
         if(j==last){continue;}
         int add = x!=last ? 1 : 0 ; 
         if(dp[i][j]+add==dp[i+1][last])
         {
            last = j ; break ; 
         } 
      }
      br[i] = last ; 
   }
   cout << ans << endl ;
   lp(i,1,n)
   {
      cout << ic[br[i]] ; 
   }
   cout << endl ;
   return 0 ;
}