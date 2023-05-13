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
const ll maxx = 1010 ,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int ar[maxx+10][maxx+10],n,m ; 
int dp[maxx+10][maxx+10][5] ; 
int main()
{
   debugMode();
   int test ; 
   cin >> test ;
   while(test--)
   {
      cin >> n >> m ;
      for(int i=1;i<=n;i++)
      {
         for(int j=1;j<=m;j++)
         {
            cin >> ar[i][j] ; 
         }
      } 
      for(int i=1;i<=n;i++)
      {
         for(int j=1;j<=m;j++)
         {
            int a = (ar[i][j]==-1) ? 1 : 0 ; 
            int b = (ar[i][j]==1) ? 1 : 0 ; 
            dp[i][j][1] = max(dp[i-1][j][1]+a,dp[i][j-1][1]+a) ; 
            dp[i][j][2] = max(dp[i-1][j][2]+b,dp[i][j-1][2]+b) ; 
         }
      }
      int l = dp[n][m][1] ;
      int r = dp[n][m][2] ; 
      int len = n+m-1 ; 
      int h = len/2 ; 
      if(len%2==0 && h<=min(l,r))
      {
         cout << "YES" << endl ;
      }
      else
      {
         cout << "NO" << endl ;
      }
   }
   return 0 ;
}