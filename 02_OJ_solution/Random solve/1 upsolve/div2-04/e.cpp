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
const ll maxx = 305,mod=3e5+10,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int dp[maxx+10][maxx+10] ; 
int ar[mod+10],n,lim ;
int calco(int p,int tk)
{
   if(dp[p][tk]!=-1){return dp[p][tk];}
   int ans = 0 ; 
   for(int i=p+1;i<lim;i++)
   {
      if((ar[p]^i)<(ar[i]^p))
      {
         int temp = calco(i,tk+1) ; 
         ans = max(ans,temp) ;  
      }
   }
   ans = max(ans,tk) ; 
   return dp[p][tk]=ans ; 
}
int main()
{
   debugMode();
   int test ;
   cin >> test ;
   while(test--)
   { 
      cin >> n ; 
      for (int i = 0; i < n ; ++i)
      {
         cin >> ar[i] ; 
      }
      lim = min(n,305) ;
      int ans = 0 ; 
      for(int i=0;i<lim;i++)
      {
         memset(dp,-1,sizeof(dp)) ;
         int temp = calco(i,1) ;
         ans = max(ans,temp) ; 
      }
      cout << ans << endl ;  
   }
   return 0 ;
}