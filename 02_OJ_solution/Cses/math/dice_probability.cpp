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
typedef long double ld ;
const int imin = 1e9+100;
const ll maxx = 110 ,mod=1e9+7,imax=1e18+10;
ld dp[maxx][maxx*6];
int main()
{
   ll n,a,b ;
   cin >> n >> a >> b ;
   dp[0][0]=1.0;
   for(int i=1;i<=n;i++)
   {
       for(int j=i;j<=(i*6);j++)
       {
           for(int k=1;k<=6;k++)
           {
               if(j-k<0){continue;}
               dp[i][j]+=dp[i-1][j-k];
           }
           dp[i][j] = (ld)dp[i][j]/6.0 ;
       }
   }
   ld sum = 0.0;
   for(int i=a;i<=b;i++)
   {
       sum+=(dp[n][i]);
   }
   printf("%.6Lf\n",sum);
   return 0 ;
}
