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
const ll maxx = 3e5+10,mod=1e9+7,imax=1e18,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll ar[maxx+10],n,dp[maxx][5] ; 
int main()
{
   debugMode();
   cin >> n ; 
   lp(i,1,n)
   {
      cin >> ar[i] ; 
   }
   // n was not taken
   dp[1][1]=ar[1] ; 
   dp[1][2]= imax ; 
   lp(i,2,n-1)
   {
      dp[i][1] = min(dp[i-1][1],dp[i-1][2])+ar[i] ;
      dp[i][2] = dp[i-1][1] ;  
   }
   ll ans = dp[n-1][1] ; 
   // n is taken ; 
   dp[1][1] = ar[1]+ar[n] ; 
   dp[1][2] = ar[n] ; 
   lp(i,2,n-1)
   {
      dp[i][1] = min(dp[i-1][1],dp[i-1][2])+ar[i] ;
      dp[i][2] = dp[i-1][1] ;  
   }
   ll temp = min(dp[n-1][1],dp[n-1][2]) ;
   ans = min(ans,temp) ; 
   cout << ans << endl ; 
   return 0 ;
}