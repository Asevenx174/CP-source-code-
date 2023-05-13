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
const ll maxx = 12 ,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int ar[maxx+10],n,m ; 
bool dp[maxx+5][maxx+5] ; 
void dfs(int idx,int last)
{
   //if(dp[idx][last]){return;}
   if(idx>n)
   {
      for (int i = 0; i < n ; ++i)
      {
         if(i>0){cout << " " ; }
         cout << ar[i+1] ; 
      }
      cout << endl ; 
      return  ; 
   }
   for(int i=last+1;i<=m;i++)
   {
      ar[idx] = i ; 
      dfs(idx+1,i) ; 
   }
   //dp[idx][last] = true ; 
   return ; 
}
int main()
{
   debugMode();
   cin >> n >> m ;
   dfs(1,0) ; 
   return 0 ;
}