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
const ll maxx = 2e5+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll xr[maxx+10] ,dp[maxx+10][5],cap[maxx+10][5] ; 
int main()
{
   debugMode();
   ll test ;
   cin >> test ;
   while(test--)
   {
      ll n,a,b ;
      cin >> n >> a >> b ; 
      for (int i = 0; i < n ; ++i)
      {
         cin >> xr[i+1] ; 
      }

      dp[1][1] = b*abs(xr[0]-xr[1]) ; 
      dp[1][2] = dp[1][1]+a*abs(xr[0]-xr[1]) ;
      cap[1][2]=1 ; 
      cap[1][1]=0 ; 

      for(int i=2;i<=n;i++)
      {
         ll p = cap[i-1][1] ; 
         ll q = cap[i-1][2] ; 

         ll c = dp[i-1][1]+b*abs(xr[p]-xr[i]) ; 
         ll d = dp[i-1][2]+b*abs(xr[q]-xr[i]) ;

         if(c>d)
         {
            dp[i][1]=d ; 
            cap[i][1]=q ; 
         }
         else
         {
            dp[i][1]=c ;
            cap[i][1]=p ; 
         }
         

         c = c+a*abs(xr[p]-xr[i]) ; 
         d = d+a*abs(xr[q]-xr[i]) ;

         if(c>d)
         {
            dp[i][2]= d ;  
         }
         else
         {
            dp[i][2]= c ;
         }
         cap[i][2] = i ; 
      }
      ll ans = min(dp[n][1],dp[n][2]) ; 
      cout << ans << endl ;
   }
   return 0 ;
}