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
const ll maxx = 1000+10,mod=1e6+10,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll ar[maxx+10],n,m ; 
ll fr[maxx+10] ; 
bool dp[maxx+10] ; 
int main()
{
   debugMode() ;
   ll f = 0 ; 
   cin >> n >> m ;
   for (int i = 0; i < n ; ++i)
   {
      ll x ;
      cin >> x ;
      x = x%m ; 
      if(x==0){f=1;}
      fr[x]++ ; 
   }
   dp[0] = true ; 
   if(f==1){ cout << "Yes" << endl; return 0 ; }
   for(int i=1;i<m;i++)
   {
      if(fr[i]==0){continue;}
      std::vector < int > used(maxx+10,0);
      for(int j=i;j<=m;j++)
      {
         if(dp[j-i] && used[j-i]<fr[i])
         {
            dp[j] = true ; 
            used[j] = used[j-i]+1 ; 
         }
      }
   }
   if(dp[m])
   {
      cout << "Yes" << endl ;
   }
   else
   {
      cout << "No" << endl ; 
   }
   return 0 ;
}