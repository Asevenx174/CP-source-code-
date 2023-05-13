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
const ll maxx = 3010 ,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll ar[maxx+10],n,lr[maxx+10],rr[maxx+10],k ; 
int main()
{
   debugMode();
   cin >> n >> k ; 
   lp(i,1,n)
   {
      cin >> ar[i] ; 
   }
   ar[n+1]=0 ;
   ll ans = 1 ; 
   ll a=mod,b=-mod ; 
   lp(i,1,n+1)
   {
      ll x = ar[i] ; 
      if(x!=0)
      {
         lr[i]=x ; 
         rr[i]=x ; 
      }
      else
      {
         ll l = max(ar[i-1],ar[i+1])-k ; 
         ll r = min(ar[i-1],ar[i+1])+k ; 
         r = min(r,k) ; 
         l = max(l,-k) ; 
         lr[i]=l ; 
         rr[i]=r ; 
      }
      if( lr[i]>rr[i] )
      {
         cout << i << endl ;
         ans = 0 ; break ; 
      }
      a = min(a,lr[i]) ; 
      b = max(b,rr[i]) ; 
   } 
   if(ans==0)
   {
      cout << "-1" << endl ;
   }
   else
   {
      ans = b-a+1 ; 
      cout << ans << endl ;
   }
   return 0 ;
}