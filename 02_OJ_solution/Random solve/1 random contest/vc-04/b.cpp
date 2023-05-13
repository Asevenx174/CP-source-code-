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
const ll maxx = 120000+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int ar[maxx+10] ; 
int main()
{
   debugMode();
   map < ll ,int > f ; 
   map < ll , bool > used,tak ; 
   ll n ;
   cin >> n ; 
   for (int i = 0; i < n ; ++i)
   {
      ll x ;
      cin >> x ; 
      used[x] = true ; 
      ar[i] = x ; 
      f[x]++ ; 
   }
   for (int i = 0; i < n ; ++i)
   {
      ll x = ar[i] ; 
      ll idx = 0 ; 
      while(idx<=30LL)
      {
         ll temp = qq << idx ; 
         if(temp>x)
         {
            ll y = temp-x ; 
            if(!used[y]){idx++;continue;}
            if(x==y && f[x]==qq){idx++;continue;}
            tak[x] = true ; 
            tak[y] = true ; 
         }
         idx++ ; 
      }
   }
   ll ans = 0 ; 
   for (int i = 0; i < n ; ++i)
   {
      if(!tak[ ar[i] ]){ans++;}
   }
   cout << ans << endl ;
   return 0 ;
}