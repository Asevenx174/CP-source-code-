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
const ll maxx = 1e5+5,mod=1e9+7,imax=105,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll n,k,ar[imax],dp[imax][maxx],pre[imax][maxx] ; 
int main()
{
   debugMode();
   cin >> n >> k ;
   for (int i = 0; i < n ; ++i)
   {
      cin >> ar[i+1] ; 
   }
   for (int i = 0; i <= n ; ++i)
   {
      pre[0][i] = 1 ; 
   }
   for(ll i=1;i<=n;i++)
   {
      //ll sum = pre[i][0] ; 
      ll sum = 1 ;  
      pre[i-1][0] = 1 ; 
      for(int j=1;j<=k;j++)
      {
         // ar[2] = 3 ; 
         // dp[2][4] = dp[1][4]+dp[1][3]+dp[1][2]+dp[1][1] ; 
         // pre[1][4] = dp[1][4]+dp[1][3]+dp[1][2]+dp[1][1]+dp[1][0] 
         ll r = j ; 
         ll l = j-ar[i] ; 
         ll temp = pre[i-1][r] ; 
         if(l>0)
         {
            temp = (temp-pre[i-1][l-1])%mod ; 
         } 
         if(i==2 && j==4)
         {
            cout << temp << " " << pre[i-1][r]  << " " << pre[i-1][l-1]  << endl ;
         }
         dp[i][j] = temp ; 
         //pre[i][j] = (pre[i][j-1]+dp[i][j])%mod ; 
         sum = (sum+temp)%mod ; 
         pre[i][j] = sum ; 
      }
   }
   cout << dp[2][4] << endl ; 
   //cout << dp[1][3] << " " << dp[1][2] <<  " " <<  dp[1][1] << endl ;
   //cout << pre[1][3] << endl ;
   return 0 ;
}