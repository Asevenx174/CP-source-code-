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

using namespace std ;
typedef long long ll ;
typedef long double ld ; 
const int imin = 1e9+100;
const ll maxx = 2010 ,mod= 998244353 ,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
std::vector< ll > g[maxx] ;
ll dp[maxx][maxx][5] ; 
int main()
{
   debugMode();
   ll n,m,k,s,t,xo ; 
   cin >> n >> m >> k >> s >> t >> xo ; 
   for (int i = 0; i < m ; ++i)
   {
      ll u,v ;
      cin >> u >> v ; 
      g[u].push_back(v) ; 
      g[v].push_back(u) ;
   }
   for(int j=1;j<=n;j++)
   {
      ll p = j==s ? 1 : 0 ; 
      dp[0][j][0] = p ; 
      dp[0][j][1] = 0 ;
   }
   for(int i=0;i<k;i++)
   {
       for(int j=1;j<=n;j++)
       {
          ll op = j!=xo ? 0 : 1 ; 
          for(auto k : g[j] )
          {
             ll x = 0 ; 
             while(x<2)
             {
                dp[i+1][j][x] = (dp[i+1][j][x]+dp[i][k][x^op])%mod ; 
                x++;
             }
          }
       }
   }
   cout << dp[k][t][0] << endl ;
   return 0 ;
}