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
using namespace std ;
typedef long long ll ;
const int imin = 1e9+100;
const ll maxx = 510 ,mod=1e9+7,imax=1e16+10;
ll dp[maxx][maxx];
int main()
{
   int n,m,q ;
   cin >> n >> m >> q ;
   for(int i=1;i<=n;i++)
   {
       for(int j=1;j<=n;j++)
       {
           dp[i][j]=imax;
           dp[j][i]=imax;
       }
       dp[i][i]=0;
   }
   for(int i=1;i<=m;i++)
   {
       ll a,b,c ;
       cin >> a >> b >> c ;
       dp[a][b]=min(dp[a][b],c);
       dp[b][a]=min(dp[b][a],c);
   }
   for(int i=1;i<=n;i++)
   {
       for(int j=1;j<=n;j++)
       {
           for(int k=1;k<=n;k++)
           {
               dp[j][k]=min(dp[j][k],dp[j][i]+dp[i][k]);
           }
       }
   }
   while(q--)
   {
       int x,y ;
       cin >> x >> y ;
       if(dp[x][y]==imax)
       {
           cout << "-1" << endl ;
       }
       else
       {
           cout << dp[x][y] << endl ;
       }
   }
   return 0 ;
}
