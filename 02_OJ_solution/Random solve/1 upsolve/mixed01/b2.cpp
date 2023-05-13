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
const ll maxx = 53,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int tr[maxx+10][10],pr[maxx+10][10],n ; 
int dp[maxx][maxx][maxx][maxx] ; 
int calco(int idx,int taken,int time,int k)
{
   if(dp[idx][taken][time][k]!=-1)
   {
      return dp[idx][taken][time][k] ; 
   }
   if(taken>=n || idx>n)
   {
      return 0 ; 
   }
   int t1 = tr[idx][1] ; 
   int t2 = tr[idx][2] ; 
   int t3 = tr[idx][3] ; 
   int p1 = pr[idx][1] ; 
   int p2 = pr[idx][2] ; 
   int p3 = pr[idx][3] ; 
   int ans = 0 ; 
   if(time-t1>=0)
   {
      int temp = p1+calco(idx+1,taken+1,time-t1,k) ; 
      ans = max(ans,temp) ; 
   }
   if(time-t2>=0)
   {
      int temp = p2+calco(idx+1,taken+1,time-t2,k) ; 
      ans = max(ans,temp) ; 
   }
   if(time-t3>=0)
   {
      int temp = p3+calco(idx+1,taken+1,time-t3,k) ; 
      ans = max(ans,temp) ; 
   }
   if(time-t1-t2-t3>=0 && k>1 && taken+3<=n)
   {
      int temp = p3+p2+p1+calco(idx+1,taken+3,time-t3-t1-t2,k-2) ; 
      ans = max(ans,temp) ; 
   }
   if(time-t1-t2>=0 && k>0 && taken+2<=n)
   {
      int temp = p2+p1+calco(idx+1,taken+2,time-t1-t2,k-1) ; 
      ans = max(ans,temp) ; 
   }
   if(time-t1-t3>=0 && k>0 && taken+2<=n)
   {
      int temp = p3+p1+calco(idx+1,taken+2,time-t3-t1,k-1) ; 
      ans = max(ans,temp) ; 
   }
   if(time-t2-t3>=0 && k>0 && taken+2<=n)
   {
      int temp = p3+p2+calco(idx+1,taken+2,time-t3-t2,k-1) ; 
      ans = max(ans,temp) ; 
   }
   int temp = calco(idx+1,taken,time,k) ; 
   ans = max(ans,temp) ;
   return dp[idx][taken][time][k] = ans ; 
}
int main()
{
   debugMode();
   int test ;
   cin >> test ;
   while(test--)
   {
      ms(dp,-1) ; 
      int k,time ; 
      cin >> n >> k >> time ; 
      for (int i = 0; i < n ; ++i)
      {
         cin >> tr[i+1][1] >> tr[i+1][2] >> tr[i+1][3] ; 
      }
      for (int i = 0; i < n ; ++i)
      {
         cin >> pr[i+1][1] >> pr[i+1][2] >> pr[i+1][3] ; 
      }
      k = min(n,k) ; 
      int ans = calco(1,0,time,k) ;
      cout << ans << endl ;
   }
   return 0 ;
}