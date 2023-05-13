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
const ll maxx = 23 ,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll d,dp[maxx+5][5][15] ; 
ll calco(ll idx,ll s,ll last)
{
   if(dp[idx][s][last]!=-1){return dp[idx][s][last];}
   if(idx>d){return 1 ;}
   ll ans = 0 ; 
   for(int i=last+1;i<10;i++)
   {
      if(s==0){break;}
      ans+=calco(idx+1,1,i) ;
   }
   for(int i=last-1;i>=0;i--)
   {
      ans+=calco(idx+1,0,i) ;
   }
   ans+=calco(idx+1,s,last) ;
   return dp[idx][s][last]= ans ;  
}
int main()
{
   //debugMode();
   memset(dp,-1,sizeof(dp)) ; 
   cin >> d ; 
   ll ans = calco(1,1,0) ; 
   cout << ans << endl ;
   return 0 ;
}