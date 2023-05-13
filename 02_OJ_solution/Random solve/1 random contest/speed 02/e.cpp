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
int ar[maxx+10],n,dp[maxx+10][40] ; 
bool valid(int k)
{
  int need = n-k+1 ; 
  std::vector < int > pq(30,0) ;  
  for(int i=1;i+k-1<=n;i++)
  {
     int l = i ;
     int r = i+k-1 ; 
     for(int j=1;j<=26;j++)
     {
        int have = dp[r][j]-dp[l-1][j] ;
        if(have>0)
        {
          pq[j]++ ; 
          if(pq[j]==need){return true ; }
        } 
     }
  }
  return false ; 
}
int main()
{
   debugMode();
   string s ;
   cin >> s ;
   n = s.size() ; 
   map < int ,char > ic ; 
   map < char ,int > ci ; 
   char cc = 'a' ; 
   int idx = 1 ;
   while(cc<='z')
   {
      ci[cc] = idx ; 
      ic[idx] = cc ; 
      cc++;
      idx++ ; 
   }
   idx = 1 ;
   for(auto c : s )
   {
      ar[idx++] = ci[c] ; 
   }
   for(int i=1;i<=n;i++)
   {
      int x = ar[i] ; 
      dp[i][x] = 1 ; 
      for(int j=1;j<=26;j++)
      {
         dp[i][j]+=dp[i-1][j] ; 
      }
   }
   int l = 1 ,r = n,ans=0 ; 
   while(l<=r)
   {
      int m = (l+r)/2 ;
      if(valid(m))
      {
        ans = m ; 
        r = m-1 ; 
      }
      else
      {
        l = m+1 ; 
      }
   }
   cout << ans << endl ;
   return 0 ;
}