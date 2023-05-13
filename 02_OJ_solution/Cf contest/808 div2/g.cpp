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
int ar[maxx+10],dp[maxx+10] ; 
void gendiv(int v)
{
   int add = 0 ; 
   for(int i=1;i*i<=v;i++)
   {
      if(v%i==0)
      {
         int y = v/i ; 
         if(i<v)
         {
            add = max(add,dp[i]) ; 
         }
         if(y<v)
         {
            add = max(add,dp[y]) ; 
         }
      }
   }
   dp[v]+=add ; 
}
int main()
{
   debugMode();
   int test ;
   cin >> test ;
   while(test--)
   {
      ms(dp,0) ; 
      int n ;
      cin >> n ; 
      for (int i = 0; i < n ; ++i)
      {
         int x ;
         cin >> x ;
         dp[x]++ ; 
      }
      int ans = 0 ; 
      for(int i=1;i<maxx;i++)
      {
         if(dp[i]>0)
         {
            gendiv(i) ; 
            ans = max(ans,dp[i]) ; 
         }
      }
      ans = n-ans ; 
      cout << ans << endl ;
   }
   return 0 ;
}