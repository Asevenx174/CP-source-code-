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
const ll maxx = 1e5+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll ar[50] ; 
ll br[50] ; 
ll calco(ll b,ll p)
{
   ll ans = 1 ; 
   while(p>zz)
   {
      ans = ans*b ; 
      p-- ; 
   }
   return ans ; 
}
int main()
{
   debugMode();
   ll n,bx ;
   cin >> n >> bx ; 
   for (int i = 0; i < n ; ++i)
   {
      cin >> ar[i] ;  
   }
   ll idx = 0 ; 
   ll a = 0 ; 
   while(n--)
   {
      ll add = ar[n]*calco(bx,idx) ; idx++ ; 
      a+=add ; 
   }


   ll m,by ;
   cin >> m >> by ; 
   for (int i = 0; i < m ; ++i)
   {
      cin >> br[i] ;  
   }
   idx = 0 ; 
   ll b = 0 ; 
   while(m--)
   {
      ll add = br[m]*calco(by,idx) ; idx++ ; 
      b+=add ; 
   }
   string ans = "" ; 
   if(a<b)
   { 
      ans = "<" ; 
   }
   else if(a>b)
   {
      ans = ">" ; 
   }
   else
   { 
      ans = "=" ; 
   }
   cout << ans << endl ;
   return 0 ;
}