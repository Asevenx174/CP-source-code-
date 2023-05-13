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
typedef unsigned long long ll ;
const int imin = 1e9+100;
const ll maxx = 1e5+10,mod=1e9+7,imax=1e18+10;
ll p[25];
int main()
{
   ll n,k,ans=0 ;
   cin >> n >> k ;
   for(int i=1;i<=k;i++)
   {
       cin >> p[i] ;
   }
   for(ll i=1;i<(1<<k);i++)
   {

       vector < ll > v ;
       ll x = i ;
       ll idx = 1 ;
       while( (1<<(idx-1))<=x )
       {
           if(x&(1<<(idx-1)))
           {
               v.push_back(p[idx]);
           }
           idx++;
       }

       ll sum = 1 ;
       for(auto x : v )
       {
           if(sum>(n/x))
           {
               sum = n+1 ;
               break;
           }
           sum = sum*x ;
       }
       if(v.size()%2==1)
       {
           ans+=(n/sum) ;
       }
       else
       {
           ans-=(n/sum) ;
       }
   }
   cout << ans << endl;
   return 0 ;
}
