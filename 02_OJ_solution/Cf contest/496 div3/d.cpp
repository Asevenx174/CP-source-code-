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
int ar[maxx+10],n,pre[maxx+10],br[maxx+10] ; 
int dp[maxx+10] ; 
int calco(int idx)
{
   if(dp[idx]!=-1){return dp[idx];}
   if(idx>n)
   {
      return 0 ; 
   }
   int sum = 0 ; 
   int ans = 0 ; 
   for(int i=idx;i<=min(n,idx+2);i++)
   {
      sum+=ar[i] ; 
      int add = (sum%3==0) ? 1 : 0 ; 
      int temp = add + calco(i+1) ; 
      ans = max(ans,temp) ;
   } 
   return dp[idx] = ans ; 
}
int main()
{
   debugMode();
   ms(dp,-1) ; 
   int idx = 0 ; 
   string s ;
   cin >> s ;
   n = s.size() ; 
   int sum = 0 ; 
   for(auto c : s )
   {
      int x = c-'0' ; 
      ar[++idx] = x%3 ;  
   }
   int ans = calco(1) ;
   cout << ans << endl ; 
   return 0 ;
}