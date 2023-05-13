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
const ll maxx = 1e5+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int main()
{
   debugMode();
      ll x,a,d,n ;
      cin >> x >> a >> d >> n ; 
      if(d==0)
      {
         ll temp = abs(x-a) ;  
         cout << temp << endl ;
         return 0 ; 
      }
      ll ans = 1e18 ; 
      ll k = ((x-a)/d)-100LL ;  

      ll l = k-100 ; 
      ll r = k+100 ; 

      ll p = min(l,r) ; 
      ll q = max(l,r) ; 

      while(p<=q)
      {
         ll temp = a+d*p ;
         ans = min(ans,abs(temp-x)) ;
         p++ ; 
      }

      l = -k-100 ; 
      r = -k+100 ; 

      p = min(l,r) ; 
      q = max(l,r) ;
      
      while(p<=q)
      {
         ll temp = a+d*p ;
         ans = min(ans,abs(temp-x)) ;
         p++ ; 
      }

      cout << ans << endl ;
   return 0 ;
}