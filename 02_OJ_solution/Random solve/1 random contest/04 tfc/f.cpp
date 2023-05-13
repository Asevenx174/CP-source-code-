#include<bits/stdc++.h>
#define pb           push_back
#define mp           make_pair
#define pf printf
#define ff first
#define ss second
#define sef second.first
#define ses second.second
#define PI 3.14159265 /// tan inverse = atan(value)*(180/PI)

#define ms(a,b)            memset(a, b, sizeof(a))
#define lp(i,a,b) for (int i = a; i <= b; i++)
#define pii                pair <int,int>

///%I64d   %Lf
///  ios::sync_with_stdio(0); cin.tie(0); 

using namespace std ;
typedef long long ll ;
typedef long double ld ; 
const int imin = 1e9+100;
const ll maxx = 2e5+10,mod=1e9+7,imax=2e9+10,big=1e18+5,qq=1,zz=0,tt=2;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll ar[maxx+10],n,m,dp[maxx+4][5],used[maxx+4][5] ; 
void solve()
{
   int last = 0 ; 
   cin >> n >> m ;
   int a = 0 ;
   int b = 0 ; 
   for (int i = 0; i < n ; ++i)
   {
      cin >> ar[i+1] ; 
      if(ar[i+1]<0){b++;last=i+1;}else{a++;}
      dp[i+1][1] = mod ; 
      dp[i+1][2] = mod ; 
   }
   if(b>m)
   {
      cout << "-1" << endl ; return  ; 
   }
   else if(b==0)
   {
      cout << "0" << endl ; return ; 
   }
   int idx = 1 ; 
   std::vector < pii > ans ;
   while(idx<=n)
   {
      if(ar[idx]>=0){idx++;continue;}
      int l = idx ; 
      int r = idx ; 
      if(r+1<=n && ar[r+1]<0)
      {
         r++ ; 
      }
      ans.push_back({l,r}) ; 
      idx = r+1 ; 
   }
   //ans.push_back({n+1,n+1}) ; 
   dp[1][1] = 2 ; 
   dp[1][2] = 2 ; 
   used[1][1] = 1 ; 
   used[1][2] = 1 ; 
   idx = 2 ; 
   for (int i = 1 ; i < ans.size() ; ++i)
   {
      pii p = ans[i] ; 
      int l = p.ff ; 
      int r = p.ss ; 
      int len = r-l+1 ; 
      int ex = l-ans[i-1].ss-1 ;
      // dp[idx][1] == ? len+ex 
      // 1..1 

      if(used[idx-1][1]+len+ex<=m)
      {
         dp[idx][1] = min(dp[idx][1],dp[idx-1][1]) ; 
         used[idx][1] = used[idx-1][1]+len+ex ; 
      }
      if(used[idx-1][2]+len+ex<=m)
      {
         dp[idx][1] = min(dp[idx][1],dp[idx-1][2]) ; 
         used[idx][1] = used[idx-1][2]+len+ex ;
      }
      

      if(used[idx-1][1]+len<=m)
      {
         dp[idx][2] = min(dp[idx][1],dp[idx-1][1]+1) ; 
         used[idx][2] = used[idx-1][1]+len ; 
      }
      if(used[idx-1][2]+len<=m)
      {
         dp[idx][2] = min(dp[idx][1],dp[idx-1][2]+1) ; 
         used[idx][2] = used[idx-1][2]+len ;
      }
      //cout << idx << " " << dp[idx][1] << " " << dp[idx][2] << endl ;
      idx++ ;  
   }
   idx-- ; 
   ll ex = n-last ; 
   //cout << used[idx][1] << " " << used[idx][2] << " " << dp[idx][2] <<  endl ;
   ll res = mod ; 
   if(used[idx][1]+ex<=m)
   {
      res = min(res,dp[idx][1]) ; 
   }
   else
   {
      res = min(res,dp[idx][1]+qq) ;
   }
   if(used[idx][2]+ex<=m)
   {
      res = min(res,dp[idx][2]) ; 
   }
   else
   {
      res = min(res,dp[idx][2]+qq) ;
   }
   if(last==n){res--;}
   cout << res << endl ;
}
int main()
{
   //debugMode();
   ll test = 1 ; 
   // cin >> test ; 
   while(test--)
   {
      solve() ; 
   }
   return 0 ;
}