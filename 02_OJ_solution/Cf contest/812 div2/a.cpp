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
int n,k,ar[maxx+10],br[maxx+10],len,dis ; 
int fr[10000] ;
ll dp[1050][1050] ; 
ll calco(ll idx,ll last)
{
   if(dp[idx][last]!=-1){return dp[idx][last];}
   if(idx>len){return 1;}
   ll ans = 1 ; 
   for(int i=last+1;i<=dis;i++)
   {
      ll q = br[i] ; 
      q = fr[q] ; 
      ll temp = (q*calco(idx+1,i))%mod ; 
      ans = (ans*temp)%mod ; 
   }
   return dp[idx][last] = ans ; 
}
int main()
{
   debugMode();
   memset(dp,-1,sizeof(dp)) ;
   set < int > s ; 
   cin >> n >> k ; 
   for (int i = 0; i < n ; ++i)
   {
      int x ;
      cin >> x ;
      ar[i+1] = x ; 
      s.insert(x) ; 
      fr[x]++ ; 
   }
   int idx = 0 ; 
   for(auto x : s)
   {
      br[++idx] = x ; 
   }
   dis = idx ; 
   len = min(dis,k) ; 
   ll temp = calco(0,0) ;
   ll ans = 0 ; 
   for(int i=1;i<=len;i++)
   {
      cout << i << "->" << endl ;
      for(int j=1;j<=dis;j++)
      {
         ll add = dp[i][j] ; 
         if(add==-1){continue;}
         cout << j << " " << dp[i][j] << endl ;
         ans = (ans+add)%mod ; 
      }
   }
   cout << ans << endl ;
   return 0 ;
}