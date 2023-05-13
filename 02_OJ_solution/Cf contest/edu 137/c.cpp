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
ll ar[maxx+10],n,br[maxx+10] ; 
ll dp[maxx+10][5] ; 
ll calco(ll idx,ll p)
{
   if(dp[idx][p]!=-1){return dp[idx][p];}
   if(idx==0){return 0;}
   ll a=0,b=0 ; 
   if(p==1)
   {
      if(ar[idx])
      {
         a = br[idx]+calco(idx-1,1) ; 
      }
      else
      {
         a = br[idx]+calco(idx-1,0) ; 
      }

   }
   else
   {
      if(ar[idx]==1)
      {
         a = br[idx]+calco(idx-1,0) ; 
         b = calco(idx-1,1) ;  
      }
      else
      {
         b = calco(idx-1,0) ; 
      }
   }
   ll ans = max(a,b) ; 
   return dp[idx][p] = ans ; 
}
int main()
{
   debugMode();
   ll test ;
   cin >> test ;
   while(test--)
   {
      ll n ;
      cin >> n ; 
      string s ;
      cin >> s ;
      for (int i = 0; i < n ; ++i)
      {
         cin >> br[i+1] ; 
         dp[i+1][0] = -1 ; 
         dp[i+1][1] = -1 ; 
      }
      ll idx = 1 ; 
      for(auto c : s )
      {
         ll x = c=='1' ? 1 : 0 ; 
         ar[idx++] = x ; 
      }
      ll ans = calco(n,0) ;
      cout << ans << endl ; 
   }
   return 0 ;
}