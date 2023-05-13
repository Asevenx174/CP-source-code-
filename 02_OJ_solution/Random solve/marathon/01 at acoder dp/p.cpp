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
ll n,h[maxx],a[maxx],dp[maxx] ; 
int main()
{
   debugMode();
   cin >> n ; 
   for (int i = 0; i < n ; ++i)
   {
      cin >> h[i+1] ; 
   }
   for (int i = 0; i < n ; ++i)
   {
      cin >> a[i+1] ; 
   }
   set < pii > s ;
   ll ans = 0 ; 
   for(int i=1;i<=n;i++)
   {
      ll x = h[i] ; 
      auto it = s.upper_bound({x,mod}) ;
      if(it==s.begin() || s.empty() )
      {
         dp[i] = a[i] ; 
      }
      else
      {  
         it-- ; 
         pii p = *it ; 
         ll last = p.ss ; 
         cout << i << " -> " << endl ;
         while(1)
         {
            it = s.begin() ; 
            p = *it ; 
            ll idx = p.ss ; 
            cout << idx << endl ;
            dp[i] = max(dp[i],dp[idx]) ; 
            //s.erase(it) ; 
            if(s.empty() || idx==last ){break;}
         }
         dp[i]+=a[i] ; 
      }
      s.insert({x,i}) ; 
      ans = max(ans,dp[i]) ; 
   }
   cout << ans << endl ;
   return 0 ;
}