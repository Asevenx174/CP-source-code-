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
ll sett(ll idx,ll mask )
{
   mask = mask | (qq << (idx-qq)) ; 
   return mask ; 
}
bool check(ll idx,ll mask )
{
   if( (mask&(qq<<(idx-qq))) == zz )
   {
      return false ; 
   }
   return true ; 
}
ll n,q,fr[60][maxx],f[60],ar[maxx+10] ; 
int main()
{
   debugMode();
   ll test ;
   cin >> test ;
   while(test--)
   {
      
      cin >> n >> q ;
      for(int i=0;i<35;i++)
      {
         f[i] = 0  ;
         for(int j=0;j<=n+5;j++)
         {
            fr[i][j] = 0 ; 
         }
      }
      for (int i = 0; i < n ; ++i)
      {
         cin >> ar[i+1] ; 
      }
      ll l,r ;
      cin >> l >> r ; 
      for(int i=l;i<=r;i++)
      {
         ll x ;
         cin >> x ;
         for(int j=1;j<=30;j++)
         {
            if(check(j,x))
            {
               f[j]++ ; 
               fr[j][ f[j] ] = i ; 
            }
         }
      }
      ll a = r ; 
      ll b = l ; 
      ll c = mod ; 
      ll d = -mod ; 
      for(int i=1;i<=30;i++)
      {
         ll x = f[i] ; 
         if(f[i]<2LL){continue;}
         ll p = fr[i][1] ; 
         ll q = fr[i][ f[i] ] ; 
         if(x%2LL==zz)
         {
            c = min(c,p) ; 
            d = max(d,q) ; 
            continue;
         }
         p = fr[i][2] ; 
         q = fr[i][ f[i]-1 ] ; 
         if(p>q){continue;}
         a = min(a,p) ; 
         b = max(b,q) ;  
      }
      a = min(a,c) ; 
      b = max(b,d) ; 
      cout << a << " " << b << endl ;
   }
   return 0 ;
}