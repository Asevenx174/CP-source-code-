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

#define SL(a)              scanf("%I64d",&a)
#define SLL(a,b)           scanf("%I64d %I64d",&a,&b)
#define PL(x) printf("%I64d\n",(x))
#define PLL(x,y) printf("%I64d %I64d\n",x,y)

#define S(a)              scanf("%d",&a)
#define SS(a,b)           scanf("%d %d",&a,&b)
#define P(x) printf("%d\n",(x))
#define PP(x,y) printf("%d %d\n",x,y)

///%I64d   %Lf
///  ios::sync_with_stdio(0); cin.tie(0); 
/// ar.resize(n+10, vector<int>(m+10)); // 2d vector 
using namespace std ;
typedef long long ll ;
typedef long double ld ; 
const int imin = 1e9+100;
const ll maxx = 1010 ,mod= 998244353 ,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll dp[maxx+5][maxx+5][10],r,c ; 
int main()
{
   debugMode();
   cin >> r >> c ; 
   dp[1][1][1] = 1 ; 
   dp[1][1][2] = 1 ; 
   dp[1][1][3] = 1 ; 
   dp[1][1][4] = 1 ; 
   for(int j=2;j<=c;j++)
   {
      dp[1][j][1] = (dp[1][j-1][1]+dp[1][j-1][2])%mod ;
      dp[1][j][2] = (dp[1][j-1][1]+dp[1][j-1][2])%mod ;

      dp[1][j][3] = (dp[1][j-1][3]+dp[1][j-1][4])%mod ;
      dp[1][j][4] = (dp[1][j-1][3]+dp[1][j-1][4])%mod ;
   }
   for(int j=2;j<=r;j++)
   {
      dp[j][1][1] = (dp[j-1][1][1]+dp[j-1][1][4])%mod ; 

      dp[j][1][2] = (dp[j-1][1][2]+dp[j-1][1][3])%mod ; 
      dp[j][1][3] = (dp[j-1][1][2]+dp[j-1][1][3])%mod ; 

      dp[j][1][4] = (dp[j-1][1][1]+dp[j-1][1][4])%mod ; 
   }
   for(int i=2;i<=r;i++)
   {
      for(int j=2;j<=c;j++)
      {
         dp[i][j][1] = (dp[i-1][j][1]+dp[i][j-1][1])%mod ;
         dp[i][j][2] = (dp[i-1][j][2]+dp[i][j-1][2])%mod ;
         dp[i][j][3] = (dp[i-1][j][3]+dp[i][j-1][3])%mod ;
         dp[i][j][4] = (dp[i-1][j][4]+dp[i][j-1][4])%mod ;
      }
   }
   ll ans = 0 ; 
   for(int i=1;i<=4;i++)
   {
      ans = (ans+dp[r][c][i])%mod ; 
   }
   cout << ans << endl ;
   return 0 ;
}