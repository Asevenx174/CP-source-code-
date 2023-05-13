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
const ll maxx = 1e5+10,mod=35,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll n,k,ar[maxx+10] ; 
ll dp[maxx+10][mod+5],lim ; 
ll calco(ll idx,ll b)
{
   if(dp[idx][b]!=-1){return dp[idx][b];}
   if(idx>n)
   {
      return 0 ; 
   }
   ll x = ar[idx] ; 
   ll div = lim-b ;
   while(div--)
   {
      x = x/2LL ; 
      if(x==zz){break;}
   }   
   ll ans = -k+x+calco(idx+1,b) ; 
   if(b>0)
   {
       ll temp = (x/2)+calco(idx+1,b-1) ; 
       ans = max(ans,temp)  ;
   }
   else
   {
      ll temp = calco(n+1,0) ; 
      ans = max(ans,temp)  ;
   }
   return dp[idx][b] = ans ; 
}
int main()
{
   debugMode() ;
   ll test ;
   cin >> test ;
   while(test--)
   {
      cin >> n >> k ;
      for (int i = 0; i < n ; ++i)
      {
         int x ;
         scanf("%d",&x) ; 
         ar[i+1] = x ; 
      }
      for (int i = 0; i < n+5; ++i)
      {
         for (int j = 0; j < mod +2 ; ++j )
         {
            dp[i][j] = -1 ; 
         }
      }
      lim = min(mod,n) ; 
      ll ans = calco(1,lim) ;
      cout << ans << endl ;
   }
   return 0 ;
}