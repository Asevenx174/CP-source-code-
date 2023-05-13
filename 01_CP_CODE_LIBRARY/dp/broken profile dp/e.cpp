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
/// vector<vector<int>> vec( n , vector<int> (m));
using namespace std ;
typedef long long ll ;
typedef long double ld ; 
const int imin = 1e9+100;
const ll maxx = 34,mod=30,imax=2e9+10,big=1e18+5,qq=1,zz=0,tt=2;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
bool occupied(int i, int q)
{ 
    return q&(1 << (i-1)) ;
}
ll n=3,m,dp[maxx+5][maxx+5] ; 
void calco(int i,int j,int q,int p)
{
   //cout << p << " " << q << endl ;
   if(i==n+1)
   {
      dp[j+1][p]+=dp[j][q] ; 
      return ;
   }
   if(occupied(i,q))
   {
      calco(i+1,j,q,p) ; return ;
   }
   if(i+1<=n && !occupied(i+1,q))
   {
      calco(i+2,j,q,p) ; 
   }
   if(j+1<=m)
   {
      calco(i+1,j,q,(p^(1<<(i-1)))) ; 
   }
}
void solve()
{
   cin >> n >> m ; 
   if(min(n,m)==0)
   {
      cout << "0" << endl ; return ;
   }
   for (int i = 0; i < maxx ; ++i)
   {
      for (int j = 0; j < maxx ; ++j)
      {
         dp[i][j] = 0 ; 
      }
   }
   dp[0][0] = 1 ; 
   for(int j=0;j<m;j++)
   {
      for(int q=0;q<(1<<n);q++)
      {
         calco(1,j,q,0) ; 
      }
   }
   cout << dp[m][0] << endl ;
}
int main()
{
   debugMode();
   ll test = 1 ; 
   cin >> test ; 
   while(test--)
   {
      solve() ; 
   }
   return 0 ;
}