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
const ll maxx = 6000+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
bool com(const pii &a,const pii &b)
{
   if(a.ff==b.ff)
   {
      return a.ss > b.ss ; 
   }
   else
   {
      return a.ff < b.ff ; 
   }
}
int ar[maxx+10],br[maxx+10],n,t ; 
int dp[maxx+10][maxx+10] ; 
int calco(int idx,int tim)
{
   if(dp[idx][tim]!=-1){return dp[idx][tim];}
   if(idx>n || tim>t){return 0;}  
   ll a=calco(idx+1,tim+ar[idx])+br[idx],b=calco(idx+1,tim) ;
   return dp[idx][tim] = max(a,b) ; 
}
int main()
{
   debugMode();
   memset(dp,-1,sizeof(dp)) ; 
   cin >> n >> t ; 
   t-- ;
   std::vector < pii > pq ;
   for (int i = 0; i < n ; ++i)
   {
      int x,y ;
      cin >> x >> y ; 
      pq.push_back({x,y}) ; 
   }
   sort(pq.begin(),pq.end(),com) ; 
   int idx = 1 ; 
   for(auto p : pq )
   {
       ar[idx] = p.ff ; 
       br[idx] = p.ss ; 
       idx++ ; 
   }
   int ans = calco(1,0) ; 
   cout << ans << endl ; 
   return 0 ;
}