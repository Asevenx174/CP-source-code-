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
const ll maxx = 1e5+10,mod=1e9+7,imax=1e18+10,mod1=1e9+6;
ll fastpow(ll n,ll k,ll p )
{
    ll ans=1,q=1;
    while(k>0)
    {
        if(k&q)
        {
            ans = (ans*n)%p;
        }
        k = k >> q ;
        n = (n*n)%p;
    }
    return ans ;
}
ll p[maxx],k[maxx];
int main()
{
   ll n,sum=1,num=1,div=1 ;
   cin >> n ;
   for(int i=1;i<=n;i++)
   {
       cin >> p[i] >> k[i] ;
       ll a = (fastpow(p[i],k[i]+1,mod)+mod1)%mod ;
       ll b = fastpow(p[i]-1,mod-2,mod);
       ll kk = (a*b)%mod ;
       sum = (sum*kk)%mod ;
       div = (div*(k[i]+1))%mod ;
   }
   ll pp = 1 ,f =0  ;
   for(int i=1;i<=n;i++)
   {
       if(k[i]%2==1 && f==0)
       {
           f = 1 ;
           pp = (pp*( (k[i]+1)>>1LL ))%mod1 ;
       }
       else
       {
           pp = (pp*(k[i]+1))%mod1 ;
       }
   }
   if(f==0)
   {
       for(int i=1;i<=n;i++)
       {
           k[i]= (k[i]>>1LL) ;
       }
   }
   ll num1 = 1 ;
   for(int i=1;i<=n;i++)
   {
       num1 = (num1*fastpow(p[i],k[i],mod))%mod ;
   }
   ll pro = fastpow(num1,pp,mod);
   cout << div << " " << sum << " " << pro << endl;
   return 0 ;
}
