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
const ll maxx = 1e5+10,mod=505,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll dp[maxx+10],n,r,xr[maxx+10],yr[maxx+10],tr[maxx+10],pre[maxx+10] ; 
int main()
{
   debugMode(); 
   cin >> r >> n ; 
   xr[0] = 1 ; 
   yr[0] = 1 ; 
   tr[0] = 0 ; 
   for(int i=1;i<=n;i++)
   {
      cin >> tr[i] >> xr[i] >> yr[i] ; 
   }
   ll ans = 0 ; 
   for(ll i=1;i<=n;i++)
   {
      ll l = max(zz,i-2*r+1) ; 
      ll r = i-1 ; 
      ll p = max(zz,l-1) ; 
      ll temp = 0 ; 
      while(l<=r)
      {
         if( (tr[i]-tr[l]) >= ( abs(xr[i]-xr[l])+abs(yr[i]-yr[l]) ) )
         {
            if( !(l>0 && dp[l]==0) )
            {
                temp = max(temp,dp[l]+1) ; 
            }
         }
         l++ ;
      }
      if(p>0)
      {
         temp = max(temp,pre[p]+1) ; 
      }
      dp[i] = temp ; 
      pre[i] = max(pre[i-1],dp[i]) ; 
      ans = max(ans,temp) ; 
   }
   cout << ans << endl ;
   return 0 ;
}