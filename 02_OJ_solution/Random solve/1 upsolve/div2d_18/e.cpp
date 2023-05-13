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
const ll maxx = 105,mod=1e9+7,imax=1e5+5,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll n,k,ar[maxx+5],dp[maxx+5][imax+5] ; 
int main()
{
   debugMode();
   cin >> n >> k ;
   for (int i = 0; i < n ; ++i)
   {
     cin >> ar[i+1] ; 
   }
   dp[0][0] = 1 ; 
   for(ll i=1;i<=n;i++)
   {
      dp[i][0] = 1 ; 
      for(ll j=1;j<=k;j++)
      {
         ll r = j ; 
         ll l = max(zz,j-ar[i]) ; 
         for(ll k=l;k<=r;k++)
         {
            dp[i][j]+=dp[i-1][k] ; 
            //if(i==3 && j==5 ) { cout << i-1 << " " << k << " " << dp[i-1][k] << endl ; } 
         }
      }
   }
   cout << dp[n][k] << endl ;
   return 0 ;
}