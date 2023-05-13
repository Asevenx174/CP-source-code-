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
const int imin = 1e9+100;
const ll maxx = 1e6+10,mod=998244353,imax=1e18+10;
inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll fastpow(ll n,ll k)
{
    ll ans = 1 ;
    while(k>0)
    {
        if(k&1)
        {
            ans = (ans*n)%mod;
        }
        k = k >> 1 ;
        n = (n*n)%mod;
    }
    return ans ;
}
ll fact[maxx+5],invfact[maxx+5];
ll ncr(ll n,ll r)
{
  if(n<r){return 0 ;}
  if(r==1){return n ;}
  if(n==r){return 1 ; }
  ll x = (ll)(fact[n]*invfact [n-r])%mod;
  return (ll)(x*invfact[r])%mod;
}



ll dpx[maxx],dpy[maxx],kcr[maxx+10]; 
int main()
{
   debugMode() ; 
   fact[0]=1;
   invfact[0]=1;
   for(int i=1;i<=maxx;i++)
   {
       fact[i] = (fact[i-1]*i)%mod ;
       invfact[i] = fastpow(fact[i],mod-2);
   }

   ll h,w,k ;
   cin >> h >> w >> k ; 
   ll x1,x2,y1,y2 ;
   cin >> x1 >> y1 >> x2 >> y2 ; 


   ll f = 0 ; 
   if(x1==x2){f=1;}
   dpx[0]=f ; 
   dpx[1]=!f ; 
   
   f = 0 ; 
   if(y1==y2){f=1;}
   dpy[0]=f ;
   dpy[1]=!f ; 

   for(int i=2;i<=k;i++)
   {
      ll sum = fastpow(h-1,i-1)-dpx[i-1]+mod ;
      dpx[i] = sum%mod ; 

      sum = fastpow(w-1,i-1)-dpy[i-1]+mod ;
      dpy[i] = sum%mod ;
   }

   ll ans = 0 ; 
   for(ll p=0;p<=k;p++)
   {
      ll temp = ncr(k,p) ;

      temp = (temp*dpx[p])%mod ;
      temp = (temp*dpy[k-p])%mod ; 
      ans = (ans+temp)%mod ;  
   }
   cout << ans << endl ; 
}
