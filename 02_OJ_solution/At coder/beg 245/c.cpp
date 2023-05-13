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
ll a[maxx],b[maxx],n,k,dp[maxx][5]; 
int main()
{
   debugMode();
   cin >> n >> k ;
   for (int i = 0; i < n ; ++i)
   {
      cin >> a[i+1] ; 
   }
   for (int i = 0; i < n ; ++i)
   {
      cin >> b[i+1] ; 
   }

   dp[1][1] = 1 ; 
   dp[1][2] = 1 ; 
   for(int i=2;i<=n;i++)
   {
      int p = abs(a[i]-a[i-1]) ; 
      int q = abs(a[i]-b[i-1]) ; 
      
      if( ( p<=k && dp[i-1][1]!=mod ) || ( q<=k && dp[i-1][2]!=mod ) )
      {
          dp[i][1] = 1 ; 
      }
      else
      {
          dp[i][1]=mod ;
      }
      


      p = abs(b[i]-a[i-1]) ; 
      q = abs(b[i]-b[i-1]) ; 
      
      if( ( p<=k && dp[i-1][1]!=mod ) || ( q<=k && dp[i-1][2]!=mod ) )
      {
          dp[i][2] = 1 ; 
      }
      else
      {
          dp[i][2]=mod ;
      }
   }
   int ans = min(dp[n][1],dp[n][2]) ; 
   if(ans==mod)
   {
      cout << "No" << endl ; 
   }
   else
   {
      cout << "Yes" << endl ;
   }
   return 0 ;
}